#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

#include <QDebug>
#include <QPixmap>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QIODevice>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include "ithyroidwrapper.h"

uvc_device_handle_t *devh;
uvc_context_t *ctx;
uvc_device_t *dev;

// call back function//
void cb(uvc_frame_t *frame, void *ptr)
{
  uvc_frame_t *bgr;
  uvc_error_t ret;
  /* We'll convert the image from YUV/JPEG to BGR, so allocate space */
  bgr = uvc_allocate_frame(frame->width * frame->height * 3);
  if (!bgr) {
    printf("unable to allocate bgr frame!");
    return;
  }
  /* Do the BGR conversion */
  ret = uvc_any2bgr(frame, bgr);
  if (ret) {
    uvc_perror(ret, "uvc_any2bgr");
    uvc_free_frame(bgr);
    return;
  }
  /*Call a user function:*/
   MainWindow *my_obj = (MainWindow *) ptr;
   my_obj->loadImage(bgr);

  uvc_free_frame(bgr);
}

// 初始化 //
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    setupUI();
    Mat img = imread("shield.jpeg");
    showImage(img);
    readROIfile();

    mThread = new MyThread(this);

    IThyroidWrapper* wrapper = CreateWrapper();
    mThread->SetWrapper(wrapper);
    mThread->start();
    qRegisterMetaType<Mat>("Mat");
    qRegisterMetaType<vector<vector<cv::Point> >>("vector<vector<cv::Point> >&");
    qRegisterMetaType<vector<double>>("vector<double>&");

    connect(this,&MainWindow::sendImage,mThread,&MyThread::receiveImage);
    connect(mThread,&MyThread::analyzeDone,this,&MainWindow::showContours);

    videoInput = true;
    findVideo = false;
    index =  0;

    //setupVideo();
}

// BGR 转 Mat ，从采集卡得到图像并调用loadImage()显示Mat //
void MainWindow::loadImage(uvc_frame_t *bgr_temp)
{
    cvImg = cvCreateImageHeader(cvSize(bgr_temp->width, bgr_temp->height), IPL_DEPTH_8U,3);
    cvSetData(cvImg, bgr_temp->data, bgr_temp->width * 3);
    Img = cv::cvarrToMat(cvImg,true);  //Img 是最原始的全屏原图
    cvtColor(Img,Imggray,COLOR_BGR2GRAY,CV_8UC1); //Imggray是传进算法的单通道灰度图

    temp_Img = Img.clone();   // temp_Imageshow是显示rectangle的图

    if(showRec.width>0)
    {
      rectangle(temp_Img,showRec,Scalar(0,255,0));
      showImage(temp_Img);
    }
    else if(ROIRec.width>0)
    {
       // rectangle(temp_Img,ROIRec,Scalar(0,255,0));
        ROI = Mat(Imggray,ROIRec);

       emit sendImage(ROI);

    }
    else
    {
        showImage(temp_Img);
    }
    cvReleaseImageHeader(&cvImg);
}

void MainWindow::loadMatImg(int index)
{
    Mat image = vecImg[index].clone();
    Img = image.clone();
    if(Img.channels()==1)
    {
        Imggray = Img.clone();
    }
    else
    {
        cvtColor(Img,Imggray,COLOR_BGR2GRAY,CV_8UC1); //Imggray是传进算法的单通道灰度图
    }
    temp_Img = Img.clone();   // temp_Imageshow是显示rectangle的图

    if(showRec.width>0)
    {
      rectangle(temp_Img,showRec,Scalar(0,255,0));
      showImage(temp_Img);
    }
    else if(ROIRec.width>0 && ROIRec.width<temp_Img.cols && ROIRec.height<temp_Img.rows)
    {

        ROI = Mat(Imggray,ROIRec);

      emit sendImage(ROI);

    }
    else if(ROIRec.width>0 && (ROIRec.width>temp_Img.cols || ROIRec.height>temp_Img.rows))
    {
       on_undopushButton_clicked();
       QMessageBox::warning(this,"waring","The ROI size is bigger than image size ,please plot again");
    }
    else
    {
        showImage(temp_Img);
    }
}

MainWindow::~MainWindow()
{

    delete ui;
}

//  设置UI //
void MainWindow::setupUI()
{
    label = new ShowLabel(ui->widget);
    label->setAlignment(Qt::AlignCenter);
    label->setScaledContents(true); //注释掉不报错

    this->grabKeyboard(); //all keyboard

    label_layout = new QGridLayout;
    label_layout->addWidget(label);
    label_layout->setContentsMargins(0,0,0,0);
    ui->widget->setLayout(label_layout);

    //this->setWindowFlags(Qt::FramelessWindowHint);
    //this->showFullScreen();
    this->setStyleSheet("background-color:black;");
    //ui->dockWidget->setTitleBarWidget(new QWidget()); 
    ui->dockWidget->setStyleSheet("background-color:black;");
    ui->dockWidget_2->setStyleSheet("background-color:black;");
    QDesktopWidget *desktop = QApplication::desktop();
    ui->dockWidget->setFixedWidth(desktop->width()/8);
    ui->dockWidget_2->setFixedWidth(ui->dockWidget->width());

    ui->setpushButton->setEnabled(false);
    ui->undopushButton->setEnabled(false);
}

// 将Mat显示在label中 //
void MainWindow::showImage(Mat& img)
{
    if(!img.empty())
    {
       // QImage imageshow = Mat2QImage(img);
        Mat temp(img.cols,img.rows,img.type());
        cvtColor(img,temp,CV_BGR2RGB);       //temp 是原图
        imageshow = QImage((uchar*)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
        if(!imageshow.isNull())
        {
           label->setFixedSize(imageshow.width(),imageshow.height());
           label->setPixmap(QPixmap::fromImage(imageshow).scaled(label->size(),Qt::KeepAspectRatio,Qt::FastTransformation));
        }

    }
    else
    {
       // QMessageBox::warning(this,"warning","Image not vaild!");
    }
}

void MainWindow::showContours(vector<vector<Point>> &contours2, vector<double> &scores2)
{
    //save to global contours and scores
    contours.swap(contours2);
    scores.swap(scores2);
   // how to drawcontours,true for using QPaint ,false for using Opencv to paint contours;
    bool useQPaint = true;
    if(!useQPaint)
    {
        for(int i=0;i<contours.size();i++)
        {
            Scalar color = Scalar(0,255,0);
            QString text = QString::number(scores[i]);
            drawContours(temp_Img,contours,i,color,1,8,noArray(),0x7fffffff,cv::Point(ROIRec.x,ROIRec.y));
            putText(temp_Img,text.toStdString(),(contours[i][0]+cv::Point(ROIRec.x,ROIRec.y)),FONT_HERSHEY_PLAIN,2,color);
        }
        showImage(temp_Img);
    }
    else
    {
        Mat temp(temp_Img.cols,temp_Img.rows,temp_Img.type());
        cvtColor(temp_Img,temp,CV_BGR2RGB);       //temp 是原图
        imageQpaint = QImage((uchar*)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);

        QPainter p(&imageQpaint);
        QPen pen;
        pen.setColor(Qt::green);
        pen.setJoinStyle(Qt::RoundJoin);
        p.setPen(pen);
        p.setRenderHints(QPainter::Antialiasing,true); //抗锯齿
        //paint contours
        for(int i = 0;i<contours.size();i++)
        {
            QPolygonF polygen;
            for(int j=0;j<contours[i].size();j++)
                polygen<<QPointF(QPoint(contours[i][j].x+ROIRec.x,contours[i][j].y+ROIRec.y));

            p.drawPolygon(polygen);
        }
        //paint scores
        for(int i=0;i<scores.size();i++)
        {
            QString text(QString::number(scores[i]));
            p.drawText(QPointF(contours[i][0].x+ROIRec.x,contours[i][0].y+ROIRec.y),text);
        }
        imageQpaintScaled = imageQpaint.scaledToWidth(this->width(),Qt::FastTransformation);
        label->setPixmap(QPixmap::fromImage(imageQpaintScaled));
    }

}

//  初始化流,每一帧都会调用回调函数 //
int MainWindow::setupVideo()
{
    uvc_stream_ctrl_t ctrl;
    uvc_error_t res;
    /* Initialize a UVC service context. Libuvc will set up its own libusb
     * context. Replace NULL with a libusb_context pointer to run libuvc
     * from an existing libusb context. */
    res = uvc_init(&ctx, NULL);
    if (res < 0)
    {
      uvc_perror(res, "uvc_init");
      return res;
    }
    puts("UVC initialized");
    /* Locates the first attached UVC device, stores in dev */
    res = uvc_find_device(ctx, &dev, 0, 0, NULL); /* filter devices: vendor_id, product_id, "serial_num" */
    if (res < 0)
    {
      uvc_perror(res, "uvc_find_device"); /* no devices found */
      findVideo = false;
    } else
    {
      puts("Device found");
      findVideo = true;
      /* Try to open the device: requires exclusive access */
      res = uvc_open(dev, &devh);
      if (res < 0)
      {
        uvc_perror(res, "uvc_open"); /* unable to open device */
      }
      else
      {
        puts("Device opened");
        /* Print out a message containing all the information that libuvc knows about the device */
        uvc_print_diag(devh, stderr);
        /* Try to negotiate a 640x480 30 fps YUYV stream profile */
        res = uvc_get_stream_ctrl_format_size(
            devh, &ctrl, /* result stored in ctrl */
            UVC_FRAME_FORMAT_YUYV, /* YUV 422, aka YUV 4:2:2. try _COMPRESSED */
            1280, 1024, 25 /* width, height, fps */ /*640,480,30;1280, 1024, 60;1600,1200,30*/
        );
        /* Print out the result */
        uvc_print_stream_ctrl(&ctrl, stderr);
        if (res < 0)
        {
          uvc_perror(res, "get_mode"); /* device doesn't provide a matching stream */
        } else
        {

          res = uvc_start_streaming(devh, &ctrl, cb, (void*)(this) , 0);

          if (res < 0)
            uvc_perror(res, "start_streaming"); /* unable to start stream */
          else
            puts("Streaming,able to streaming...");

        }
      }
      /* Release the device descriptor */

    }
    return 0;
}

int MainWindow::readROIfile()
{
    QFile file("/root/Desktop/ROI.text");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this,"warning","NO ROI region set,please set again!");
        return 1;
    }
    QTextStream stream(&file);
    QString line_in;
    int index;
    bool ok;
    stream.seek(0);
    while(!stream.atEnd())
    {
        line_in = stream.readLine();
        qDebug()<<line_in<<endl;
        if(line_in.contains("x"))
        {
           index = line_in.indexOf(":");
           ROIRec.x = line_in.right(line_in.length()-index-1).toInt(&ok,10);
           qDebug()<<"ROI x = "<<ROIRec.x<<endl;
        }
        else if(line_in.contains("y"))
        {
           index = line_in.indexOf(":");
           ROIRec.y = line_in.right(line_in.length()-index-1).toInt(&ok,10);
           qDebug()<<"ROI y = "<<ROIRec.y<<endl;
        }
        else if(line_in.contains("w"))
        {
           index = line_in.indexOf(":");
           ROIRec.width = line_in.right(line_in.length()-index-1).toInt(&ok,10);
           qDebug()<<"ROI width = "<<ROIRec.width<<endl;
        }
        else if(line_in.contains("h"))
        {
           index = line_in.indexOf(":");
           ROIRec.height = line_in.right(line_in.length()-index-1).toInt(&ok,10);
           qDebug()<<"ROI height = "<<ROIRec.height<<endl;
        }
    }
    file.close();
}

int MainWindow::writeROIfile()
{
    QFile file("/root/Desktop/ROI.text");
    if(file.exists())
        file.remove();
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this,"warning","NO ROI file can be written ,please check again");
        return 1;
    }
    QTextStream stream(&file);

    stream.seek(0);

    stream<<"Here is the ROI rectangle to be analyzed"<<endl;
    stream<<"x:"<<ROIRec.x<<endl;
    stream<<"y:"<<ROIRec.y<<endl;
    stream<<"width:"<<ROIRec.width<<endl;
    stream<<"height:"<<ROIRec.height<<endl;

    file.close();
}

void MainWindow::on_quitPushbutton_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("warning");
    msgBox.setText("Are you sure to quit?");
    msgBox.setStandardButtons(QMessageBox::Yes
                              | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Yes:
        if(findVideo)
        {
            uvc_stop_streaming(devh);
            uvc_close(devh);
            uvc_unref_device(dev);
            uvc_exit(ctx);
            puts("Stop Screaming!");
        }

        mThread->terminate();
        mThread->wait();
        puts("Stop Thread!");
        this->close();
        break;
    case QMessageBox::Cancel:
        qDebug() << "Discard changes!";
        break;
    }
}


void MainWindow::on_drawpushButton_clicked()
{
    label->Recflag = true;

    ui->setpushButton->setEnabled(true);
    ui->undopushButton->setEnabled(true);

    connect(label,&ShowLabel::sendRect,this,&MainWindow::receiveRect);
}

void MainWindow::receiveRect(cv::Rect rect)
{
    showRec = rect;
    std::cout<<"showRec.x="<<showRec.x<<endl;
    if(!videoInput)
    {
        Mat temp_Img_2 = Img.clone();
        rectangle(temp_Img_2,showRec,Scalar(0,255,0));
        showImage(temp_Img_2);
    }
}

void MainWindow::on_setpushButton_clicked()
{
    label->Recflag = false;

    ROIRec = showRec;
    showRec.x = 0;
    showRec.y = 0;
    showRec.width = 0;
    showRec.height = 0;

    disconnect(label,&ShowLabel::sendRect,this,&MainWindow::receiveRect);
    if(!videoInput)
    {
        ROI = Mat(Imggray,ROIRec);
        emit sendImage(ROI);
    }

    writeROIfile();
}

void MainWindow::on_undopushButton_clicked()
{
    label->Recflag = true;

    showRec.x = 0;
    showRec.y = 0;
    showRec.width = 0;
    showRec.height = 0;
    ROIRec = showRec;

    connect(label,&ShowLabel::sendRect,this,&MainWindow::receiveRect);

    if(!videoInput)
    {
        showImage(Img);
    }
}

void MainWindow::on_sourcepushButton_clicked()
{
    if(videoInput)
    {
        //change to Image input
        QString foldername = QFileDialog::getExistingDirectory(this,tr("Open Folder"),QString());
        if(!foldername.isEmpty())
        {
            QDir dir(foldername);
            vecImg.clear();
            foreach (QFileInfo imageFileInfo, dir.entryInfoList(QStringList()<<"*.jpg"<<"*.png"<<"*.bmp"<<"*.jpeg",QDir::Files,QDir::NoSort))
            {
                QString imgName = imageFileInfo.absoluteFilePath();
                Mat img = imread(imgName.toStdString());
                vecImg.push_back(img);
            }
        }
        if(vecImg.size()>0)
            loadMatImg(0);
        else
            QMessageBox::warning(this,"warning","There is no image in the folder");

        if(findVideo)
        {
            uvc_stop_streaming(devh);
            uvc_close(devh);
            uvc_unref_device(dev);
            uvc_exit(ctx);
            puts("Stop Screaming!");
        }
        videoInput = false;
    }
    else
    {
        //change to video input
        setupVideo();
        videoInput = true;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!videoInput)
    {
        if(vecImg.size()>0)
        {
            if(event->key()==Qt::Key_Up)
            {
                index = ((index==vecImg.size()-1)?0:index+1);
                loadMatImg(index);
            }

            if(event->key()==Qt::Key_Down)
            {
                index = ((index==0)?(vecImg.size()-1):(index-1));
                loadMatImg(index);
            }
        }
    }
}
