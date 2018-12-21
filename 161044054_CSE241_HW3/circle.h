#ifndef CIRCLE_H_

#define CIRCLE_H_
#include<iostream>
#include<fstream>
#define PI 3.14

using namespace std;

class circle{
public:
	//for the operator overloading I add the static variables adding in constructors
	circle(){	totalArea=totalArea+area();
			totalPerimeter=totalPerimeter+periLength();	}
	
	circle(double coordxValue,double coordyValue)
		:centerCoordX(coordxValue),centerCoordY(coordyValue)
	{	totalArea=totalArea+area();
		totalPerimeter=totalPerimeter+periLength(); }
	
	circle(int radiusValue,char positionValue,double coordxValue,double coordyValue,int rotateValue,double pos_xValue,double pos_yValue)
		:centerCoordX(coordxValue),centerCoordY(coordyValue),rotate(rotateValue),position(positionValue),radius(radiusValue),pos_x(pos_xValue),pos_y(pos_yValue)
	{	totalArea=totalArea+area();
		totalPerimeter=totalPerimeter+periLength(); }
	
	circle(int radiusValue,char positionValue)
		:radius(radiusValue),position(positionValue)
	{	totalArea=totalArea+area();
		totalPerimeter=totalPerimeter+periLength(); }
	
	
	void set(int newRadius,char newPosition,double newCenterCoordX,double newCenterCoordY,int newRotate,double newPos_x,double newPos_y);
	void set(double newCenterCoordX,double newCenterCoordY);
	void set(int newRotate);
	void set(char newPosition);
	
	int getRadius()const{ return radius; }
	char getPosition()const{ return position; }
	double getCenterCoordX()const{ return centerCoordX; }
	double getCenterCoordY()const{ return centerCoordY; }
	int getRotate()const{ return rotate; }
	
	//PERIMETER AND AREA CALCS
	double periLength()const{ return 2*PI*radius; }
	double area()const{ return PI*radius*radius; }
	
	//OPERATOR OVERLOADINGS 	
	friend ostream& operator<<(ostream& outputStream,const circle& shape);
	circle operator++();//for prefix
	circle operator++(int);//for postfix
	circle operator--();//for prefix
	circle operator--(int);//for postfix
	const circle operator+(const double plus)const;
	const circle operator-(const double plus)const;
	const bool operator==(const circle& shape2)const{ return area()==shape2.area(); }
	const bool operator!=(const circle& shape2)const{ return area()!=shape2.area(); }
	const bool operator>(const circle& shape2)const{ return  area()>shape2.area(); }
	const bool operator<(const circle& shape2)const{ return  area()<shape2.area(); }
	const bool operator>=(const circle& shape2)const{ return  area()>=shape2.area(); }
	const bool operator<=(const circle& shape2)const{ return  area()<=shape2.area(); }
	//STATIC FUNCTIONS	
	static double calcTotalArea(){ return totalArea; }
	static double calcTotalPerimeter(){ return totalPerimeter; }

	void input();
	void output()const{ cout<<"The circle's position:"<<position<<" radius:"<<radius<<" coord x:"<<centerCoordX<<" coord y:"<<centerCoordY<<" rotate:"<<rotate<<endl; }
	//this function draws the one small circle(the pos_x and pos_y is rotating point's x and y)
	void draw(ofstream& outputStream,double pos_x,double pos_y);
private:
	//for the static funtions
	static double totalArea;
	static double totalPerimeter;
	double centerCoordX;
	double centerCoordY;
	int rotate;//the degree of rotating
	int radius;
	char position;//inner or container shape issue
	double pos_x;
	double pos_y;
};

#endif
