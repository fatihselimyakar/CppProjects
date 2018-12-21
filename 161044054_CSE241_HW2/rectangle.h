#ifndef RECTANGLE_H_

#define RECTANGLE_H_
#include<iostream>
#include<fstream>
using namespace std;

class rectangle{
public:
	
	rectangle(){/*intentionally empty*/}
	
	rectangle(int heightVal,int widthVal,char positionVal)
		:height(heightVal),width(widthVal),position(positionVal)
	{
			rotate=0;
			rectY=0;
			rectX=0;
	}
	
	rectangle(int heightVal,int widthVal,char positionVal,double rectXval,double rectYval,int rotateVal)
		:height(heightVal),width(widthVal),position(positionVal),rectX(rectXval),rectY(rectYval),rotate(rotateVal)
	{/*intentionally empy*/}
	
	int getHeight()const{ return height; }
	int getWidth()const{ return width; }
	char getPosition()const{ return position; }
	double getRectX()const{ return rectX; }
	double getRectY()const{ return rectY; }
	int getRotate()const{ return rotate; }
	
	void output()const{ cout<<"Rectangle's Height:"<<height<<" Width:"<<width<<" Position:"<<position<<" coord x:"<<rectX<<" coord y:"<<rectY<<" rotate val:"<<rotate<<endl; }
	void input();
	
	void set(int newHeight,int newWidth,char newPosition,double newRectX,double newRectY,int newRotate);
	void set(int newHeight,int newWidth);
	void set(int newRotate);
	void set(char newPosition);
	
	//the draw function draws only one shape
	void draw(ofstream& outputStream);
private:
	int height;
	int width;
	char position;//inner or container issues
	double rectX;//the edge coordinate's X
	double rectY;//the edge coordinate's Y
	int rotate;//rotating degree
	
};
#endif