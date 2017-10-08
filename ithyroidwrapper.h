#ifndef ITHYROIDWRAPPER_H
#define ITHYROIDWRAPPER_H

#include <iostream>
#include <vector>
#ifdef win32
    #ifdef EXPORT
        #define WRAPPERDLL __declspec (dllexport)
        #else
        #define WRAPPERDLL __declspec (dllimport)
    #endif
#else
#define WRAPPERDLL
#endif



struct  WRAPPERDLL Point2i2333
{
    int m_x;
    int m_y;
    Point2i2333(int x, int y) : m_x(x), m_y(y)
    {
    }
    Point2i2333() : m_x(0), m_y(0)
    {
    }
};

class WRAPPERDLL IThyroidWrapper
{
public:
    IThyroidWrapper() {}
    virtual ~IThyroidWrapper() {}
    virtual bool IsInitilize(int width,int height) = 0;
    virtual void Initilize(int width,int height) = 0;

    virtual void Execute(char* img, int width, int heigth,
                          std::vector<std::vector<Point2i2333>> &contours,
                         std::vector<double> &scores) = 0;
};

extern "C" WRAPPERDLL IThyroidWrapper*  CreateWrapper();

extern "C" WRAPPERDLL  void  ReleaseWrapper(IThyroidWrapper** wrapper);

#endif // ITHYROIDWRAPPER_H
