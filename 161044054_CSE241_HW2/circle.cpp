#include"circle.h"

void circle::set(int newRadius,char newPosition,double newCenterCoordX,double newCenterCoordY,int newRotate){
	if(newRadius<=0||newCenterCoordX<0||newCenterCoordY<0){
		cout<<"YOU ENTERED UNVALID RADIUS OR COORDINATE VALUE"<<endl;
		exit(1);
	}
	else{
		radius=newRadius;
		centerCoordX=newCenterCoordX;
		centerCoordY=newCenterCoordY;
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
