#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "showlabel.h"
#include <QMainWindow>
#include "opencv/cv.h"
#include <opencv2/core.hpp>
#include "opencv/highgui.h"
#include <opencv2/imgproc.hpp>
#include <QImage>
#include <QGridLayout>
#include "libuvc/libuvc.h"
#include <QtGui>

#include <mythread.h>
#include <testwrapper.h>

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

void cb(uvc_frame_t *frame, void *ptr);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showImage(Mat& img);
    void loadImage(uvc_frame_t *bgr_temp);
    void loadMatImg(int index);
    QImage Mat2QImage(cv::Mat const& mat);
    void setupUI();
    int setupVideo();
    int readROIfile();
    int writeROIfile();
    ShowLabel* label;
    QGridLayout* label_layout;

    IplImage* cvImg;
    Mat Img;
    Mat Imggray;
    Mat temp_Img;
    Mat ROI;
    Mat Masktest;
    QImage imageshow;
    QImage imageQpaint;
    QImage imageQpaintScaled;
    Rect ROIRec;
    Rect showRec;
    bool videoInput; //1 for video ,0 for image;
    bool findVideo;

    vector<vector<Point>> contours;
    vector<double> scores;
    vector<Mat> vecImg;  //save images for test
    int index; //index of test images

    MyThread *mThread;

private slots:
    void on_quitPushbutton_clicked();
    void on_drawpushButton_clicked();
    void receiveRect(cv::Rect rect);
    void on_setpushButton_clicked();
    void on_undopushButton_clicked();
    void on_sourcepushButton_clicked();
    void keyPressEvent(QKeyEvent *event);
signals:
    void sendImage(Mat);
public slots:
    void showContours(vector<vector<Point>>& contours2,vector<double> &scores2);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
