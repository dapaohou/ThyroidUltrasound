#include "testwrapper.h"
#include <QDebug>
testwrapper::testwrapper() : IThyroidWrapper()
{
    w = 0;
    h = 0;
}
  bool testwrapper::IsInitilize(int width, int height)
  {
      return (w != width) || (h!=height);
  }

void testwrapper::Initilize(int width, int height)
{
   if (width > 0)
    w = width;
   if (height >0)
    h = height;
}

void testwrapper::Execute(char *img, int width, int height,std::vector<std::vector<Point2i2333> > &contours, std::vector<double> &scores)
{

    contours.clear();
    scores.clear();

    cv::Mat testImg = cv::Mat(height,width,CV_8UC1,img);
    cv::Mat Masktest = cv::imread("test.jpeg",0);

    std::vector<std::vector<cv::Point>> cvContours;

    if(!Masktest.empty())
    {
        cv:threshold(Masktest,Masktest,120,255,cv::THRESH_BINARY);
        cv::findContours(Masktest,cvContours,1,CV_CHAIN_APPROX_SIMPLE);
        for(int i=0;i<cvContours.size();i++)
        {
            std::vector<Point2i2333> contour;
            for (int n = 0; n < cvContours[i].size(); ++n)
            {
                Point2i2333 tempPoint(cvContours[i][n].x,cvContours[i][n].y);
                contour.push_back(tempPoint);
            }
            contours.push_back(contour);
            scores.push_back(0.38483283);
        }
    }
    else
    {
        qDebug()<<"load mask error"<<endl;
    }
}

IThyroidWrapper*  CreateWrapper()
{
    return new testwrapper();
}


void  ReleaseWrapper(IThyroidWrapper** wrapper)
{
    if(*wrapper!=NULL)
    {
        delete dynamic_cast<testwrapper*> (*wrapper);
        *wrapper = NULL;
    }
}
