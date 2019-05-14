#include "cg.h"
#include<GL/freeglut.h>


Point::Point()
{

}


Point::Point(double x_, double y_)
{
    x=x_;
    y=y_;
}



void cg::Line(double x1, double y1, double x2, double y2,float cor[3],float thickness)
{
    glColor3fv(cor);
	glLineWidth(thickness);
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
}

void cg::LinePoints(Point P, Point Q, float cor[3],float thickness)
{
    Line(P.x, P.y, Q.x, Q.y, cor,thickness);
}


void cg::PlotFunction(Function f, double xmin_, double xmax_,float cor[3],float thickness)
{
    int nPts=500;
	int nSubIntervalos=nPts-1;

	double x=xmin_;
	double y=f(x);

	double incr=(xmax_-xmin_)/nSubIntervalos;

	glColor3fv(cor);
	glLineWidth(thickness);
	glBegin(GL_LINE_STRIP);
	for(unsigned i=1; i<=nPts; i++)
    {
			glVertex2f(x,y);
			x+=incr;
			y=f(x);
	}
	glEnd();
}

void cg::ExtractPoints(Function f, int numOfPts, Knots& P, double xmin_, double xmax_)
{
	int nSubIntervalos=numOfPts-1;
	double x=xmin_;
	double y=f(x);
	double incr=(xmax_-xmin_)/nSubIntervalos;
	P.clear();
	for(int i=0; i<numOfPts; i++)
	{
		Point p(x,y);
		P.push_back(p);
		x+=incr;
		y=f(x);
	}

}

void cg::PlotPoints(Knots P, float cor[3])
{
	glColor3fv(cor);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	for(unsigned i=0; i<P.size(); i++)
		{
			glVertex2f(P[i].x,P[i].y);
		}
	glEnd();
}


