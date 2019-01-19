#include "Circle.h"
namespace SHAPE{
    //IN DERIVED CLASS CONSTRUCTORS I USE THE BASE CLASS CONSTRUCTORS FOR THE INHERITENCE
    Circle::Circle()noexcept:Shape(),centerCoordX(0.0),centerCoordY(0.0),radius(0.0){ name="circle"; }
    Circle::Circle(int r,char positionVal)throw(MyException):Shape(0.0,0.0,0,positionVal),centerCoordX(0.),centerCoordY(0.){
        name="circle";
        if(r<=0)
            throw MyException("Circle's Values are false!");
        else
            radius=r;

    }
    Circle::Circle(double x,double y,int newRotate,char p,double centerX,double centerY,double r)throw(MyException):Shape(x,y,newRotate,p){
        name="circle";
        if(centerX<0||centerY<0||r<=0)
            throw MyException("Circle's Values are false!");
        else{
            centerCoordX=centerX;
            centerCoordY=centerY;
            radius=r;
        }

    }

    //OVERRIDED FUNCTIONS
    void Circle::draw(ostream& outputStream)const throw(MyException){
        if(this->position=='c'){
            outputStream<<R"(<svg viewBox="0 0 )"<<2*this->radius<<R"( )"<<2*this->radius<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
            outputStream<<R"(<circle cx=")"<<this->radius<<R"(" cy=")"<<this->radius<<R"(" r=")"<<this->radius<<R"(" fill="red" />)"<<endl;
        }
        else if(this->position=='i')
            outputStream<<R"(<circle cx=")"<<this->centerCoordX<<R"(" cy=")"<<this->centerCoordY<<R"(" r=")"<<this->radius<<R"(" fill="green" transform="rotate()"<<this->rotate<<R"(,)"<<this->pos_x<<R"(,)"<<this->pos_y<<")\" />"<<endl;
        else
            throw MyException("UNVALID POSITION VALUE");

        return;
    }

    double Circle::area()const noexcept{ return PI*radius*radius; }
    double Circle::perimeter()const noexcept{ return 2*PI*radius; }

    //IN OPERATOR ++,-- OVERLOADS BECAUSE OF THE RETURNIN PROBLEMS I USE THE POINTERS
    Shape& Circle::operator++()noexcept{
         Circle c1(pos_x,pos_y,rotate,position,++centerCoordX,++centerCoordY,radius);
         Shape*temp=&c1;
         return *temp;
     }
    Shape& Circle::operator++(int ignore)noexcept{
        Circle c1(pos_x,pos_y,rotate,position,centerCoordX++,centerCoordY++,radius);
        Shape*temp=&c1;
        return *temp;
    }
    Shape& Circle::operator--()noexcept{
        Circle c1(pos_x,pos_y,rotate,position,--centerCoordX,--centerCoordY,radius);
        Shape*temp=&c1;
        return *temp;
     }
    Shape& Circle::operator--(int ignore)noexcept{
        Circle c1(pos_x,pos_y,rotate,position,centerCoordX--,centerCoordY--,radius);
        Shape*temp=&c1;
        return *temp;
    }

    //SETTER
    void Circle::set(double x,double y,int newRotate,char p,double centerX,double centerY,double r)throw(MyException){
        if(r<=0||centerX<0||centerY<0||x<0||y<0)
    		throw MyException("YOU ENTERED UNVALID RADIUS OR COORDINATE VALUE");
    	else{
    		radius=r;
    		centerCoordX=centerX;
    		centerCoordY=centerY;
    		pos_x=x;
    		pos_y=y;
    	}

    	if(p!='c'||p!='i'){
    		throw MyException("YOU ENTERED UNVALID POSITION VALUE");
    	}
    	else
    		position=p;

    	rotate=newRotate;
    	return;
    }

    //GETTERS
    double Circle::getCenterCoordX()const noexcept{ return centerCoordX; }
    double Circle::getCenterCoordY()const noexcept{ return centerCoordY; }
    double Circle::getRadius()const noexcept{ return radius; }


}
