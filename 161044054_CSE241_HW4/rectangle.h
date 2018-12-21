#ifndef RECTANGLE_H_

#define RECTANGLE_H_
#include<iostream>
#include<fstream>
using namespace std;

class rectangle{
public:
	//for the operator overloading I add the static variables adding in constructors
	rectangle(){	totalArea=totalArea+area();
			totalPerimeter=totalPerimeter+periLength();	}
	
	rectangle(double rectXval,double rectYval)
		:rectX(rectXval),rectY(rectYval)
	{	totalArea=totalArea+area();
		totalPerimeter=totalPerimeter+periLength(); }
	
	rectangle(int heightVal,int widthVal,char positionVal)
		:height(heightVal),width(widthVal),position(positionVal)
	{
			rotate=0;
			rectY=0;
			rectX=0;
			totalArea=totalArea+area();
			totalPerimeter=totalPerimeter+periLength();
	}
	
	rectangle(int heightVal,int widthVal,char positionVal,double rectXval,double rectYval,int rotateVal)
		:height(heightVal),width(widthVal),position(positionVal),rectX(rectXval),rectY(rectYval),rotate(rotateVal)
	{	totalArea=totalArea+area();
		totalPerimeter=totalPerimeter+periLength(); }
	
	
	
	int getHeight()const{ return height; }
	int getWidth()const{ return width; }
	char getPosition()const{ return position; }
	double getRectX()const{ return rectX; }
	double getRectY()const{ return rectY; }
	int getRotate()const{ return rotate; }
	
	//PERIMETER AND AREA CALCS
	int periLength()const{ return 2*(width+height); }
	int area()const{ return width*height; }
	
	//OPERATOR OVERLOADINGS 
	friend ostream& operator<<(ostream& outputStream,const rectangle& shape);
	rectangle operator++();//for prefix
	rectangle operator++(int);//for postfix
	rectangle operator--();//for prefix
	rectangle operator--(int);//for postfix
	const rectangle operator+(const double plus)const;
	const rectangle operator-(const double minus)const;
	const bool operator==(const rectangle& shape2)const{ return area()==shape2.area(); }
	const bool operator!=(const rectangle& shape2)const{ return area()!=shape2.area(); }
	const bool operator>(const rectangle& shape2)const{ return  area()>shape2.area(); }
	const bool operator<(const rectangle& shape2)const{ return  area()<shape2.area(); }
	const bool operator>=(const rectangle& shape2)const{ return  area()>=shape2.area(); }
	const bool operator<=(const rectangle& shape2)const{ return  area()<=shape2.area(); }
	//STATIC FUNCTIONS	
	static double calcTotalArea(){ return totalArea; }
	static double calcTotalPerimeter(){ return totalPerimeter; }
	
	void output()const{ cout<<"Rectangle's Height:"<<height<<" Width:"<<width<<" Position:"<<position<<" coord x:"<<rectX<<" coord y:"<<rectY<<" rotate val:"<<rotate<<endl; }
	void input();
	
	void set(int newHeight,int newWidth,char newPosition,double newRectX,double newRectY,int newRotate);
	void set(int newHeight,int newWidth);
	void set(int newRotate);
	void set(char newPosition);
	
	//the draw function draws only one shape
	void draw(ofstream& outputStream);
private:
	//for the static funtions
	static double totalArea;
	static double totalPerimeter;
	int height;
	int width;
	char position;//inner or container issues
	double rectX;//the edge coordinate's X
	double rectY;//the edge coordinate's Y
	int rotate;//rotating degree
	
};
#endif
