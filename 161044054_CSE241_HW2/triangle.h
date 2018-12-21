#ifndef TRIANGLE_H_

#define TRIANGLE_H_
#include<iostream>
#include<fstream>
#define SQR3 1.732//for sqrt3
#define SQR3DIV2 0.866//for sqrt3/2

using namespace std;

class triangle{
public:
	triangle(){/*intentionally empty*/}
	
	triangle(int lateralVal,char positionVal,double trixVal,double triyVal,double tri2xVal,double tri2yVal,double tri3xVal,double tri3yVal,int rotateVal)
		:lateral(lateralVal),position(positionVal),triX(trixVal),triY(triyVal),tri2X(tri2xVal),tri2Y(tri2yVal),tri3X(tri3xVal),tri3Y(tri3yVal),rotate(rotateVal)
		{/*intentionally empy*/}
	
	triangle(int lateralVal,char positionVal,double trixVal,double triyVal,int rotateVal)
		:lateral(lateralVal),position(positionVal),triX(trixVal),triY(triyVal),rotate(rotateVal)
		{/*intentionally empy*/}
	
	triangle(int lateralVal,char positionVal)
		:lateral(lateralVal),position(positionVal)
		{/*intentionally empty*/}
	
	int getLateral()const{ return lateral; }
	char getPosition()const{ return position; }
	double getTriX()const{ return triX; }
	double getTriY()const{ return triY; }
	double getTri2X()const{ return tri2X; }
	double getTri2Y()const{ return tri2Y; }
	double getTri3X()const{ return tri3X; }
	double getTri3Y()const{ return tri3Y; }
	int getRotate()const{ return rotate; }
	
	
	void input();
	void output()const{ cout<<"Triangle's lateral:"<<lateral<<" position:"<<position<<" rotate:"<<rotate<<" coord x:"<<triX<<"coord y:"<<triY<<endl; }
	
	void set(int newLateral,char newPosition,double newTriX,double newTriY,int newRotate);
	void set(int newLateral,char newPosition,double newTriX,double newTriY,double newTri2X,double newTri2Y,double newTri3X,double newTri3Y,int newRotate);
	void set(double newTriX,double newTriY);
	void set(char newPosition);
	//the draw function draws only one shape
	void draw(ofstream& outputStream,double pos_x,double pos_y);
private:
	int lateral;//it is the one side of equalateral triangle
	char position;//inner or container issue
	double triX,triY,tri2X,tri2Y,tri3X,tri3Y;//for edges coordinates
	int rotate;//degree of rotate
};
#endif