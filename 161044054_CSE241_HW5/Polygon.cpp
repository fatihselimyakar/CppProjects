#include "Polygon.h"
namespace SHAPE{
    //CONSTRUCTORS
    Polygon::Polygon()noexcept:Shape(){ name="polygon"; }
    Polygon::Polygon(double x,double y,int newRotate,char p)noexcept:Shape(x,y,newRotate,p){ name="polygon"; }

    //POINT2D'CONSTRUCTOR IT GENERATES X AND Y
    Polygon::Point2d::Point2d(double newX,double newY)throw(MyException){
        if(newX>=0&&newY>=0){
            polygonX=newX;
            polygonY=newY;
        }
        else
            throw MyException("Error your constructor isn't true");
    }
    //POINT2D SETTER
    void Polygon::Point2d::set(double newX,double newY)throw(MyException){
        if(newX>=0&&newY>=0){
            polygonX=newX;
            polygonY=newY;
        }
        else
            throw MyException("Error your set function isn't true");
        return;
    }

    //GETTERS
    double Polygon::Point2d::getX()const noexcept{ return polygonX; }
    double Polygon::Point2d::getY()const noexcept{ return polygonY; }

    //GARBAGE FUNCTIONS
    double Polygon::area()const noexcept{ return 0.0; }
    double Polygon::perimeter()const noexcept{ return 0.0; }
    Shape& Polygon::operator++()noexcept{ return *this; }
    Shape& Polygon::operator++(int ignore)noexcept{ return *this; }
    Shape& Polygon::operator--()noexcept{ return *this; }
    Shape& Polygon::operator--(int ignore)noexcept{ return *this; }
}
