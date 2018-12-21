#include"triangle.h"
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
void triangle::set(int newLateral,char newPosition,double newTriX,double newTriY,double newTri2X,double newTri2Y,double newTri3X,double newTri3Y,int newRotate){
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





