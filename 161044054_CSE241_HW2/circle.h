#ifndef CIRCLE_H_

#define CIRCLE_H_
#include<iostream>
#include<fstream>

using namespace std;

class circle{
public:
	circle(){/*intentionally empty*/}
	
	circle(int radiusValue,char positionValue,double coordxValue,double coordyValue,int rotateValue)
		:centerCoordX(coordxValue),centerCoordY(coordyValue),rotate(rotateValue),position(positionValue),radius(radiusValue)
	{/*intentionally empty*/}
	
	circle(int radiusValue,char positionValue)
		:radius(radiusValue),position(positionValue)
	{/*intentionallt enmpty*/}
	
	
	void set(int newRadius,char newPosition,double newCenterCoordX,double newCenterCoordY,int newRotate);
	void set(double newCenterCoordX,double newCenterCoordY);
	void set(int newRotate);
	void set(char newPosition);
	
	int getRadius()const{ return radius; }
	char getPosition()const{ return position; }
	double getCenterCoordX()const{ return centerCoordX; }
	double getCenterCoordY()const{ return centerCoordY; }
	int getRotate()const{ return rotate; }

	
	void input();
	void output()const{ cout<<"The circle's position:"<<position<<" radius:"<<radius<<" coord x:"<<centerCoordX<<" coord y:"<<centerCoordY<<" rotate:"<<rotate<<endl; }
	//this function draws the one small circle(the pos_x and pos_y is rotating point's x and y)
	void draw(ofstream& outputStream,double pos_x,double pos_y);
private:
	double centerCoordX;
	double centerCoordY;
	int rotate;//the degree of rotating
	int radius;
	char position;//inner or container shape issue
};

#endif