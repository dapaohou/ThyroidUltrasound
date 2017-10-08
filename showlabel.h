#ifndef SHOWLABEL_H
#define SHOWLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QApplication>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


class ShowLabel : public QLabel
{
    Q_OBJECT
signals:
    void sendRect(cv::Rect rect);
public:
    ShowLabel(QWidget *parent);
    ~ShowLabel();

    void mousePressEvent(QMouseEvent *eve);

    void mouseMoveEvent(QMouseEvent *eve);

    void mouseReleaseEvent(QMouseEvent *eve);

    void operPoint(QMouseEvent *eve);

    cv::Rect cut_rect;

    QPoint m_startPos;



    bool Recflag; //true for ready to drawRect
    bool Paintflag;//true for ready to paint contours
    double xoffset;
    double yoffset;
private:


};

#endif // SHOWLABEL_H
