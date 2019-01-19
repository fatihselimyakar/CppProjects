#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
namespace SHAPE{
    class Triangle : public Shape{
    public:
        Triangle()noexcept;
        Triangle(int lateralVal,char positionVal,double trixVal,double triyVal,double tri2xVal,double tri2yVal,double tri3xVal,double tri3yVal,int rotateVal,double pos_xVal,double pos_yVal)throw(MyException);//GENERATES A TRIANGLE RESPECT TO ALL MEMBER VARIABLES
        Triangle(int lateralVal,char positionVal)throw(MyException);//GENERATES A TRIANGLE RESPECT TO LATERAL, POSITION VALUES
        Triangle(double trixVal,double triyVal,double tri2xVal,double tri2yVal,double tri3xVal,double tri3yVal)noexcept;//GENERATES A TRIANGLE RESPECT TO CORNER POINTS

        virtual double area()const noexcept override final;//RETURNS TRIANGLE'S AREA
        virtual double perimeter()const noexcept override final;//RETURNS TRIANGLE'S PERIMETER
        virtual void draw(ostream& outputStream)const throw(MyException) override final;//DRAWS A TRIANGLE IN SVG

        virtual Shape& operator++()noexcept override final;//for prefix
    	virtual Shape& operator++(int)noexcept override final;//for postfix
    	virtual Shape& operator--()noexcept override final;//for prefix
    	virtual Shape& operator--(int)noexcept override final;//for postfix


        double getTriX()const noexcept;
        double getTriY()const noexcept;
        double getTri2X()const noexcept;
        double getTri2Y()const noexcept;
        double getTri3X()const noexcept;
        double getTri3Y()const noexcept;
        int getLateral()const noexcept;

        void set(int lateralVal,char positionVal,double trixVal,double triyVal,double tri2xVal,double tri2yVal,double tri3xVal,double tri3yVal,int rotateVal,double pos_xVal,double pos_yVal)throw(MyException);
    private:
        int lateral;
        double triX,triY,tri2X,tri2Y,tri3X,tri3Y;//Tringle's corner points
    };
}
#endif
