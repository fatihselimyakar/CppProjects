#include<iostream>
#include<fstream>

#define PI 3.14
#define SQR3 1.732//for sqrt3
#define SQR3DIV2 0.866//for sqrt3/2

using namespace std;

enum class shape{R,C,T};//I declared the new enum class for shape type 

struct shapeInfo{//This struct is necessary to implement a properties of shapes
	shape Shape;
	int width,height,radius,lateral;
};


void rectangleMeasure(int& width,int& height){//I get the value of rectangle measurement from user
	cout<<"Please enter the width."<<endl;
	cin>>width;
	cout<<"Please enter the height."<<endl;
	cin>>height;
	
	return;
}

void  circleMeasure(int& radius){//I get the value of circle measurement from user
	cout<<"Please enter the radius."<<endl;
	cin>>radius;
	
	return;
}

void  triangleMeasure(int& lateral){//I get the value of triangle measurement from user
	cout<<"Please enter the each lateral."<<endl;
	cin>>lateral;
	
	return;
}

void getInput(shapeInfo& container,shapeInfo& small){//I get whole information by the my wrote functions and then I add the my struct
	char cont,sml;
	
	cout<<"Please enter the main container shape (R, C, T)"<<endl;
	cin>>cont;
	
	if(cont=='R'){
		container.Shape=shape::R;
	}
	else if(cont=='C'){
		container.Shape=shape::C;
	}
	else if(cont=='T'){
		container.Shape=shape::T;
	}
	
	if(container.Shape==shape::R)
		rectangleMeasure(container.width,container.height);
	else if(container.Shape==shape::C)
		circleMeasure(container.radius);
	else if(container.Shape==shape::T)
		triangleMeasure(container.lateral);
	
	cout<<"Please enter the small shape (R, C, T)"<<endl;
	cin>>sml;
	
	if(sml=='R'){
		small.Shape=shape::R;
	}
	else if(sml=='C'){
		small.Shape=shape::C;
	}
	else if(sml=='T'){
		small.Shape=shape::T;
	}
	
	if(small.Shape==shape::R)
		rectangleMeasure(small.width,small.height);
	else if(small.Shape==shape::C)
		circleMeasure(small.radius);
	else if(small.Shape==shape::T)
		triangleMeasure(small.lateral);
	
	return;
}

void rectInRect(shapeInfo container,shapeInfo small){//If user enter the R and R the program calls this fuction
	ofstream outputStream;//I declared the file variable
	outputStream.open("output.svg");//I opened the my .svg file
	outputStream<<R"(<svg version="1.1")"<<endl;//and then I print the svg code by shifting
	outputStream<<R"(baseProfile="full")"<<endl;
	int normal,reverse,addForEmpty1,addForEmpty2,temp;
	if(small.width<small.height){//My program is runs the only when small.width>small.height.This ıf provides that. 
		temp=small.width;
		small.width=small.height;
		small.height=temp;
	}
	//The program runs two way the first is normal issue->align the width to width and height to height
	normal=(container.width/small.width)*(container.height/small.height);
	//second is width to height and height to width
	reverse=(container.height/small.width)*(container.width/small.height);
	
	//if there are spaces in big shape then adds the rotated rectangles for normal and reverse align
	addForEmpty1=(((container.width-((container.width/small.width)*small.width))/small.height)*(container.height/small.width));
	addForEmpty2=(((container.height-((container.height/small.width)*small.width))/small.height)*(container.width/small.width));
	
	//I calculated the total rectangle number
	normal=normal+addForEmpty1;
	reverse=reverse+addForEmpty2;

	if(normal>reverse){//This part is printing .svg file and print in datas in terminal
		cout<<"I can fit at most "<<normal<<" small shapes into the main container. The empty area (red) in container is .: "<<(container.width*container.height)-(normal*(small.width*small.height));
		int i,j,k,l;
		//this part prints the big one
		outputStream<<R"(width=")"<<container.width<<R"(" height=")"<<container.height<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
		outputStream<<R"(<rect width="100%" height="100%" fill="red" />)"<<endl;
		//this part prints normal rectangles
		for(i=0;i+small.width<=container.width;i=i+small.width){
			for(j=0;j+small.height<=container.height;j=j+small.height){
				outputStream<<R"(<rect x=")"<<i<<R"(" y=")"<<j<<R"(" width=")"<<small.width<<R"(" height=")"<<small.height<<R"(" fill="green" />)"<<endl;

			}
		}
		//this part prints added and rotated rectangles
		for(k=i;k+small.height<=container.width;k=k+small.height){
			for(l=0;l+small.width<=container.height;l=l+small.width){
				outputStream<<R"(<rect x=")"<<k<<R"(" y=")"<<l<<R"(" width=")"<<small.height<<R"(" height=")"<<small.width<<R"(" fill="green" />)"<<endl;
			}
		}


	}
	else{
		cout<<"I can fit at most "<<reverse<<" small shapes into the main container. The empty area (red) in container is .: "<<(container.width*container.height)-(reverse*(small.width*small.height));
		int i,j,k,l;
		//this part prints the big one
		outputStream<<R"(width=")"<<container.width<<R"(" height=")"<<container.height<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
		outputStream<<R"(<rect width="100%" height="100%" fill="red" />)"<<endl;
		//this part prints reverse rectangles
		for(i=0;i+small.height<=container.width;i=i+small.height){
			for(j=0;j+small.width<=container.height;j=j+small.width){
				outputStream<<R"(<rect x=")"<<i<<R"(" y=")"<<j<<R"(" width=")"<<small.height<<R"(" height=")"<<small.width<<R"(" fill="green" />)"<<endl;

			}
		}
		//this part prints added and rotated reverse rectangles
		for(k=0;k+small.width<=container.width;k=k+small.width){
			for(l=j;l+small.height<=container.height;l=l+small.height){
				outputStream<<R"(<rect x=")"<<k<<R"(" y=")"<<l<<R"(" width=")"<<small.width<<R"(" height=")"<<small.height<<R"(" fill="green" />)"<<endl;
			}
		}
	}
	outputStream<<"</svg>";
	outputStream.close();//I closed the my .svg file
	return;
}

void circInRect(shapeInfo container,shapeInfo small){// If the user select R and C this function runs
	ofstream outputStream;
	outputStream.open("output.svg");
	outputStream<<R"(<svg version="1.1")"<<endl;
	outputStream<<R"(baseProfile="full")"<<endl;
	//I calculate the circles in normal issue
	int nofCircle=(container.width/(2*small.radius))*(container.height/(2*small.radius));
	
	//this ones are for the exception
	double control_ex1=container.width-((container.width/(2*small.radius))*2*small.radius)+small.radius;
	double control_ex2=container.height-((container.height/(2*small.radius))*2*small.radius)+small.radius;
	double excause=small.radius*SQR3+small.radius;

	//this part controls the exception
	if((control_ex1<3*small.radius&&control_ex1>=excause)&&(control_ex2<3*small.radius&&control_ex2>=excause))
		nofCircle=nofCircle+(container.height/(2*small.radius)-1)+(container.width/(2*small.radius)-1)+1;
	else if(control_ex1<3*small.radius&&control_ex1>=excause)
		nofCircle=nofCircle+((container.height/(2*small.radius))-1);
	else if(control_ex2<3*small.radius&&control_ex2>=excause)
		nofCircle=nofCircle+((container.width/(2*small.radius))-1);
	
	//printing datas and graphics in .svg file and terminal
	cout<<"I can fit at most "<<nofCircle<<" small shapes into the main container. The empty area (red) in container is .: "<<(container.width*container.height)-nofCircle*(SQR3*(small.radius*small.radius));
	//This prints big one
	outputStream<<R"(width=")"<<container.width<<R"(" height=")"<<container.height<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
	outputStream<<R"(<rect width="100%" height="100%" fill="red" />)"<<endl;
	//This prints normal circles
	int i,j;
	for(i=small.radius;i+small.radius<=container.width;i=i+2*small.radius){
		for(j=small.radius;j+small.radius<=container.height;j=j+2*small.radius){
			outputStream<<R"(<circle cx=")"<<i<<R"(" cy=")"<<j<<R"(" r=")"<<small.radius<<R"(" fill="green" />)"<<endl;
		}
	}
	//for the printing exception issue
	if((control_ex1<3*small.radius&&control_ex1>=excause)&&(control_ex2<3*small.radius&&control_ex2>=excause)){

		int k,l;
		double m=2*small.radius;
		double n=(container.height/(2*small.radius))*2*small.radius+(SQR3DIV2*small.radius);
		for(k=0;k<(container.width/(2*small.radius));k++){
			outputStream<<R"(<circle cx=")"<<m<<R"(" cy=")"<<n<<R"(" r=")"<<small.radius<<R"(" fill="green" />)"<<endl;
			m=m+2*small.radius;
		}
		m=(container.width/(2*small.radius))*2*small.radius+(SQR3DIV2*small.radius);
		n=2*small.radius;
		for(l=1;l<(container.height/(2*small.radius));l++){
			outputStream<<R"(<circle cx=")"<<m<<R"(" cy=")"<<n<<R"(" r=")"<<small.radius<<R"(" fill="green" />)"<<endl;
			n=n+2*small.radius;
		}
	}
	else if(control_ex2<3*small.radius&&control_ex2>=excause){
		int k;
		double m=2*small.radius;
		double n=(container.height/(2*small.radius))*2*small.radius+(SQR3DIV2*small.radius);
		for(k=1;k<(container.width/(2*small.radius));k++){
			outputStream<<R"(<circle cx=")"<<m<<R"(" cy=")"<<n<<R"(" r=")"<<small.radius<<R"(" fill="green" />)"<<endl;
			m=m+2*small.radius;
		}
	}
	else if(control_ex1<3*small.radius&&control_ex1>=excause){
		int l;
		double m=(container.width/(2*small.radius))*2*small.radius+(SQR3DIV2*small.radius);
		double n=2*small.radius;
		for(l=1;l<(container.height/(2*small.radius));l++){
			outputStream<<R"(<circle cx=")"<<m<<R"(" cy=")"<<n<<R"(" r=")"<<small.radius<<R"(" fill="green" />)"<<endl;
			n=n+2*small.radius;
		}
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;
}

void triInRect(shapeInfo container,shapeInfo small){//If the user selects R and T this function runs 
	ofstream outputStream;
	outputStream.open("output.svg");
	outputStream<<R"(<svg version="1.1")"<<endl;
	outputStream<<R"(baseProfile="full")"<<endl;
	int normal,reverse,normalNofTriWidth,reverseNofTriHeight;

	//It calculates normal and reverse align calculates(on width and height)
	normalNofTriWidth=container.height/(SQR3DIV2*small.lateral);
	reverseNofTriHeight=container.width/(SQR3DIV2*small.lateral);

	//This parts includes exception issue's triangles
	if((container.width%small.lateral)>=(small.lateral/2))
		normal=(2*(container.width/small.lateral));
	else
		normal=(2*(container.width/small.lateral))-1;
	normal=normal*normalNofTriWidth;

	//This parts includes exception issue's triangles too for reverse
	if((container.height%small.lateral)>=(small.lateral/2))
		reverse=(2*(container.height/small.lateral));
	else
		reverse=(2*(container.height/small.lateral))-1;
	reverse=reverse*reverseNofTriHeight;

	//Printing normal align triangles
	if(normal>reverse){
		cout<<"I can fit at most "<<normal<<" small shapes into the main container. The empty area (red) in container is .: "<<(container.width*container.height)-(normal*((small.lateral*small.lateral*SQR3)/4));
		//this prints the big shape
		outputStream<<R"(width=")"<<container.width<<R"(" height=")"<<container.height<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
		outputStream<<R"(<rect width="100%" height="100%" fill="red" />)"<<endl;
		//prints normal type triangle
		double i,j;
		for(j=0;j+(SQR3*(small.lateral/2.0))<=container.height;j=j+(SQR3*(small.lateral/2.0))){
			for(i=0;i+small.lateral<=container.width;i=i+small.lateral){
				outputStream<<R"(<polygon points=")"<<i<<R"( )"<<j<<R"( )"<<small.lateral+i<<R"( )"<<j<<R"( )"<<(small.lateral/2.0)+i<<R"( )"<<SQR3*(small.lateral/2.0)+j<<R"(" fill="green" />)"<<endl;
			}
		}
		//prints reverse type triangle
		double k,l;
		for(l=(SQR3*(small.lateral/2.0));l<=container.height;l=l+(SQR3*(small.lateral/2.0))){
			for(k=small.lateral/2.0;k+small.lateral<=container.width;k=k+small.lateral){
				outputStream<<R"(<polygon points=")"<<k<<R"( )"<<l<<R"( )"<<small.lateral/2.0+k<<R"( )"<<l-(SQR3*(small.lateral/2.0))<<R"( )"<<small.lateral+k<<R"( )"<<l<<R"(" fill="green" />)"<<endl;
			}
		}

	}
	//Printing reverse align triangles
	else{
		cout<<"I can fit at most "<<reverse<<" small shapes into the main container. The empty area (red) in container is .: "<<(container.width*container.height)-(reverse*((small.lateral*small.lateral*SQR3)/4));
		//this prints the big shape
		outputStream<<R"(width=")"<<container.width<<R"(" height=")"<<container.height<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
		outputStream<<R"(<rect width="100%" height="100%" fill="red" />)"<<endl;
		//prints reverse type triangle
		double i,j;
		for(i=0;i+(SQR3*(small.lateral/2.0))<=container.width;i=i+(SQR3*(small.lateral/2.0))){
			for(j=0;j+small.lateral<=container.height;j=j+small.lateral){
				outputStream<<R"(<polygon points=")"<<i<<R"( )"<<j<<R"( )"<<i<<R"( )"<<j+small.lateral<<R"( )"<<SQR3*(small.lateral/2.0)+i<<R"( )"<<(small.lateral/2.0)+j<<R"(" fill="green" />)"<<endl;
			}
		}
		//prints normal type triangle
		double k,l;
		for(l=(small.lateral/2.0);l+small.lateral<=container.height;l=l+small.lateral){
			for(k=(SQR3*(small.lateral/2.0));k<=container.width;k=k+(SQR3*(small.lateral/2.0))){
				outputStream<<R"(<polygon points=")"<<k<<R"( )"<<l<<R"( )"<<k-(SQR3*(small.lateral/2.0))<<R"( )"<<small.lateral/2.0+l<<R"( )"<<k<<R"( )"<<small.lateral+l<<R"(" fill="green" />)"<<endl;
			}
		}
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;
}

void triInTri(shapeInfo container,shapeInfo small){//If the user select T and T this function calls
	ofstream outputStream;
	outputStream.open("output.svg");
	outputStream<<R"(<svg version="1.1")"<<endl;
	outputStream<<R"(baseProfile="full")"<<endl;
	int target=container.lateral/small.lateral;
	int counter=1,i,total=0;
	
	//I used similarity rule for triangles
	for(i=1;i<=target;i++){
		total=total+counter;
		counter=counter+2;
	}
	
	cout<<"I can fit at most "<<total<<" small shapes into the main container. The empty area (red) in container is .: "<<static_cast<double>(container.lateral*container.lateral*/*sqrt3*/SQR3)/4.-(total*((static_cast<double>(small.lateral*small.lateral)*SQR3)/4.));


	//PRINTING TRIANGLE IN TRIANGLE
	outputStream<<R"(height=")"<<container.lateral<<R"(" width=")"<<container.lateral<<R"(" xmlns="http://www.w3.org/2000/svg">>
	<polygon points=")"<<container.lateral/2.0<<R"( 0 0 )"<<container.lateral*SQR3DIV2<<R"( )"<<container.lateral<<R"( )"<<container.lateral*SQR3DIV2<<R"(" fill="red" />)"<<endl;
	//It calculates the number of triangle along the h
	int nOfTri=container.lateral/small.lateral;
	int plus;
	//the starting coordinates
	double x=container.lateral/2.0,y=0;
	int k,l,m=1;
	for(k=nOfTri;k>0;k--){
		plus=0;
		for(l=0;l<m;l++,plus=plus+small.lateral){
			//prints normal triangles
			outputStream<<R"(<polygon points=")"<<x+plus<<R"( )"<<y<<R"( )"<<x+small.lateral/2.0+plus<<R"( )"<<y+(small.lateral*SQR3DIV2)<<R"( )"<<(x-small.lateral/2.0)+plus<<R"( )"<<y+(small.lateral*SQR3DIV2)<<R"(" fill="green" />)"<<endl;	
			//for the reverse type triangle's and the if is need to last line
			if(k!=1)
				outputStream<<R"(<polygon points=")"<<x+plus<<R"( )"<<y+(2*small.lateral*SQR3DIV2)<<R"( )"<<x+small.lateral/2.0+plus<<R"( )"<<y+(small.lateral*SQR3DIV2)<<R"( )"<<(x-small.lateral/2.0)+plus<<R"( )"<<y+(small.lateral*SQR3DIV2)<<R"(" fill="green" />)"<<endl;
		}
		m=m+1;
		x=x-small.lateral/2.0;//updating x coordinates
		y=y+small.lateral*SQR3DIV2;//updating y coordinates
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;
}

void rectInTri(shapeInfo container,shapeInfo small){//If the user selects T and R this function calls
	ofstream outputStream;
	outputStream.open("output.svg");
	outputStream<<R"(<svg version="1.1")"<<endl;
	outputStream<<R"(baseProfile="full")"<<endl;
	//calculates for the two issues->width to lateral and height to lateral
	double NormalSide=container.lateral-2*(small.height/SQR3);
	double ReverseSide=container.lateral-2*(small.width/SQR3);
	//It calculates the number of triangle along the h
	int hNo=((SQR3DIV2*container.lateral)-(small.width*SQR3DIV2))/small.height;
	int hRe=((SQR3DIV2*container.lateral)-(small.height*SQR3DIV2))/small.width;
	//line by line calculating for normal align
	int i,j,normal=0,reverse=0;
	for(i=hNo;i>0;i--){
		normal=normal+NormalSide/small.width;
		if(NormalSide>0)
			NormalSide=NormalSide-2*(small.height/SQR3);
	}
	//line by line calculating for reverse align
	for(j=hRe;j>0;j--){
		reverse=reverse+ReverseSide/small.height;
		if(ReverseSide>0)
			ReverseSide=ReverseSide-2*(small.width/SQR3);
	}
	//printing the .svg files
	outputStream<<R"(height=")"<<container.lateral<<R"(" width=")"<<container.lateral<<R"(" xmlns="http://www.w3.org/2000/svg">>
	<polygon points=")"<<container.lateral/2.0<<R"( 0 0 )"<<container.lateral*SQR3DIV2<<R"( )"<<container.lateral<<R"( )"<<container.lateral*SQR3DIV2<<R"(" fill="red" />)"<<endl;

	if(normal>reverse){//for width to lateral and height to h(normal align)
		cout<<"I can fit at most "<<normal<<" small shapes into the main container. The empty area (red) in container is .: "<<(container.lateral*container.lateral*SQR3)/4.0-normal*small.width*small.height;
		//for the updating x coordinates
		int plus=small.width;
		//the starting coordinates
		double x=small.height/SQR3,y=(container.lateral*SQR3DIV2)-small.height;
		int k,l;
		//the clear-cut h for dividing
		double m=container.lateral-2*(small.height/SQR3);
		for(k=hNo;k>0;k--){
			plus=0;
			for(l=m/small.width;l>0;l--,plus=plus+small.width){
				outputStream<<R"(<rect x=")"<<x+plus<<R"(" y=")"<<y<<R"(" width=")"<<small.width<<R"(" height=")"<<small.height<<R"(" fill="green" />)"<<endl;

			}
			//updatings for coordinates and loop's data
			m=m-2*(small.height/SQR3);
			x=x+small.height/SQR3;
			y=y-small.height;
		}

	}
	else{//for height to lateral and width to h(reverse align)
		cout<<"I can fit at most "<<reverse<<" small shapes into the main container. The empty area (red) in container is .: "<<(container.lateral*container.lateral*SQR3)/4.0-reverse*small.width*small.height;
		int plus=small.height;
		double x=small.width/SQR3,y=(container.lateral*SQR3DIV2)-small.width;
		int k,l;
		double m=(container.lateral-2*(small.width/SQR3));
		for(k=hRe;k>0;k--){
			plus=0;
			for(l=m/small.height;l>0;l--,plus=plus+small.height){
				outputStream<<R"(<rect x=")"<<x+plus<<R"(" y=")"<<y<<R"(" width=")"<<small.height<<R"(" height=")"<<small.width<<R"(" fill="green" />)"<<endl;

			}
			m=m-2*(small.width/SQR3);
			x=x+small.width/SQR3;
			y=y-small.width;
		}

	}
	outputStream<<"</svg>";
	outputStream.close();
	return;
}

void circInTri(shapeInfo container,shapeInfo small){//The user select T and c then this function runs
	ofstream outputStream;
	outputStream.open("output.svg");
	outputStream<<R"(<svg version="1.1")"<<endl;
	outputStream<<R"(baseProfile="full")"<<endl;
	//side is the max number of circle fill the line
	double side=container.lateral-2*(small.radius/SQR3)-(2*small.radius/SQR3)+small.radius;
	//net height of rectangle
	int h=((SQR3DIV2*container.lateral)-small.radius)/(2*small.radius);
	//I calculate the total circle number
	int i,sum=0;
	for(i=h;i>0;i--){
		sum=sum+side/(2*small.radius);
		if(side>0)
			side=side-(4*small.radius/SQR3);
	}
	cout<<"I can fit at most "<<sum<<" small shapes into the main container. The empty area (red) in container is .: "<<(container.lateral*container.lateral*SQR3)/4.-(sum*PI*small.radius*small.radius);

	outputStream<<R"(height=")"<<container.lateral<<R"(" width=")"<<container.lateral<<R"(" xmlns="http://www.w3.org/2000/svg">>
	<polygon points=")"<<container.lateral/2.0<<R"( 0 0 )"<<container.lateral*SQR3DIV2<<R"( )"<<container.lateral<<R"( )"<<container.lateral*SQR3DIV2<<R"(" fill="red" />)"<<endl;
	
	//the first updating value
	double plus=2*small.radius;
	//coordinates
	double x=3*small.radius/SQR3,y=(container.lateral*SQR3DIV2)-small.radius;
	int k,l;
	//m is the max number of circle fill the line
	double m=container.lateral-2*(small.radius/SQR3)-(2*small.radius/SQR3)+small.radius;
	for(k=h;k>0;k--){
		plus=0;
		for(l=m/(2*small.radius);l>0;l--,plus=plus+2*small.radius){
			outputStream<<R"(<circle cx=")"<<x+plus<<R"(" cy=")"<<y<<R"(" r=")"<<small.radius<<R"(" fill="green" />)"<<endl;

		}
		//updates
		m=m-4*(small.radius/SQR3);
		x=x+2*(small.radius/SQR3);
		y=y-2*small.radius;
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;
}

void triInCirc(shapeInfo container,shapeInfo small){//The user select C and T then this function runs
	//In this function I used the equalateral triangle's loop and multiplication to 6
	ofstream outputStream;
	outputStream.open("output.svg");
	//In this function I fill the regular equalateral triangle in circle and rotate it loop
	int target=container.radius/small.lateral;
	int counter=1,i,total=0;
	for(i=1;i<=target;i++){
		total=total+counter;
		counter=counter+2;
	}
	total=6*total;//360 degree/60 degree
	
	cout<<"I can fit at most "<<total<<" small shapes into the main container. The empty area (red) in container is .: "<<(PI*container.radius*container.radius)-total*((small.lateral*small.lateral*SQR3)/4.);
	
	outputStream<<R"(<svg viewBox="0 0 )"<<2*container.radius<<R"( )"<<2*container.radius<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
	outputStream<<R"(<circle cx=")"<<container.radius<<R"(" cy=")"<<container.radius<<R"(" r=")"<<container.radius<<R"(" fill="red" />)"<<endl;
	
	int nOfTri=container.radius/small.lateral;
	//x's adds
	int plus;
	//coordinates
	double x=container.radius,y=container.radius;
	int k,l,m=1;
	for(k=nOfTri;k>0;k--){
		plus=0;
		for(l=0;l<m;l++,plus=plus+small.lateral){
			int rotate;
			//this loop for the normal align triangle
			for(rotate=0;rotate<360;rotate=rotate+60){
				outputStream<<R"(<polygon points=")"<<x+plus<<R"( )"<<y<<R"( )"<<x+small.lateral/2.0+plus<<R"( )"<<y+(small.lateral*SQR3DIV2)<<R"( )"<<(x-small.lateral/2.0)+plus<<R"( )"<<y+(small.lateral*SQR3DIV2)<<R"(" fill="green" transform="rotate()"<<rotate<<R"(,)"<<container.radius<<R"(,)"<<container.radius<<")\" />"<<endl;
			}
			//this loop for the reverse align triangle
			if(k!=1){
				int rotate2;
				for(rotate2=0;rotate2<360;rotate2=rotate2+60){
					outputStream<<R"(<polygon points=")"<<x+plus<<R"( )"<<y+(2*small.lateral*SQR3DIV2)<<R"( )"<<x+small.lateral/2.0+plus<<R"( )"<<y+(small.lateral*SQR3DIV2)<<R"( )"<<(x-small.lateral/2.0)+plus<<R"( )"<<y+(small.lateral*SQR3DIV2)<<R"(" fill="green" transform="rotate()"<<rotate2<<R"(,)"<<container.radius<<R"(,)"<<container.radius<<")\" />"<<endl;
				}
			}
		}
		//Updates
		m=m+1;
		x=x-small.lateral/2.0;
		y=y+small.lateral*SQR3DIV2;
	}
	
	
	outputStream<<"</svg>";
	outputStream.close();
	return;
	
}

void circInCirc(shapeInfo container,shapeInfo small){//The user select C and C then this function runs
	ofstream outputStream;
	outputStream.open("output.svg");
	//In this function I used the equalateral triangle's loop and multiplication to 6
	int nOfCircle;
	int total=0;
	for(nOfCircle=((container.radius-small.radius)/(2*small.radius))+1;nOfCircle>1;nOfCircle--){
		total=total+nOfCircle;
	}
	//for there is no circle issue
	if(container.radius>small.radius)
		total=(3*total)+(3*(total/2-1))+1;
	
	cout<<"I can fit at most "<<total<<" small shapes into the main container. The empty area (red) in container is .: "<<(PI*container.radius*container.radius)-total*(PI*small.radius*small.radius);
	
	outputStream<<R"(<svg viewBox="0 0 )"<<2*container.radius<<R"( )"<<2*container.radius<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
	outputStream<<R"(<circle cx=")"<<container.radius<<R"(" cy=")"<<container.radius<<R"(" r=")"<<container.radius<<R"(" fill="red" />)"<<endl;
	//for there is no circle issue
	if(container.radius>small.radius)
		//the centerlock circle
		outputStream<<R"(<circle cx=")"<<container.radius<<R"(" cy=")"<<container.radius<<R"(" r=")"<<small.radius<<R"(" fill="green" />)"<<endl;
	
	//number of vertical circle
	int nOfVertCircle=(container.radius-small.radius)/(2*small.radius)+1;
	int plus;
	double x=container.radius,y=container.radius;
	int k,l,m=1;
	//the triangle h's
	for(k=nOfVertCircle;k>0;k--){
		plus=0;
		// the triangle line's
		for(l=1;l<m;l++,plus=plus+2*small.radius){
			int rotate;
			//this loop is rotate to circle center
			for(rotate=0;rotate<360;rotate=rotate+60){
				outputStream<<R"(<circle cx=")"<<x+plus<<R"(" cy=")"<<y<<R"(" r=")"<<small.radius<<R"(" fill="green" transform="rotate()"<<rotate<<R"(,)"<<container.radius<<R"(,)"<<container.radius<<")\" />"<<endl;
			}
		}
		// updates
		m=m+1;
		x=x-small.radius;
		y=y+small.radius*SQR3;
	}
	
	
	outputStream<<"</svg>";
	outputStream.close();
	return;
}

void recInCirc(shapeInfo container, shapeInfo small){//The user select C and R then this function runs
	//In this function I used rectangle in rectangle(especially square) loop and fitted the circle
	ofstream outputStream;
	outputStream.open("output.svg");
	
	int squareWidth=(2*container.radius)/1.414;
	
	int nofRect,addForEmpty1,addForEmpty2,temp;
	
	nofRect=(squareWidth/small.width)*(squareWidth/small.height);
	addForEmpty1=(((squareWidth-((squareWidth/small.width)*small.width))/small.height)*(squareWidth/small.width));
	nofRect=nofRect+addForEmpty1;

	
	cout<<"I can fit at most "<<nofRect<<" small shapes into the main container. The empty area (red) in container is .: "<<(PI*container.radius*container.radius)-(nofRect*(small.width*small.height));
	/*PRINTING SVG*/
	int i,j,k,l;
	outputStream<<R"(<svg viewBox="0 0 )"<<2*container.radius<<R"( )"<<2*container.radius<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;
	outputStream<<R"(<circle cx=")"<<container.radius<<R"(" cy=")"<<container.radius<<R"(" r=")"<<container.radius<<R"(" fill="red" />)"<<endl;

	for(i=0;i+small.width<=squareWidth;i=i+small.width){
		for(j=0;j+small.height<=squareWidth;j=j+small.height){
			outputStream<<R"(<rect x=")"<<i+(container.radius-squareWidth/2.)<<R"(" y=")"<<j+(container.radius-squareWidth/2.)<<R"(" width=")"<<small.width<<R"(" height=")"<<small.height<<R"(" fill="green" />)"<<endl;

		}
	}
	for(k=i;k+small.height<=squareWidth;k=k+small.height){
		for(l=0;l+small.width<=squareWidth;l=l+small.width){
			outputStream<<R"(<rect x=")"<<k+(container.radius-squareWidth/2.)<<R"(" y=")"<<l+(container.radius-squareWidth/2.)<<R"(" width=")"<<small.height<<R"(" height=")"<<small.width<<R"(" fill="green" />)"<<endl;
		}
	}
	
	outputStream<<"</svg>";
	outputStream.close();
	return;
}


void calcAndDraw(shapeInfo container,shapeInfo small){//This function is for the select and calls functions different issues
	/*IF CONTAINER IS RECTANGLE*/
	if(container.Shape==shape::R){
		if(small.Shape==shape::R){//RECT IN RECT
			rectInRect(container,small);
		}
		
		else if(small.Shape==shape::C){//RECT IN CIRCLE
			
			circInRect(container,small);
		}
		
		else if(small.Shape==shape::T){//RECT IN TRIANGLE
			triInRect(container,small);	
		}
	}
	/*IF CONTAINER IS TRIANGLE*/
	else if(container.Shape==shape::T){
		if(small.Shape==shape::T){//TRIANGLE IN TRIANGLE
			
			triInTri(container,small);
			
		}
		else if(small.Shape==shape::R){//RECTANGLE IN TRIANGLE
			
			rectInTri(container,small);
			
		}
		else if(small.Shape==shape::C){//CIRCLE IN TRIANGLE
			
			circInTri(container,small);
		
		}
	}
	/*IF CONTAINER IS CIRCLE*/
	else if(container.Shape==shape::C){
		if(small.Shape==shape::T){//TRIANGLE IN CIRCLE
			
			triInCirc(container,small);
			
		}
		else if(small.Shape==shape::C){//CIRCLE IN CIRCLE
			
			circInCirc(container,small);
		
		}
		else if(small.Shape==shape::R){//RECTANGLE IN CIRCLE
			
			recInCirc(container,small);
		
		}
	}
	return;
}
