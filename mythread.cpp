#include "mythread.h"
#include <QtCore>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
    m_wrapper = NULL;
    m_start = false;
}
MyThread::~MyThread()
{
    requestInterruption();
    quit();
    wait();
}
 void MyThread::SetWrapper(IThyroidWrapper* wrapper)
 {
    delete m_wrapper;
    m_wrapper = wrapper;
 }

void MyThread::run()
{
    while(1)
    {
        if (m_start)
        {
           //   std::cout << "m_start ";
            if(m_wrapper->IsInitilize(ROI.cols,ROI.rows))
            {
                m_wrapper->Initilize(ROI.cols,ROI.rows);
            }

            std::vector<std::vector<Point2i2333>> contours;
            std::vector<double> scores;
            std::vector<std::vector<cv::Point>> cvContours;
            uchar* charImg = new uchar[ROI.rows*ROI.cols];

            for(int i = 0;i<ROI.rows;i++)
            {
                for(int j=0;j<ROI.cols;j++)

                    charImg[i*ROI.cols+j] = ROI.ptr<uchar>(i)[j];
            }
         //   cv::imwrite("roi.bmp",ROI);

            m_wrapper->Execute((char *)charImg,ROI.cols,ROI.rows,contours,scores);

            delete []charImg;
        //     std::cout << "Execute";
            for(int i=0;i<contours.size();i++)
            {
                std::vector<cv::Point> contour;
                for (int n = 0; n < contours[i].size(); ++n)
                {
                    cv::Point tempPoint(contours[i][n].m_x,contours[i][n].m_y);
                    contour.push_back(tempPoint);
                }
                cvContours.push_back(contour);
            }
             emit analyzeDone(cvContours,scores);
            m_start = false;
        }
        else
        {
            usleep(100);
        }
    }


        //wrapper = new testwrapper;



}

void MyThread::receiveImage(Mat mat)
{

     ROI = mat.clone();
      m_start = true;
    //  std::cout << "receiveImage";
}
