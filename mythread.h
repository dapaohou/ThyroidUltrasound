#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <ithyroidwrapper.h>

using namespace std;
using namespace cv;


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    ~MyThread();
    void run();
    bool Stop;
    cv::Mat ROI; //接受主线程的Mat,以传给算法

    void SetWrapper(IThyroidWrapper* wrapper);
private:
    bool m_start;
    IThyroidWrapper*  m_wrapper;
    vector<vector<cv::Point>> contours2;//自定义的Point2i转换成oepncv 的Point，否则信号和槽的参数类型不匹配
signals:
    void analyzeDone(vector<vector<cv::Point>>&,vector<double>&);
public slots:
    void receiveImage(Mat mats);
};

#endif // MYTHREAD_H
