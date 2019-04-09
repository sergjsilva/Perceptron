#pragma once
#include<vector>

namespace cg
{
    float myfx(float x);
    void Line(float x1,float y1, float x2, float y2,float cor[3]);
    void plotFunc(float xmin_, float xmax_);
}

namespace vetor
{
    std::vector<float> soma(std::vector<float> u, std::vector<float> v);
     std::vector<float> subtract(std::vector<float> u, std::vector<float> v);
}


class Point
{
    public:
        float x,y;
        int label;
        Point(float xmin, float xmax, float ymin, float ymax);
        Point(float x_, float y_);
        ~Point();
        void show();

    private:
        float randomFloat(float a, float b);

};




