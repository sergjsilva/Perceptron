#include<GL/freeglut.h>
#include<vector>
#include "Point.h"
#include"Perceptron.h"

int LARGURA=640;
int ALTURA=480;
const int FPS=35;

float xmin=-5;
float xmax=12;
float ymin=-2;
float ymax=12;
unsigned nPts=3;


void display();
void init();
void trainingNeuron(int botao, int status, int x, int y);
void idle(int x);

std::vector<Point> data;
std::vector<float> input;

Perceptron neuron=Perceptron();


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
    init();

	glutDisplayFunc(display);
	glutMouseFunc(trainingNeuron);
	glutTimerFunc(1000/FPS,idle,0);

	glutMainLoop();

	return 0;
}

void init()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(LARGURA, ALTURA);
	glutCreateWindow("Perceptron Curve Fitting - UFR - APRIL 2019");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(xmin,xmax,ymin,ymax);

	data.push_back(Point(2,5));
	data.push_back(Point(4,3));
	data.push_back(Point(5,2));
	data.push_back(Point(1,10));
    data.push_back(Point(3,4));

   /* data.push_back(Point(0,4));
    data.push_back(Point(2,4.4));
    data.push_back(Point(4,4.8));
    data.push_back(Point(6,5.2));
    data.push_back(Point(8,5.6));
    */
    neuron.print();
}


void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Axis
    float corEixo[]={0,1,1};
    cg::Line(xmin,0,xmax,0,corEixo);
    cg::Line(0,ymin,0,ymax,corEixo);

    //plot Points
    for(unsigned i=0;i<data.size();i++)
        data[i].show();

    neuron.plot(xmin,xmax);
    neuron.print();

     glutSwapBuffers();
}

void trainingNeuron(int botao, int  status, int x, int y)
{
    if(botao==GLUT_LEFT_BUTTON)
		if(status==GLUT_DOWN)
            neuron.training(data);

    glutPostRedisplay();
}

void idle(int x)
{
	neuron.training(data);

	glutPostRedisplay();
	glutTimerFunc(1000/FPS,idle,0);
}

