#ifndef POLYGON_DYN_H
#define POLYGON_DYN_H
#include "Polygon.h"
namespace SHAPE{
    class PolygonDyn : public Polygon{
    public:
        PolygonDyn()noexcept;
        PolygonDyn(vector<Point2d>pointVector)throw(MyException);//GENERATES A POLYGONDYN RESPECT TO POINT2D VECTOR
        PolygonDyn(int newCapacity,int newSize)throw(MyException);//GENERATES A POLYGONDYN RESPECT TO CAPACITY AND SIZE
        PolygonDyn(Rectangle rec)throw(MyException);//GENERATES A POLYGONDYN RESPECT TO PARAMETER RECTANGLE
        PolygonDyn(Triangle tri)throw(MyException);//GENERATES A POLYGONDYN RESPECT TO PARAMETER TRIANGLE
        PolygonDyn(Circle cir)throw(MyException);//GENERATES A POLYGONDYN RESPECT TO PARAMETER CIRCLE

        virtual void draw(ostream& outputStream)const throw(MyException) override final;//DRAW A POLYGON SHAPE IN SVG FILE
        Point2d& operator[](int index)const throw(MyException);//RETURNS points[index]

        int getCapacity()const noexcept;
        int getSize()const noexcept;

        PolygonDyn& operator=(const PolygonDyn& rightSide)noexcept;//assignment for big three
        PolygonDyn(const PolygonDyn& object)noexcept;//copy constructor
        ~PolygonDyn()noexcept;//destructor

    private:
        Point2d *points;
        int capacity;//IT IS THE CAPACITY OF "*points"
        int size;//IT IS THE SIZE OF "*points"
    };
}
#endif
