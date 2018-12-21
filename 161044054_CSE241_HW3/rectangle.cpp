#include"rectangle.h"
//for getting the input from user in driver(main) file
double rectangle::totalArea=0;
double rectangle::totalPerimeter=0;

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

//Operator overloadings->This one prints the shape in svg file 
ostream &operator<<(ostream& outputStream,const rectangle& shape){
	
	if(shape.position=='c'){
		outputStream<<R"(<svg version="1.1")"<<endl;//and then I print the svg code by shifting
		outputStream<<R"(baseProfile="full")"<<endl;
		outputStream<<R"(width=")"<<shape.getWidth()<<R"(" height=")"<<shape.getHeight()<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
		outputStream<<R"(<rect width="100%" height="100%" fill="red" />)"<<endl;
	}
	else if(shape.position=='i'){
		outputStream<<R"(<rect x=")"<<shape.getRectX()<<R"(" y=")"<<shape.getRectY()<<R"(" width=")"<<shape.getWidth()<<R"(" height=")"<<shape.getHeight()<<R"(" fill="green" />)"<<endl;
	}
	
	return outputStream;
}

//This overloading add 1 to the coordinates and returns(prefix)
rectangle rectangle::operator++(){
	rectX=rectX+1.;
	rectY=rectY+1.;
	
	return rectangle(rectX,rectY);
}

//This overloading add 1 to the coordinates but unadded value returns(postfix)
rectangle rectangle::operator++(int ignoreMe){
	double temp1=rectX;
	double temp2=rectY;
	rectX=rectX+1.;
	rectY=rectY+1.;
	
	return rectangle(temp1,temp2);
}

//This overloading add minus 1 to the coordinates and returns(prefix)
rectangle rectangle::operator--(){
	rectX=rectX-1.;
	rectY=rectY-1.;
	
	return rectangle(rectX,rectY);
}

//This overloading add minus 1 to the coordinates but unadded value returns(postfix)
rectangle rectangle::operator--(int ignoreMe){
	double temp1=rectX;
	double temp2=rectY;
	rectX=rectX-1.;
	rectY=rectY-1.;
	
	return rectangle(temp1,temp2);
}

//this overloading add "plus" width and height
const rectangle rectangle::operator+(const double plus)const{
	double newWidth=width+plus;
	double newHeight=height+plus;
	return rectangle(newHeight,newWidth,position,rectX,rectY,rotate);
}

//this overloading add "minus" width and height
const rectangle rectangle::operator-(const double minus)const{
	double newWidth=width-minus;
	double newHeight=height-minus;
	return rectangle(newHeight,newWidth,position,rectX,rectY,rotate);
}




