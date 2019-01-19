#ifndef POLYGON_H
#define POLYGON_H
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
namespace SHAPE{
    //I DERIVED THE NEW CLASS FROM SHAPE AND I USE THE ABSTRACT FOR THE OTHER CHILD CLASS
    class Polygon : public Shape{
    public:
        Polygon()noexcept;
        Polygon(double x,double y,int newRotate,char p)noexcept;
        virtual void draw(ostream& outputStream)const throw(MyException) override=0;

        //I DECLARE THE POINT2D(HOLD THE X AND Y POINT) IN BASE POLYGON CLASS BECAUSE THIS IS THE MUTUAL FOR THE POLYGONDYN AND POLYGONVECT
        class Point2d{
        public:
       	    Point2d(){/*intentionally empty*/}
            Point2d(double newX,double newY)throw(MyException);
            void set(double newX,double newY)throw(MyException);
            double getX()const noexcept;
            double getY()const noexcept;
        private:
            double polygonX;
            double polygonY;
        };

        //GARBAGE FUNCTIONS(++,--)
        virtual double area()const noexcept override final;
        virtual double perimeter()const noexcept override final;
        virtual Shape& operator++()noexcept override final;//for prefix
        virtual Shape& operator++(int)noexcept override final;//for postfix
        virtual Shape& operator--()noexcept override final;//for prefix
        virtual Shape& operator--(int)noexcept override final;//for postfix*/

        //POLYGON IS THE BASE ABSTRACT CLASS BECAUSE OF IT I DECLARE VIRTUAL DESTRUCTOR
        virtual ~Polygon()noexcept{}

    };
}

#endif
