#include"circle.h"

double circle::totalArea=0;
double circle::totalPerimeter=0;


void circle::set(int newRadius,char newPosition,double newCenterCoordX,double newCenterCoordY,int newRotate,double newPos_x,double newPos_y){
	if(newRadius<=0||newCenterCoordX<0||newCenterCoordY<0||newPos_x<0||newPos_y<0){
		cout<<"YOU ENTERED UNVALID RADIUS OR COORDINATE VALUE"<<endl;
		exit(1);
	}
	else{
		radius=newRadius;
		centerCoordX=newCenterCoordX;
		centerCoordY=newCenterCoordY;
		pos_x=newPos_x;
		pos_y=newPos_y;
	}
		
	
	if(newPosition!='c'&&newPosition!='i'){
		cout<<"YOU ENTERED UNVALID POSITION VALUE"<<endl;
		exit(1);
	}
	else
		position=newPosition;
		
	rotate=newRotate;
	return;
}

void circle::set(double newCenterCoordX,double newCenterCoordY){
	if(newCenterCoordX<0||newCenterCoordY<0){
		cout<<"YOU ENTERED UNVALID COORD VALUE"<<endl;
		exit(1);
	}
	else{
		centerCoordX=newCenterCoordX;
		centerCoordY=newCenterCoordY;
	}
		
	return;
	
}

void circle::set(int newRotate){ rotate=newRotate; }

void circle::set(char newPosition){
	if(newPosition!='c'&&newPosition!='i'){
		cout<<"YOU ENTERED UNVALID POSITION VALUE"<<endl;
		exit(1);
	}
	else
		position=newPosition;
}

void circle::input(){
	cout<<"Please enter the circle's radius:"<<endl;
	cin>>radius;
	if(radius<=0){
		cout<<"Program Aborted!(UNVALID RADIUS)"<<endl;
		exit(1);
	}
	
	return;
}

//this function draws the one small circle by the member variables and parameters
void circle::draw(ofstream& outputStream,double pos_x,double pos_y){
	if(position=='c'){
		outputStream<<R"(<svg viewBox="0 0 )"<<2*radius<<R"( )"<<2*radius<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
		outputStream<<R"(<circle cx=")"<<radius<<R"(" cy=")"<<radius<<R"(" r=")"<<radius<<R"(" fill="red" />)"<<endl;
	}
	else if(position=='i'){
		outputStream<<R"(<circle cx=")"<<centerCoordX<<R"(" cy=")"<<centerCoordY<<R"(" r=")"<<radius<<R"(" fill="green" transform="rotate()"<<rotate<<R"(,)"<<pos_x<<R"(,)"<<pos_y<<")\" />"<<endl;//DEĞİŞCEK!!!!!!!!!!!
	}
	   
	return;
	
}


//Operator overloadings->This one prints the shape in svg file 
ostream &operator<<(ostream& outputStream,const circle& shape){
	
	if(shape.position=='c'){
		outputStream<<R"(<svg viewBox="0 0 )"<<2*shape.radius<<R"( )"<<2*shape.radius<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
		outputStream<<R"(<circle cx=")"<<shape.radius<<R"(" cy=")"<<shape.radius<<R"(" r=")"<<shape.radius<<R"(" fill="red" />)"<<endl;
	}
	else if(shape.position=='i'){
		outputStream<<R"(<circle cx=")"<<shape.centerCoordX<<R"(" cy=")"<<shape.centerCoordY<<R"(" r=")"<<shape.radius<<R"(" fill="green" transform="rotate()"<<shape.rotate<<R"(,)"<<shape.pos_x<<R"(,)"<<shape.pos_y<<")\" />"<<endl;
	}
	   
	return outputStream;
}

//This overloading add 1 to the coordinates and returns(prefix)
circle circle::operator++(){
	centerCoordX=centerCoordX+1.;
	centerCoordY=centerCoordY+1.;
	
	return circle(centerCoordX,centerCoordY);
}

//This overloading add 1 to the coordinates but unadded value returns(postfix)
circle circle::operator++(int ignoreMe){
	double temp1=centerCoordX;
	double temp2=centerCoordY;
	centerCoordX=centerCoordX+1.;
	centerCoordY=centerCoordY+1.;
	
	return circle(temp1,temp2);
}

//This overloading add minus 1 to the coordinates and returns(prefix)
circle circle::operator--(){
	centerCoordX=centerCoordX-1.;
	centerCoordY=centerCoordY-1.;
	
	return circle(centerCoordX,centerCoordY);
}

//This overloading add minus 1 to the coordinates but unadded value returns(postfix)
circle circle::operator--(int ignoreMe){
	double temp1=centerCoordX;
	double temp2=centerCoordY;
	centerCoordX=centerCoordX-1.;
	centerCoordY=centerCoordY-1.;
	
	return circle(temp1,temp2);
}

//this overloading add "plus" radius
const circle circle::operator+(const double plus)const{
	double newRadius=radius+plus;
	return circle(newRadius,position,centerCoordX,centerCoordY,rotate,pos_x,pos_y);
}

//this overloading add "minus" radius
const circle circle::operator-(const double minus)const{
	double newRadius=radius-minus;
	return circle(newRadius,position,centerCoordX,centerCoordY,rotate,pos_x,pos_y);
}


