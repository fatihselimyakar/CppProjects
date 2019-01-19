#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
namespace SHAPE{
    class Rectangle : public Shape{
    public:
        Rectangle()noexcept;
        Rectangle(int newHeight,int newWidth,double x,double y,int newRotate,char p)throw(MyException);//GENERATES A RECTANGLE RESPECT TO ALL MEMBER VARIABLES
        Rectangle(int heightVal,int widthVal,char positionVal)throw(MyException);//GENERATES A RECTANGLE RESPECT TO HEIGHT, WIDTH, AND POSITIONVALUE

        virtual double area()const noexcept override final;//RETURNS A RECTANGLE AREA THAT IS HOLD
        virtual double perimeter()const noexcept override final;//RETURNS A RECTANGLE PERIMETER THAT IS HOLD
        virtual void draw(ostream& outputStream)const throw(MyException) override final;//DRAW A RECTANGLE IN SVG FILE

        virtual Shape& operator++()noexcept override final;//for prefix
    	virtual Shape& operator++(int)noexcept override final;//for postfix
    	virtual Shape& operator--()noexcept override final;//for prefix
    	virtual Shape& operator--(int)noexcept override final;//for postfix*/


        int getHeight()const noexcept;
        int getWidth()const noexcept;
        void set(int newHeight,int newWidth,double x,double y,int newRotate,char p)throw(MyException);

    private:
        int height;
    	int width;
    };
}

#endif
