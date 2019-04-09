#pragma once

#include<vector>
#include "Point.h"


class Perceptron
{
    public:
         float predict(std::vector<float> inputs);
         std::vector<float> weights;
         float learningCoef=0.01;

         Perceptron();
        ~Perceptron();
         void print();

         void training(std::vector<Point> data);
         void plot(float xmin, float xmax);

    private:
        float random(float a, float b); // retorna random entre [a,b]
        int sign(float n); // Activation Function
        double fx(double x);
        float dotProduct(std::vector<float> u, std::vector<float> v);
        float linear(float x);
};




