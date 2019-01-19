#include "Rectangle.h"
namespace SHAPE{
    Rectangle::Rectangle()noexcept:Shape(),height(0),width(0){ name="rectangle"; }

    Rectangle::Rectangle(int newHeight,int newWidth,double x,double y,int newRotate,char p)throw(MyException):Shape(x,y,newRotate,p){
        name="rectangle";
        if(newHeight<=0||newWidth<=0){
            throw MyException("UNVALID WIDTH OR HEIGHT VALUE");
        }
        else{
            height=newHeight;
            width=newWidth;
        }
    }

    Rectangle::Rectangle(int heightVal,int widthVal,char positionVal)throw(MyException):Shape(0.0,0.0,0,positionVal){
        name="rectangle";
        if(heightVal<=0||widthVal<=0){
            throw MyException("UNVALID WIDTH OR HEIGHT VALUE");
        }
        else{
            height=heightVal;
            width=widthVal;
        }
    }

    //OVERRIDED FUNCTIONS
    double Rectangle::area()const noexcept{ return height*width; }
    double Rectangle::perimeter()const noexcept{ return 2*(height+width); }

    void Rectangle::draw(ostream& outputStream)const throw(MyException){
        if(this->position=='c'){
    		outputStream<<R"(<svg version="1.1")"<<endl;//and then I print the svg code by shifting
    		outputStream<<R"(baseProfile="full")"<<endl;
    		outputStream<<R"(width=")"<<this->getWidth()<<R"(" height=")"<<this->getHeight()<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
    		outputStream<<R"(<rect width="100%" height="100%" fill="red" />)"<<endl;
    	}
    	else if(this->position=='i'){
    		outputStream<<R"(<rect x=")"<<this->getPosX()<<R"(" y=")"<<this->getPosY()<<R"(" width=")"<<this->getWidth()<<R"(" height=")"<<this->getHeight()<<R"(" fill="green" />)"<<endl;
    	}
        else{
            throw MyException("UNVALID POSITION VALUE");
        }

    	return;
    }

    //IN OPERATOR ++,-- OVERLOADS BECAUSE OF THE RETURNIN PROBLEMS I USE THE POINTERS
    Shape& Rectangle::operator++()noexcept{
         Rectangle r1(height,width,++pos_x,++pos_y,rotate,position);
         Shape*temp=&r1;
         return *temp;
     }
    Shape& Rectangle::operator++(int ignore)noexcept{
        Rectangle r1(height,width,pos_x++,pos_y++,rotate,position);
        Shape*temp=&r1;
        return *temp;
    }
    Shape& Rectangle::operator--()noexcept{
        Rectangle r1(height,width,--pos_x,--pos_y,rotate,position);
        Shape*temp=&r1;
        return *temp;
     }
    Shape& Rectangle::operator--(int ignore)noexcept{
        Rectangle r1(height,width,pos_x--,pos_y--,rotate,position);
        Shape*temp=&r1;
        return *temp;
    }

    //GETTERS
    int Rectangle::getHeight()const noexcept{ return height; }
    int Rectangle::getWidth()const noexcept{ return width; }

    //SETTER
    void Rectangle::set(int newHeight,int newWidth,double x,double y,int newRotate,char p)throw(MyException){
        if(newHeight<=0)
    		throw MyException("Program Aborted!(UNVALID HEIGHT VALUE)");
    	else
    		height=newHeight;

    	if(newWidth<=0)
    		throw MyException("Program Aborted!(UNVALID WIDTH VALUE)");
    	else
    		width=newWidth;

    	if(p!='c'&&p!='i')
    		throw MyException("Program Aborted!(UNVALID POSITION VALUE)");
    	else
    		position=p;

    	if(x<0||y<0)
    		throw MyException("Program Aborted!(UNVALID COORD VALUE)");
    	else{
    		pos_x=x;
    		pos_y=y;
    	}

    	rotate=newRotate;

    	return;
    }

}
