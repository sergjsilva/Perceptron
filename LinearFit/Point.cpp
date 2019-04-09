#include "Point.h"
#include <cstdlib>
#include<GL/freeglut.h>
#include<iostream>

float cg::myfx(float x)
{
    //return -x+500;
    //return x;
    return -5*x+5;
}


void cg::Line(float x1,float y1, float x2, float y2,float cor[3])
{
    glColor3fv(cor);
    glLineWidth(3.0);
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
}

void cg::plotFunc(float xmin_, float xmax_)
{
    float cor[]={1,0,0};
    Line(xmin_,myfx(xmin_),xmax_,myfx(xmax_),cor);

}

std::vector<float> vetor::soma(std::vector<float> u, std::vector<float> v)
{
    if(u.size()!=v.size())
    {
        std::cout<<"Error in SOMA procedure! Vectors are from different size."<<std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        std::vector<float> result(u.size(),0);
        for(unsigned i;i<u.size();i++)
            result[i]=u[i]+v[i];
        return result;
    }

}
std::vector<float> vetor::subtract(std::vector<float> u, std::vector<float> v)
{
    if(u.size()!=v.size())
    {
        std::cout<<"Error in SOMA procedure! Vectors are from different size."<<std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        std::vector<float> result(u.size(),0);
        for(unsigned i;i<u.size();i++)
            result[i]=u[i]-v[i];
        return result;
    }

}
Point::Point(float xmin, float xmax, float ymin, float ymax)
{
    x=randomFloat(xmin,xmax);
    y=randomFloat(ymin,ymax);
    if(cg::myfx(x)<y)
        label=1;
    else
        label=-1;
}

Point::Point(float x_, float y_)
{
    x=x_;
    y=y_;
}

Point::~Point()
{

}

float Point::randomFloat(float a, float b)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void Point::show()
{
    if(label==1)//label==1
          glColor3f(0,0,1.0);
    else
          glColor3f(1.0,0,0);
	glPointSize(4.0);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
}
