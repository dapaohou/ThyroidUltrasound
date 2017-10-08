#include "showlabel.h"
#include <iostream>
ShowLabel::ShowLabel(QWidget *parent)
        :QLabel(parent)
{
    cut_rect.x = 0;
    cut_rect.y = 0;
    cut_rect.width = 0;
    cut_rect.height = 0;
    Paintflag = false;
}

ShowLabel::~ShowLabel()
{

}

void ShowLabel::mousePressEvent(QMouseEvent *eve)
{
    if(Recflag)
    {
        xoffset = (this->contentsRect().width()-this->pixmap()->rect().width())/2;
        yoffset = (this->contentsRect().height()-this->pixmap()->rect().height())/2;
        std::cout<<"the xoffset is "<<xoffset<<"the yoffset is "<<yoffset<<std::endl;

        m_startPos = eve->pos();
        cut_rect.x = m_startPos.x();
        cut_rect.y = m_startPos.y();
        std::cout<<"the startx is "<<m_startPos.x()<<"the starty is "<<m_startPos.y()<<std::endl;
    }
}

void ShowLabel::mouseMoveEvent(QMouseEvent *eve)
{
    if(Recflag)
    {
        if(eve->button()==Qt::LeftButton)
        {
//            operPoint(eve);
//            emit sendRect(cut_rect);
        }
    }
}

void ShowLabel::mouseReleaseEvent(QMouseEvent *eve)
{
    if(Recflag && eve->button()==Qt::LeftButton)
    {
        operPoint(eve);
        emit sendRect(cut_rect);
    }
    else
    {
        cut_rect.x = 0;
        cut_rect.y = 0;
        cut_rect.width = 0;
        cut_rect.height = 0;
    }
}

void ShowLabel::operPoint(QMouseEvent *eve)
{
   QPoint tmpPoint = eve->pos();

   int tmpx, tmpy;
       if (tmpPoint.x() < 0) { tmpx = 0; }
       else if (tmpPoint.x() > this->width()) { tmpx = this->width(); }
       else { tmpx = tmpPoint.x(); }

       if (tmpPoint.y() < 0) { tmpy = 0; }
       else if (tmpPoint.y() > this->height()) { tmpy = this->height(); }
       else { tmpy = tmpPoint.y(); }

       int x, y, w, h;
       if (m_startPos.x() < tmpx)
       {
           x = m_startPos.x();
           w = tmpx - m_startPos.x();
       }
       else
       {
           x = tmpx;
           w = m_startPos.x() - tmpx;
       }

       if (m_startPos.y() < tmpy)
       {
           y = m_startPos.y();
           h = tmpy - m_startPos.y();
       }
       else
       {
           y = tmpy;
           h = m_startPos.y() - tmpy;
       }

       cut_rect.x = x-xoffset-6;
       cut_rect.y = y-yoffset;
       cut_rect.width = w;
       cut_rect.height = h;
       if(cut_rect.width<20)
       {
           cut_rect.width = 0;
           cut_rect.height = 0;
       }
       std::cout << "x: " <<  cut_rect.x << "y:" <<  cut_rect.y << "with:" <<  cut_rect.width << "height:" <<  cut_rect.height << std::endl;
}


