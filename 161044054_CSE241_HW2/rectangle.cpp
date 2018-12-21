#include"rectangle.h"
//for getting the input from user in driver(main) file
void rectangle::input(){
	cout<<"Please enter the rectangle's height"<<endl;
	cin>>height;
	if(height<=0){
		cout<<"YOU ENTERED UNVALID HEIGHT VALUE"<<endl;
		exit(1);
	}
	
	cout<<"Please enter the rectangle's width"<<endl;
	cin>>width;
	if(width<=0){
		cout<<"YOU ENTERED UNVALID WIDTH VALUE"<<endl;
		exit(1);
	}
	
	return;
}

void rectangle::set(char newPosition){
	if(newPosition!='c'&&newPosition!='i'){
		cout<<"Program Aborted!(UNVALID POSITION VALUE)"<<endl;
		exit(1);
	}
	else
		position=newPosition;
}

void rectangle::set(int newHeight,int newWidth,char newPosition,double newRectX,double newRectY,int newRotate){
	if(newHeight<=0){
		cout<<"Program Aborted!(UNVALID HEIGHT VALUE)"<<endl;
		exit(1);
	}
	else
		height=newHeight;
	
	if(newWidth<=0){
		cout<<"Program Aborted!(UNVALID WIDTH VALUE)"<<endl;
		exit(1);
	}
	else
		width=newWidth;
	
	if(newPosition!='c'&&newPosition!='i'){
		cout<<"Program Aborted!(UNVALID POSITION VALUE)"<<endl;
		exit(1);
	}
	else
		position=newPosition;
	
	if(newRectX<0||newRectY<0){
		cout<<"Program Aborted!(UNVALID COORD VALUE)"<<endl;
		exit(1);
	}
	else{
		rectX=newRectX;
		rectY=newRectY;
	}
	
	rotate=newRotate;
		
	return;
}

void rectangle::set(int newHeight,int newWidth){
	if(newHeight<=0){
		cout<<"Program Aborted!(UNVALID HEIGHT VALUE)"<<endl;
		exit(1);
	}
	else
		height=newHeight;
	
	if(newWidth<=0){
		cout<<"Program Aborted!(UNVALID WIDTH VALUE)"<<endl;
		exit(1);
	}
	else
		width=newWidth;
	return;
}

void rectangle::set(int newRotate){ rotate=newRotate; }

//this function draws the one small shape according to member variables
void rectangle::draw(ofstream& outputStream){
	if(position=='c'){
		outputStream<<R"(<svg version="1.1")"<<endl;//and then I print the svg code by shifting
		outputStream<<R"(baseProfile="full")"<<endl;
		outputStream<<R"(width=")"<<width<<R"(" height=")"<<height<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
		outputStream<<R"(<rect width="100%" height="100%" fill="red" />)"<<endl;
	}
	else if(position=='i'){
		outputStream<<R"(<rect x=")"<<rectX<<R"(" y=")"<<rectY<<R"(" width=")"<<width<<R"(" height=")"<<height<<R"(" fill="green" />)"<<endl;
	}
	
}


