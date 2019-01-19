#ifndef POLYGON_VECT_H
#define POLYGON_VECT_H
#include "Polygon.h"
namespace SHAPE{
    class PolygonVect : public Polygon{
    public:
        PolygonVect()noexcept;
        PolygonVect(vector<Point2d>pointVector)noexcept;//GENERATES A POLYGONVECT RESPECT TO POINT2D VECTOR
        PolygonVect(Rectangle rec)throw(MyException);//GENERATES A POLYGONVECT RESPECT TO PARAMETER RECTANGLE
        PolygonVect(Triangle tri)throw(MyException);//GENERATES A POLYGONVECT RESPECT TO PARAMETER TRIANGLE
        PolygonVect(Circle cir)throw(MyException);//GENERATES A POLYGONVECT RESPECT TO PARAMETER CIRCLE

        virtual void draw(ostream& outputStream)const throw(MyException) override final;//DRAW A POLYGON SHAPE IN SVG FILE
        const Point2d& operator[](int index)const throw(MyException);
    private:
        vector<Point2d>polyvector;//for the saving points
    };
}
#endif
