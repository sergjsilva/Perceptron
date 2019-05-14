#pragma once

#include<vector>
#include<string>


using std::vector;
using std::string;

class Point{
public:
	double x;
	double y;
	Point(double x_, double y_);
	Point();
};

typedef double (*Function)(double);
typedef vector<Point> Knots;

namespace cg
{
    void Line(double x1, double y1, double x2, double y2,float cor[3],float thickness);
    void LinePoints(Point P, Point Q, float cor[3],float thickness);
    void PlotFunction(Function f, double xmin_, double xmax_,float cor[3],float thickness);
    void ExtractPoints(Function f, int numOfPts,Knots& P, double xmin_, double xmax_);
    void PlotPoints(Knots P, float cor[3]);
};
