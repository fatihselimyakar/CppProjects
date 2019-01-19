#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
namespace SHAPE{
    //CIRCLE DERIVED FROM SHAPE
    class Circle : public Shape{
    public:
        Circle()noexcept;
        Circle(int radiusValue,char positionValue)throw(MyException);//GENERATES A CIRCLE RESPECT TO RADIUS AND POSITION
        Circle(double x,double y,int newRotate,char p,double centerX,double centerY,double r)throw(MyException);//GENERATES A CIRCLE RESPECT TO ALL MEMBERS

        virtual double area()const noexcept override final;//RETURNS HOLDING CIRCLE'S AREA
        virtual double perimeter()const noexcept override final;//RETURNS THE HOLDING CIRCLE'S PERIMETER
        virtual void draw(ostream& outputStream)const throw(MyException) override final;//DRAW A CIRCLE IN SVG FILE

        virtual Shape& operator++()noexcept override final;//for prefix
    	virtual Shape& operator++(int)noexcept override final;//for postfix
    	virtual Shape& operator--()noexcept override final;//for prefix
    	virtual Shape& operator--(int)noexcept override final;//for postfix

        void set(double x,double y,int newRotate,char p,double centerX,double centerY,double r)throw(MyException);//SET THE CIRCLE'S VALUE RESPECT TO ALL MEMBERS

        double getCenterCoordX()const noexcept;
        double getCenterCoordY()const noexcept;
        double getRadius()const noexcept;
    private:
        double centerCoordX;//center point's x coordinate
    	double centerCoordY;//center point's y coordinate
        double radius;
    };
}


#endif
