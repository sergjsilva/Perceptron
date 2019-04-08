#include<GL/freeglut.h>
#include<vector>
#include "Point.h"
#include"Perceptron.h"

int LARGURA=640;
int ALTURA=480;
const int FPS=35;

float xmin=-10;
float xmax=10;
float ymin=-10;
float ymax=10;
unsigned nPts=200;


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
	glutCreateWindow("Perceptron - UFR - ABRIL 2019");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(xmin,xmax,ymin,ymax);

    for(unsigned i=0;i<nPts;i++)
    {
        Point P(xmin,xmax,ymin,ymax);
        data.push_back(P);
    }

}


void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    float cor[]={0,1,1};
    cg::Line(xmin,0,xmax,0,cor);
    cg::Line(0,ymin,0,ymax,cor);
    cg::plotFunc(xmin,xmax);

    for(unsigned i=0;i<data.size();i++)
        data[i].show();
    neuron.plot(xmin,xmax);



    glutSwapBuffers();
}

void trainingNeuron(int botao, int  status, int x, int y)
{
    if(botao==GLUT_LEFT_BUTTON)
		if(status==GLUT_DOWN)
		{
			for(int i=0;i<data.size();i++)
            {
                input.push_back(1);
                input.push_back(data[i].x);
                input.push_back(data[i].y);
                neuron.training(input,data[i].label);
                input.clear();
            }

		}

    glutPostRedisplay();
}

void idle(int x)
{
	for(int i=0;i<data.size();i++)
    {
        input.push_back(1);
        input.push_back(data[i].x);
        input.push_back(data[i].y);
        neuron.training(input,data[i].label);
        input.clear();
    }
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,idle,0);
}
