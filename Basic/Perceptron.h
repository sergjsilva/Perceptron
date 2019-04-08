#pragma once

#include<vector>


class Perceptron
{
    public:
         int predict(std::vector<float> inputs);
         std::vector<float> weights;
         float learningCoef=0.001;

         Perceptron();
        ~Perceptron();
         void print();

         void training(std::vector<float> inputs, int goal);
         void plot(float xmin, float xmax);

    private:
        float random(float a, float b); // retorna random entre [a,b]
        int sign(float n); // Activation Function
        double fx(double x);
        float dotProduct(std::vector<float> u, std::vector<float> v);
        float linear(float x);
};





