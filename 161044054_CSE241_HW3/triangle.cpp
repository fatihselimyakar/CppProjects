#include"triangle.h"

double triangle::totalArea=0;
double triangle::totalPerimeter=0;

//For the get inputs from user in main(driver)
void triangle::input(){
	cout<<"Please enter the lateral: "<<endl;
	cin>>lateral;
	if(lateral<=0){
		cout<<"Program aborted!(UNVALID LATERAL)"<<endl;
		exit(1);
	}
	
	return;
}
void triangle::set(char newPosition){
	if(newPosition=='i'||newPosition=='c')
		position=newPosition;
	else{
		cout<<"Program aborted!(UNVALID POSITION)"<<endl;
		exit(1);
	}
}
void triangle::set(int newLateral,char newPosition,double newTriX,double newTriY,double newTri2X,double newTri2Y,double newTri3X,double newTri3Y,int newRotate){//POSX POSY Yİ EKLEMEK GEREKEBİLİR
	if(newLateral>0)
		lateral=newLateral;
	else{
		cout<<"Program aborted!(UNVALID LATERAL)"<<endl;
		exit(1);
	}
	
	if(newPosition=='i'||newPosition=='c')
		position=newPosition;
	else{
		cout<<"Program aborted!(UNVALID POSITION)"<<endl;
		exit(1);
	}
	
	if(newTriX>=0)
		triX=newTriX;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	/*if(newPos_x>=0)
		pos_x=newPos_x;
	else{
		cout<<"Program aborted!(UNVALID REFERENCE COORDINATE)"<<endl;
		exit(1);
	}
	
	if(newPos_y>=0)
		pos_y=newPos_y;
	else{
		cout<<"Program aborted!(UNVALID REFERENCE COORDINATE)"<<endl;
		exit(1);
	}*/
	
	if(newTriY>=0)
		triY=newTriY;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	if(newTri2X>=0)
		tri2X=newTri2X;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	if(newTri2Y>=0)
		tri2Y=newTri2Y;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	if(newTri3X>=0)
		tri3X=newTri3X;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	if(newTri3Y>=0)
		tri3Y=newTri3Y;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	rotate=newRotate;
	
	
		
	
	
	return;
}

void triangle::set(int newLateral,char newPosition,double newTriX,double newTriY,int newRotate){
	if(newLateral>0)
		lateral=newLateral;
	else{
		cout<<"Program aborted!(UNVALID LATERAL)"<<endl;
		exit(1);
	}
	
	if(newPosition=='i'||newPosition=='c')
		position=newPosition;
	else{
		cout<<"Program aborted!(UNVALID POSITION)"<<endl;
		exit(1);
	}
	
	if(newTriX>=0)
		triX=newTriX;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	if(newTriY>=0)
		triY=newTriY;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	rotate=newRotate;
	
	return;
}

void triangle::set(double newTriX,double newTriY){
	if(newTriX>=0)
		triX=newTriX;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	if(newTriY>=0)
		triY=newTriY;
	else{
		cout<<"Program aborted!(UNVALID COORDINATE)"<<endl;
		exit(1);
	}
	
	return;
}

//this functions draw the small triangle according to member variables
void triangle::draw(ofstream& outputStream,double pos_x,double pos_y){
	if(position=='c'){
		outputStream<<R"(<svg version="1.1")"<<endl;
		outputStream<<R"(baseProfile="full")"<<endl;
		outputStream<<R"(height=")"<<lateral<<R"(" width=")"<<lateral<<R"(" xmlns="http://www.w3.org/2000/svg">>
	<polygon points=")"<<lateral/2.0<<R"( 0 0 )"<<lateral*SQR3DIV2<<R"( )"<<lateral<<R"( )"<<lateral*SQR3DIV2<<R"(" fill="red" />)"<<endl;
	}
	else if(position=='i'){
		outputStream<<R"(<polygon points=")"<<triX<<R"( )"<<triY<<R"( )"<<tri2X<<R"( )"<<tri2Y<<R"( )"<<tri3X<<R"( )"<<tri3Y<<R"(" fill="green" transform="rotate()"<<rotate<<R"(,)"<<pos_x<<R"(,)"<<pos_y<<")\" />"<<endl;
	}
}

//Operator overloadings->This one prints the shape in svg file 
ostream& operator<<(ostream& outputStream,const triangle& shape){
	
	if(shape.position=='c'){
		outputStream<<R"(<svg version="1.1")"<<endl;
		outputStream<<R"(baseProfile="full")"<<endl;
		outputStream<<R"(height=")"<<shape.lateral<<R"(" width=")"<<shape.lateral<<R"(" xmlns="http://www.w3.org/2000/svg">>
	<polygon points=")"<<shape.lateral/2.0<<R"( 0 0 )"<<shape.lateral*SQR3DIV2<<R"( )"<<shape.lateral<<R"( )"<<shape.lateral*SQR3DIV2<<R"(" fill="red" />)"<<endl;
	}
	else if(shape.position=='i'){
		outputStream<<R"(<polygon points=")"<<shape.triX<<R"( )"<<shape.triY<<R"( )"<<shape.tri2X<<R"( )"<<shape.tri2Y<<R"( )"<<shape.tri3X<<R"( )"<<shape.tri3Y<<R"(" fill="green" transform="rotate()"<<shape.rotate<<R"(,)"<<shape.pos_x<<R"(,)"<<shape.pos_y<<")\" />"<<endl;
	}
	
	return outputStream;
}

//This overloading add 1 to the coordinates and returns(prefix)
triangle triangle::operator++(){
	triX=triX+1.;
	triY=triY+1.;
	tri2X=tri2X+1.;
	tri2Y=tri2Y+1.;
	tri3X=tri3X+1.;
	tri3Y=tri3Y+1.;
		
	return triangle(triX,triY,tri2X,tri2Y,tri3X,tri3Y);
}

//This overloading add 1 to the coordinates but unadded value returns(postfix)
triangle triangle::operator++(int ignoreMe){
	double temp1=triX,temp2=triY,temp3=tri2X,temp4=tri2Y,temp5=tri3X,temp6=tri3Y;
	triX=triX+1.;
	triY=triY+1.;
	tri2X=tri2X+1.;
	tri2Y=tri2Y+1.;
	tri3X=tri3X+1.;
	tri3Y=tri3Y+1.;
	
	return triangle(temp1,temp2,temp3,temp4,temp5,temp6);
}

//This overloading add minus 1 to the coordinates and returns(prefix)
triangle triangle::operator--(){
	triX=triX-1.;
	triY=triY-1.;
	tri2X=tri2X-1.;
	tri2Y=tri2Y-1.;
	tri3X=tri3X-1.;
	tri3Y=tri3Y-1.;
		
	return triangle(triX,triY,tri2X,tri2Y,tri3X,tri3Y);
}

//This overloading add minus 1 to the coordinates but unadded value returns(postfix)
triangle triangle::operator--(int ignoreMe){
	double temp1=triX,temp2=triY,temp3=tri2X,temp4=tri2Y,temp5=tri3X,temp6=tri3Y;
	triX=triX-1.;
	triY=triY-1.;
	tri2X=tri2X-1.;
	tri2Y=tri2Y-1.;
	tri3X=tri3X-1.;
	tri3Y=tri3Y-1.;
	
	return triangle(temp1,temp2,temp3,temp4,temp5,temp6);
}

//this overloading add "plus" lateral
const triangle triangle::operator+(double plus)const{
	double newLateral=lateral+plus;
	return triangle(newLateral,position,triX,triY,tri2X,tri2Y,tri3X,tri3Y,rotate,pos_x,pos_y);
}

//this overloading add "minus" lateral
const triangle triangle::operator-(double minus)const{
	double newLateral=lateral-minus;
	return triangle(newLateral,position,triX,triY,tri2X,tri2Y,tri3X,tri3Y,rotate,pos_x,pos_y);
}




