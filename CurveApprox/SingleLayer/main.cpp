#include<GL/freeglut.h>
#include<vector>
#include<cmath>
#include<iostream>
#include<windows.h>
#include<string>

#include "cg.h"
#include "Perceptron.h"


int LARGURA=640;
int ALTURA=480;
const int FPS=35;
unsigned int nPts=50;

float xmin=-2;
float xmax=2;
float ymin=-2;
float ymax=2;


double funcao(double x);
void display();
void init();
void trainingNeuron(int botao, int status, int x, int y);
void idle(int x);

Knots data; // vector of points(x,y)
POINT p;

Perceptron neuron1=Perceptron();
Perceptron neuron2=Perceptron();

Function myFunc;

int main(int argc, char* argv[])
{
    SetConsoleTitle(" Curve Fitting with Single Layer Perceptron - UFR -  May 2019");
	glutInit(&argc, argv);
    init();

	glutDisplayFunc(display);
	glutMouseFunc(trainingNeuron);
	glutTimerFunc(1000/FPS,idle,0);

	glutMainLoop();

	return 0;
}

double funcao(double x)
{
    //return sin(x)*cos(2*x);
    return sin(2*x)*cos(x);
}

void init()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(LARGURA, ALTURA);
	glutInitWindowPosition(800,150);

	glutCreateWindow("Ajuste de Curvas - Perceptron  - UFR - Maio de  2019");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(xmin,xmax,ymin,ymax);

    myFunc=funcao;
    cg::ExtractPoints(myFunc,nPts,data,xmin,xmax);// Extract 10 points from f(x), x in [xmin. xmax] and stpres it in data

    neuron2.drawCurve=1;

    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Fitting f(x)=SIN(X)*COS(2X)\n"<<std::endl;
    std::cout<<"Approximate f(x) by a polynomial of degree 5\n";
    std::cout<<"Extracting "<<nPts<<" points.\n";
    std::cout<<"p(X)=wo+w1X+w2X^2+w3X^3+w4X^4+w5X^5\n\n";

    std::cout<<"Black = SIGMOID FUNCTION"<<std::endl;
    std::cout<<"Red = HYPERBOLIC TANGENT FUNCTION"<<std::endl;

    std::cout<<"\n\n Weights by Hyperbolic Tangent Function \n";



}


void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    float cor[]={0,1,1};
    cg::Line(xmin,0,xmax,0,cor,3.0);
    cg::Line(0,ymin,0,ymax,cor,3.0);

    float corFunc[]={1,0,0};
    //cg::PlotFunction(myFunc,xmin,xmax,corFunc,1.5);

    float colorPoints[]={0.3,0.5,1.0};

    cg::PlotPoints(data,colorPoints);

   // neuron.training(data);
    float corPerceptron1[]={0,0,0};
    neuron1.plot(xmin,xmax,corPerceptron1);

    float corPerceptron2[]={1,0,0};
    neuron2.plot(xmin,xmax,corPerceptron2);

    neuron2.print();


    glutSwapBuffers();
}

void trainingNeuron(int botao, int  status, int x, int y)
{
    if(botao==GLUT_LEFT_BUTTON)
		if(status==GLUT_DOWN)
		{
			neuron1.training(data);
			neuron2.training(data);

		}

    glutPostRedisplay();
}

void idle(int x)
{
    neuron1.training(data);
    neuron2.training(data);
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,idle,0);
}

