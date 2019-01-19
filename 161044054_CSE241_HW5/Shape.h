#ifndef SHAPE_H
#define SHAPE_H
#define SQR3 1.732//for sqrt3
#define SQR3DIV2 0.866//for sqrt3/2
#define PI 3.14
#include <iostream>
#include <fstream>
#include <vector>
#include<cmath>
using namespace std;

//FOR THE EXCEPTIONS I DERIVED MYEXCEPTION CLASS FROM EXCEPTION BASE CLASS
class MyException : public exception{
public:
    MyException():str("ERROR OCCURED"){/*empty*/}
    MyException(string a):str(a){/*empty*/}
    virtual const char* what()const noexcept override final{
        return str.c_str();
    }
private:
    string str;
};
//I PUT THE ALL OF MY FUNCTION IN THE SHAPE NAMESPACE
namespace SHAPE{
    //I MAKE THE SHAPE ABSTRACT BASE CLASS
    class Shape{
    public:
        Shape()noexcept;
        Shape(double x,double y,int newRotate,char p)throw(MyException);
        Shape(double x,double y)throw(MyException);

        virtual double area()const noexcept=0;//RETURN THE SHAPE AREA
        virtual double perimeter()const noexcept=0;//RETURN THE SHAPE PERIMETER
        virtual void draw(ostream& outputStream)const throw(MyException)=0;//DRAWS IN SVG

        virtual Shape& operator++()noexcept=0;//for prefix
    	virtual Shape& operator++(int)noexcept=0;//for postfix
    	virtual Shape& operator--()noexcept=0;//for prefix
    	virtual Shape& operator--(int)noexcept=0;//for postfix*/

        //COMPORE OPERATORS
        const bool operator==(const Shape& rightSide)const noexcept;
        const bool operator!=(const Shape& rightSide)const noexcept;
        const bool operator>(const Shape& rightSide)const noexcept;
        const bool operator<(const Shape& rightSide)const noexcept;
        const bool operator>=(const Shape& rightSide)const noexcept;
        const bool operator<=(const Shape& rightSide)const noexcept;

        //SETTERS
        void set(double x,double y,int newRotate,char p) throw(MyException);
        void set(double x,double y) throw(MyException);

        //GETTERS
        double getPosX()const noexcept;
        double getPosY()const noexcept;
        int getRotate()const noexcept;
        char getPosition()const noexcept;
        string getName()const noexcept;

        //I USE THE VIRTUAL DESTRUCTOR IN BASE ABSTRACT CLASS
        virtual ~Shape()noexcept{}
    protected:
        //I PUT THE ALL I NEED MUTUAL MEMBER PARAMETERS
        double pos_x;
        double pos_y;
        int rotate;
        char position;//for the inner and outer issue
        string name;//for ex: Triangle's name="triangle";
    };

    //GLOBAL OVERLOAD'S DECLARATION
    ostream& operator<<(ostream& outputStream,const Shape& PrintingShape) noexcept;//IMPLEMENT IS END OF THE SHAPE.CPP
    void printAll(ostream& outputStream,const vector<Shape*>PrintingVector)noexcept;//IMPLEMENT IS END OF THE SHAPE.CPP
    vector<Shape*> convertAll(vector<Shape*>ConvertingVector)throw(MyException);//IMPLEMENT IS END OF THE COMPOSEDSHAPE.CPP
    void printPoly(ostream& outputStream,const vector<Shape*>PrintingVector)throw(MyException);//IMPLEMENT IS END OF THE SHAPE.CPP
    void sortShapes(vector<Shape*>& SortingVector)noexcept;//IMPLEMENT IS END OF THE SHAPE.CPP

}

#endif
