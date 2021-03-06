#include "Perceptron.h"
#include "Point.h"
#include<cstdlib>
#include<GL/freeglut.h>
#include<iostream>
#include<iomanip>


using std::cout;
using std::endl;

Perceptron::Perceptron()
{
    //weights.resize(3);// reserva 3
    for(unsigned i=0;i<2;i++)
    {
        float w=random(-1,1);
        weights.push_back(w);
    }

}

Perceptron::~Perceptron()
{
    //dtor

}

void Perceptron::print()
{
    using std::setprecision;
    for(unsigned i=0;i<weights.size();i++)
        cout<<setprecision(3)<< std::fixed<< weights[i] << " ";

    cout<<endl;

}
float Perceptron::random(float a, float b)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

 float Perceptron::dotProduct(std::vector<float> u, std::vector<float> v)
{
    float sum=0;
    for(unsigned i=0;i<v.size();i++)
        sum+=u[i]*v[i];
    return sum;
}

float Perceptron::predict(std::vector<float> inputs)
{
    float output=dotProduct(inputs,weights);
    //std::cout<<output<<std::endl;
    return output;
}

int Perceptron::sign(float n) // Activation Function
{
    if(n>=0)
        return 1;
    else
        return -1;
}

void Perceptron::training(std::vector<Point> data)
{
    std::vector<float> inputs;
    for(unsigned j=0;j<weights.size();j++)
    {
        float somaError=0;
        for(unsigned i=0;i<data.size();i++)
        {
            inputs.push_back(1);
            inputs.push_back(data[i].x);
            float finded=predict(inputs);
            //std::cout<<"Finded="<<finded<<std::endl;
            float error=finded-data[i].y;
            somaError+=error*inputs[j];
            inputs.clear();
        }
        weights[j]-=learningCoef*somaError;
    }

}

void Perceptron::plot(float xmin, float xmax)
{
    float x1=xmin;
	float y1=linear(x1);
	float x2=xmax;
	float y2=linear(x2);

	glLineWidth(2.5);
	glLineStipple(1, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glColor3f(1,0.6,0);
	glBegin(GL_LINE_STRIP);
        glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
    glDisable(GL_LINE_STIPPLE);
}

float Perceptron::linear(float x)
{
    return weights[0]+x*weights[1];
}
