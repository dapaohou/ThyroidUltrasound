#ifndef TESTWRAPPER_H
#define TESTWRAPPER_H
#include "ithyroidwrapper.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class testwrapper : public IThyroidWrapper
{
public:
    testwrapper();
    void Initilize(int width,int height);
    void Execute(char *img, int width, int heigth,  std::vector<std::vector<Point2i2333>>& contours,std::vector<double> &scores);
    bool IsInitilize(int width, int height);
private:
    int w;
    int h;
};

#endif // TESTWRAPPER_H
