#ifndef TRIANGLE_H_

#define TRIANGLE_H_
#include<iostream>
#include<fstream>
#define SQR3 1.732//for sqrt3
#define SQR3DIV2 0.866//for sqrt3/2

using namespace std;

class triangle{
public:
	//for the operator overloading I add the static variables adding in constructors
	triangle(){	totalArea=totalArea+area();
			totalPerimeter=totalPerimeter+periLength(); 	}

	triangle(double trixVal,double triyVal,double tri2xVal,double tri2yVal,double tri3xVal,double tri3yVal)//for the operator overload
		:triX(trixVal),triY(triyVal),tri2X(tri2xVal),tri2Y(tri2yVal),tri3X(tri3xVal),tri3Y(tri3yVal)
		{	totalArea=totalArea+area();
			totalPerimeter=totalPerimeter+periLength(); }

	triangle(int lateralVal,char positionVal,double trixVal,double triyVal,double tri2xVal,double tri2yVal,double tri3xVal,double tri3yVal,int rotateVal,double pos_xVal,double pos_yVal)
		:lateral(lateralVal),position(positionVal),triX(trixVal),triY(triyVal),tri2X(tri2xVal),tri2Y(tri2yVal),tri3X(tri3xVal),tri3Y(tri3yVal),rotate(rotateVal),pos_x(pos_xVal),pos_y(pos_yVal)
		{	totalArea=totalArea+area();
			totalPerimeter=totalPerimeter+periLength(); }

	triangle(int lateralVal,char positionVal,double trixVal,double triyVal,int rotateVal)
		:lateral(lateralVal),position(positionVal),triX(trixVal),triY(triyVal),rotate(rotateVal)
		{	totalArea=totalArea+area();
			totalPerimeter=totalPerimeter+periLength(); }

	triangle(int lateralVal,char positionVal)
		:lateral(lateralVal),position(positionVal)
		{	totalArea=totalArea+area();
			totalPerimeter=totalPerimeter+periLength(); }

	int getLateral()const{ return lateral; }
	char getPosition()const{ return position; }
	double getTriX()const{ return triX; }
	double getTriY()const{ return triY; }
	double getTri2X()const{ return tri2X; }
	double getTri2Y()const{ return tri2Y; }
	double getTri3X()const{ return tri3X; }
	double getTri3Y()const{ return tri3Y; }
	int getRotate()const{ return rotate; }
	double getTriRotateByX()const{ return pos_x; }
	double getTriRotateByY()const{ return pos_y; }

	//PERIMETER AND AREA CALCS
	int periLength()const{ return lateral*3; }
	double area()const{ return (lateral*lateral*SQR3)/4.; }

	//OPERATOR OVERLOADINGS
	friend ostream& operator<<(ostream& outputStream,const triangle& shape);
	triangle operator++();//for prefix
	triangle operator++(int);//for postfix
	triangle operator--();//for prefix
	triangle operator--(int);//for postfix
	const triangle operator+(double plus)const;
	const triangle operator-(double minus)const;
	const bool operator==(const triangle& shape2)const{ return area()==shape2.area(); }
	const bool operator!=(const triangle& shape2)const{ return area()!=shape2.area(); }
	const bool operator>(const triangle& shape2)const{ return  area()>shape2.area(); }
	const bool operator<(const triangle& shape2)const{ return  area()<shape2.area(); }
	const bool operator>=(const triangle& shape2)const{ return  area()>=shape2.area(); }
	const bool operator<=(const triangle& shape2)const{ return  area()<=shape2.area(); }
	//STATIC FUNCTIONS
	static double calcTotalArea(){ return totalArea; }
	static double calcTotalPerimeter(){ return totalPerimeter; }

	void input();
	void output()const{ cout<<"Triangle's lateral:"<<lateral<<" position:"<<position<<" rotate:"<<rotate<<" coord x:"<<triX<<"coord y:"<<triY<<" 2.coord x:"<<tri2X<<" 2.coord y:"<<tri2Y<<" 3.coord x:"<<tri3X<<" 3.coord y:"<<tri3Y<<endl; }

	void set(int newLateral,char newPosition,double newTriX,double newTriY,int newRotate);
	void set(int newLateral,char newPosition,double newTriX,double newTriY,double newTri2X,double newTri2Y,double newTri3X,double newTri3Y,int newRotate);
	void set(double newTriX,double newTriY);
	void set(char newPosition);
	//the draw function draws only one shape
	void draw(ofstream& outputStream,double pos_x,double pos_y);
private:
	//for the static funtions
	static double totalArea;
	static double totalPerimeter;
	int lateral;//it is the one side of equalateral triangle
	char position;//inner or container issue
	double triX,triY,tri2X,tri2Y,tri3X,tri3Y;//for edges coordinates
	int rotate;//degree of rotate
	double pos_x,pos_y;
};
#endif
