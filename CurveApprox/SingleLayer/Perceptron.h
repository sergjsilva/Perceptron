#pragma once

#include<vector>
#include "cg.h"


class Perceptron
{
    public:
         double predict(std::vector<double> inputs);
         std::vector<double> weights;
         double learningCoef=0.0001;
         int drawCurve;

         Perceptron();
        ~Perceptron();
         void print();

         void training(Knots data);
         void plot(double xmin, double xmax,float cor[3]);

    private:
        double random(double a, double b); // retorna random entre [a,b]
        double activation(double x); // Activation Function
        double fx(double x);
        double dotProduct(std::vector<double> u, std::vector<double> v);
        double curve(double x);
};




