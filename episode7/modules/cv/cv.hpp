#ifndef __CV_HPP__
#define __CV_HPP__

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <sstream>

namespace CMAKE_TUTORIAL
{

    class CV
    {
    public:
        CV();
        ~CV() = default;
        CV(CV const &) = delete;
        CV &operator=(CV const &) = delete;

    public:
        int getselect()
        {
            return this->rec_select;
        }
        int hmin()
        {
            return this->H_min;
        }
        int hmax()
        {
            return this->H_max;
        }
        int smin()
        {
            return this->s_min;
        }
        int smax()
        {
            return this->s_max;
        }
        int vmin()
        {
            return this->v_min;
        }
        int vmax()
        {
            return this->v_max;
        }




    private:
        int rec_select;
        int H_min;
        int H_max;
        int s_min;
        int s_max;
        int v_min;
        int v_max;
    };

}

#endif