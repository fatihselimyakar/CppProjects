#include"ComposedShape.h"

void ComposedShape::optimalFit(triangle Co,triangle In){
	int nOfTri=Co.getLateral()/In.getLateral();
	int plus;
	//the starting coordinates
	double x=Co.getLateral()/2.0,y=0;
	int k,l,m=1;
	for(k=nOfTri;k>0;k--){
		plus=0;
		for(l=0;l<m;l++,plus=plus+In.getLateral()){
			//prints normal triangles
			//generate the one small shape and saves the vector
			triangle normal(In.getLateral(),'i',x+plus,y,x+In.getLateral()/2.0+plus,y+(In.getLateral()*SQR3DIV2),x-(In.getLateral()/2.0)+plus,y+(In.getLateral()*SQR3DIV2),0);
			tri.push_back(normal);
			//for the reverse type triangle's and the if is need to last line
			if(k!=1){
				//set the one small shape and saves the vector
				normal.set(In.getLateral(),'i',x+plus,y+(2*In.getLateral()*SQR3DIV2),x+In.getLateral()/2.0+plus,y+(In.getLateral()*SQR3DIV2),x-(In.getLateral()/2.0)+plus,y+(In.getLateral()*SQR3DIV2),0);
				tri.push_back(normal);
			}
				
		}
		m=m+1;
		x=x-In.getLateral()/2.0;//updating x coordinates
		y=y+In.getLateral()*SQR3DIV2;//updating y coordinates
	}
	return;
}
void ComposedShape::optimalFit(triangle Co,rectangle In){
	//calculates for the two issues->width to lateral and height to lateral
	double NormalSide=Co.getLateral()-2*(In.getHeight()/SQR3);
	double ReverseSide=Co.getLateral()-2*(In.getWidth()/SQR3);
	//It calculates the number of triangle along the h
	int hNo=((SQR3DIV2*Co.getLateral())-(In.getWidth()*SQR3DIV2))/In.getHeight();
	int hRe=((SQR3DIV2*Co.getLateral())-(In.getHeight()*SQR3DIV2))/In.getWidth();
	//line by line calculating for normal align
	int i,j,normal=0,reverse=0;
	for(i=hNo;i>0;i--){
		normal=normal+NormalSide/In.getWidth();
		if(NormalSide>0)
			NormalSide=NormalSide-2*(In.getHeight()/SQR3);
	}
	//line by line calculating for reverse align
	for(j=hRe;j>0;j--){
		reverse=reverse+ReverseSide/In.getHeight();
		if(ReverseSide>0)
			ReverseSide=ReverseSide-2*(In.getWidth()/SQR3);
	}
	//printing the .svg files

	if(normal>reverse){//for width to lateral and height to h(normal align)
		//for the updating x coordinates
		int plus=In.getWidth();
		//the starting coordinates
		double x=In.getHeight()/SQR3,y=(Co.getLateral()*SQR3DIV2)-In.getHeight();
		int k,l;
		//the clear-cut h for dividing
		double m=Co.getLateral()-2*(In.getHeight()/SQR3);
		for(k=hNo;k>0;k--){
			plus=0;
			for(l=m/In.getWidth();l>0;l--,plus=plus+In.getWidth()){
				//generate the one small shape and saves the vector
				rectangle drawRec(In.getHeight(),In.getWidth(),'i',x+plus,y,0);
				rec.push_back(drawRec);

			}
			//updatings for coordinates and loop's data
			m=m-2*(In.getHeight()/SQR3);
			x=x+In.getHeight()/SQR3;
			y=y-In.getHeight();
		}

	}
	else{//for height to lateral and width to h(reverse align)
		int plus=In.getHeight();
		double x=In.getWidth()/SQR3,y=(Co.getLateral()*SQR3DIV2)-In.getWidth();
		int k,l;
		double m=(Co.getLateral()-2*(In.getWidth()/SQR3));
		for(k=hRe;k>0;k--){
			plus=0;
			for(l=m/In.getHeight();l>0;l--,plus=plus+In.getHeight()){
				//generate the one small shape and saves the vector
				rectangle drawRec(In.getWidth(),In.getHeight(),'i',x+plus,y,0);
				rec.push_back(drawRec);
			}
			m=m-2*(In.getWidth()/SQR3);
			x=x+In.getWidth()/SQR3;
			y=y-In.getWidth();
		}

	}
	return;
}
void ComposedShape::optimalFit(triangle Co,circle In){
	//side is the max number of circle fill the line
	double side=Co.getLateral()-2*(In.getRadius()/SQR3)-(2*In.getRadius()/SQR3)+In.getRadius();
	//net height of rectangle
	int h=((SQR3DIV2*Co.getLateral())-In.getRadius())/(2*In.getRadius());
	//I calculate the total circle number
	int i,sum=0;
	for(i=h;i>0;i--){
		sum=sum+side/(2*In.getRadius());
		if(side>0)
			side=side-(4*In.getRadius()/SQR3);
	}
	//the first updating value
	double plus=2*In.getRadius();
	//coordinates
	double x=3*In.getRadius()/SQR3,y=(Co.getLateral()*SQR3DIV2)-In.getRadius();
	int k,l;
	//m is the max number of circle fill the line
	double m=Co.getLateral()-2*(In.getRadius()/SQR3)-(2*In.getRadius()/SQR3)+In.getRadius();
	for(k=h;k>0;k--){
		plus=0;
		for(l=m/(2*In.getRadius());l>0;l--,plus=plus+2*In.getRadius()){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',x+plus,y,0);
			circ.push_back(drawCirc);
		}
		//updates
		m=m-4*(In.getRadius()/SQR3);
		x=x+2*(In.getRadius()/SQR3);
		y=y-2*In.getRadius();
	}
	return;
}
void ComposedShape::optimalFit(rectangle Co,triangle In){
	int normal,reverse,normalNofTriWidth,reverseNofTriHeight;

	//It calculates normal and reverse align calculates(on width and height)
	normalNofTriWidth=Co.getHeight()/(SQR3DIV2*In.getLateral());
	reverseNofTriHeight=Co.getWidth()/(SQR3DIV2*In.getLateral());

	//This parts includes exception issue's triangles
	if((Co.getWidth()%In.getLateral())>=(In.getLateral()/2))
		normal=(2*(Co.getWidth()/In.getLateral()));
	else
		normal=(2*(Co.getWidth()/In.getLateral()))-1;
	normal=normal*normalNofTriWidth;

	//This parts includes exception issue's triangles too for reverse
	if((Co.getHeight()%In.getLateral())>=(In.getLateral()/2))
		reverse=(2*(Co.getHeight()/In.getLateral()));
	else
		reverse=(2*(Co.getHeight()/In.getLateral()))-1;
	reverse=reverse*reverseNofTriHeight;

	//Printing normal align triangles
	if(normal>reverse){
		double i,j;
		for(j=0;j+(SQR3*(In.getLateral()/2.0))<=Co.getHeight();j=j+(SQR3*(In.getLateral()/2.0))){
			for(i=0;i+In.getLateral()<=Co.getWidth();i=i+In.getLateral()){
				//generate the one small shape and saves the vector
				triangle normal(In.getLateral(),'i',i,j,In.getLateral()+i,j,(In.getLateral()/2.0)+i,SQR3*(In.getLateral()/2.0)+j,0);
				tri.push_back(normal);
			}
		}
		//prints reverse type triangle
		double k,l;
		for(l=(SQR3*(In.getLateral()/2.0));l<=Co.getHeight();l=l+(SQR3*(In.getLateral()/2.0))){
			for(k=In.getLateral()/2.0;k+In.getLateral()<=Co.getWidth();k=k+In.getLateral()){
				//generate the one small shape and saves the vector
				triangle normal(In.getLateral(),'i',k,l,In.getLateral()/2.0+k,l-(SQR3*(In.getLateral()/2.0)),In.getLateral()+k,l,0);
				tri.push_back(normal);
			}
		}

	}
	//Printing reverse align triangles
	else{
		//prints reverse type triangle
		double i,j;
		for(i=0;i+(SQR3*(In.getLateral()/2.0))<=Co.getWidth();i=i+(SQR3*(In.getLateral()/2.0))){
			for(j=0;j+In.getLateral()<=Co.getHeight();j=j+In.getLateral()){		
				//generate the one small shape and saves the vector
				triangle normal(In.getLateral(),'i',i,j,i,j+In.getLateral(),SQR3*(In.getLateral()/2.0)+i,(In.getLateral()/2.0)+j,0);
				tri.push_back(normal);
			}
		}
		//prints normal type triangle
		double k,l;
		for(l=(In.getLateral()/2.0);l+In.getLateral()<=Co.getHeight();l=l+In.getLateral()){
			for(k=(SQR3*(In.getLateral()/2.0));k<=Co.getWidth();k=k+(SQR3*(In.getLateral()/2.0))){				
				//generate the one small shape and saves the vector
				triangle normal(In.getLateral(),'i',k,l,k-(SQR3*(In.getLateral()/2.0)),In.getLateral()/2.0+l,k,In.getLateral()+l,0);
				tri.push_back(normal);
			}
		}
	}
	return;
}
void ComposedShape::optimalFit(rectangle Co,rectangle In){
	int normal,reverse,addForEmpty1,addForEmpty2,temp;
	int smallwidth=In.getWidth();
	int smallheight=In.getHeight();
	if(smallwidth<smallheight){//My program is runs the only when small.width>small.height.This ıf provides that. 
		temp=smallwidth;
		smallwidth=smallheight;
		smallheight=temp;
	}
	//The program runs two way the first is normal issue->align the width to width and height to height
	normal=(Co.getWidth()/smallwidth)*(Co.getHeight()/smallheight);
	//second is width to height and height to width
	reverse=(Co.getHeight()/smallwidth)*(Co.getWidth()/smallheight);
	
	//if there are spaces in big shape then adds the rotated rectangles for normal and reverse align
	addForEmpty1=(((Co.getWidth()-((Co.getWidth()/smallwidth)*smallwidth))/smallheight)*(Co.getHeight()/smallwidth));
	addForEmpty2=(((Co.getHeight()-((Co.getHeight()/smallwidth)*smallwidth))/smallheight)*(Co.getWidth()/smallwidth));
	
	//I calculated the total rectangle number
	normal=normal+addForEmpty1;
	reverse=reverse+addForEmpty2;

	if(normal>reverse){//This part is printing .svg file and print in datas in terminal
		int i,j,k,l;
		for(i=0;i+smallwidth<=Co.getWidth();i=i+smallheight){
			for(j=0;j+smallheight<=Co.getHeight();j=j+smallheight){
				//generate the one small shape and saves the vector
				rectangle normal(smallheight,smallwidth,'i',i,j,0);
				rec.push_back(normal);
			}
		}
		//this part prints added and rotated rectangles
		for(k=i;k+smallheight<=Co.getWidth();k=k+smallheight){
			for(l=0;l+smallwidth<=Co.getHeight();l=l+smallwidth){
				//generate the one small shape and saves the vector
				rectangle normal2(smallwidth,smallheight,'i',k,l,0);
				rec.push_back(normal2);
			}
		}


	}
	else{
		int i,j,k,l;
		for(i=0;i+smallheight<=Co.getWidth();i=i+smallheight){
			for(j=0;j+smallwidth<=Co.getHeight();j=j+smallwidth){
				//generate the one small shape and saves the vector
				rectangle reverse(smallwidth,smallheight,'i',i,j,0);
				rec.push_back(reverse);

			}
		}
		//this part prints added and rotated reverse rectangles
		for(k=0;k+smallwidth<=Co.getWidth();k=k+smallwidth){
			for(l=j;l+smallheight<=Co.getHeight();l=l+smallheight){
				//generate the one small shape and saves the vector
				rectangle reverse2(smallheight,smallwidth,'i',k,l,0);
				rec.push_back(reverse2);
			}
		}
	}
	return;
}
void ComposedShape::optimalFit(rectangle Co,circle In){
	ofstream outputStream;
	//I calculate the circles in normal issue
	int nofCircle=(Co.getWidth()/(2*In.getRadius()))*(Co.getHeight()/(2*In.getRadius()));
	
	//this ones are for the exception
	double control_ex1=Co.getWidth()-((Co.getWidth()/(2*In.getRadius()))*2*In.getRadius())+In.getRadius();
	double control_ex2=Co.getHeight()-((Co.getHeight()/(2*In.getRadius()))*2*In.getRadius())+In.getRadius();
	double excause=In.getRadius()*SQR3+In.getRadius();

	//this part controls the exception
	if((control_ex1<3*In.getRadius()&&control_ex1>=excause)&&(control_ex2<3*In.getRadius()&&control_ex2>=excause))
		nofCircle=nofCircle+(Co.getHeight()/(2*In.getRadius())-1)+(Co.getWidth()/(2*In.getRadius())-1)+1;
	else if(control_ex1<3*In.getRadius()&&control_ex1>=excause)
		nofCircle=nofCircle+((Co.getHeight()/(2*In.getRadius()))-1);
	else if(control_ex2<3*In.getRadius()&&control_ex2>=excause)
		nofCircle=nofCircle+((Co.getWidth()/(2*In.getRadius()))-1);

	int i,j;
	for(i=In.getRadius();i+In.getRadius()<=Co.getWidth();i=i+2*In.getRadius()){
		for(j=In.getRadius();j+In.getRadius()<=Co.getHeight();j=j+2*In.getRadius()){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',i,j,0);
			circ.push_back(drawCirc);
		}
	}
	//for the printing exception issue
	if((control_ex1<3*In.getRadius()&&control_ex1>=excause)&&(control_ex2<3*In.getRadius()&&control_ex2>=excause)){

		int k,l;
		double m=2*In.getRadius();
		double n=(Co.getHeight()/(2*In.getRadius()))*2*In.getRadius()+(SQR3DIV2*In.getRadius());
		for(k=0;k<(Co.getWidth()/(2*In.getRadius()));k++){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',m,n,0);
			circ.push_back(drawCirc);
			m=m+2*In.getRadius();
		}
		m=(Co.getWidth()/(2*In.getRadius()))*2*In.getRadius()+(SQR3DIV2*In.getRadius());
		n=2*In.getRadius();
		for(l=1;l<(Co.getHeight()/(2*In.getRadius()));l++){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',m,n,0);
			circ.push_back(drawCirc);
			n=n+2*In.getRadius();
		}
	}
	else if(control_ex2<3*In.getRadius()&&control_ex2>=excause){
		int k;
		double m=2*In.getRadius();
		double n=(Co.getHeight()/(2*In.getRadius()))*2*In.getRadius()+(SQR3DIV2*In.getRadius());
		for(k=1;k<(Co.getWidth()/(2*In.getRadius()));k++){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',m,n,0);
			circ.push_back(drawCirc);
			m=m+2*In.getRadius();
		}
	}
	else if(control_ex1<3*In.getRadius()&&control_ex1>=excause){
		int l;
		double m=(Co.getWidth()/(2*In.getRadius()))*2*In.getRadius()+(SQR3DIV2*In.getRadius());
		double n=2*In.getRadius();
		for(l=1;l<(Co.getHeight()/(2*In.getRadius()));l++){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',m,n,0);
			circ.push_back(drawCirc);
			n=n+2*In.getRadius();
		}
	}
	return;
}
void ComposedShape::optimalFit(circle Co,circle In){
	//In this function I used the equalateral triangle's loop and multiplication to 6
	int nOfCircle;
	int total=0;
	for(nOfCircle=((Co.getRadius()-In.getRadius())/(2*In.getRadius()))+1;nOfCircle>1;nOfCircle--){
		total=total+nOfCircle;
	}
	//for there is no circle issue
	if(Co.getRadius()>In.getRadius())
		total=(3*total)+(3*(total/2-1))+1;
	//for there is no circle issue
	if(Co.getRadius()>In.getRadius()){
		//generate the one small shape and saves the vector
		circle smallC(In.getRadius(),'i',Co.getRadius(),Co.getRadius(),0);
		circ.push_back(smallC);
	}
		
	
	//number of vertical circle
	int nOfVertCircle=(Co.getRadius()-In.getRadius())/(2*In.getRadius())+1;
	int plus;
	double x=Co.getRadius(),y=Co.getRadius();
	int k,l,m=1;
	//the triangle h's
	for(k=nOfVertCircle;k>0;k--){
		plus=0;
		// the triangle line's
		for(l=1;l<m;l++,plus=plus+2*In.getRadius()){
			int rotate;
			//this loop is rotate to circle center
			for(rotate=0;rotate<360;rotate=rotate+60){
				//generate the one small shape and saves the vector
				circle smallC(In.getRadius(),'i',x+plus,y,rotate);//container.radius'a göre rotate var
				circ.push_back(smallC);
			}
		}
		// updates
		m=m+1;
		x=x-In.getRadius();
		y=y+In.getRadius()*SQR3;
	}

	return;
}
void ComposedShape::optimalFit(circle Co,triangle In){
	//In this function I fill the regular equalateral triangle in circle and rotate it loop
	int target=Co.getRadius()/In.getLateral();
	int counter=1,i,total=0;
	for(i=1;i<=target;i++){
		total=total+counter;
		counter=counter+2;
	}
	total=6*total;//360 degree/60 degree
	int nOfTri=Co.getRadius()/In.getLateral();
	//x's adds
	int plus;
	//coordinates
	double x=Co.getRadius(),y=Co.getRadius();
	int k,l,m=1;
	for(k=nOfTri;k>0;k--){
		plus=0;
		for(l=0;l<m;l++,plus=plus+In.getLateral()){
			int rotate;
			//this loop for the normal align triangle
			for(rotate=0;rotate<360;rotate=rotate+60){						
				//generate the one small shape and saves the vector
				triangle smallTri(In.getLateral(),'i',x+plus,y,x+In.getLateral()/2.0+plus,y+(In.getLateral()*SQR3DIV2),(x-In.getLateral()/2.0)+plus,y+(In.getLateral()*SQR3DIV2),rotate);
				tri.push_back(smallTri);
			}
			//this loop for the reverse align triangle
			if(k!=1){
				int rotate2;
				for(rotate2=0;rotate2<360;rotate2=rotate2+60){	
					//generate the one small shape and saves the vector
					triangle reverseSmallTri(In.getLateral(),'i',x+plus,y+(2*In.getLateral()*SQR3DIV2),x+In.getLateral()/2.0+plus,y+(In.getLateral()*SQR3DIV2),(x-In.getLateral()/2.0)+plus,y+(In.getLateral()*SQR3DIV2),rotate2);
					tri.push_back(reverseSmallTri);
					
				}
			}
		}
		//Updates
		m=m+1;
		x=x-In.getLateral()/2.0;
		y=y+In.getLateral()*SQR3DIV2;
	}
	return;
}
void ComposedShape::optimalFit(circle Co,rectangle In){
	int squareWidth=(2*Co.getRadius())/1.414;
	
	int nofRect,addForEmpty1,addForEmpty2,temp;
	
	nofRect=(squareWidth/In.getWidth())*(squareWidth/In.getHeight());
	addForEmpty1=(((squareWidth-((squareWidth/In.getWidth())*In.getWidth()))/In.getHeight())*(squareWidth/In.getWidth()));
	nofRect=nofRect+addForEmpty1;

	int i,j,k,l;
	
	for(i=0;i+In.getWidth()<=squareWidth;i=i+In.getWidth()){
		for(j=0;j+In.getHeight()<=squareWidth;j=j+In.getHeight()){
			//generate the one small shape and saves the vector
			rectangle normal(In.getHeight(),In.getWidth(),'i',i+(Co.getRadius()-squareWidth/2.),j+(Co.getRadius()-squareWidth/2.),0);
			rec.push_back(normal);
		}
	}
	for(k=i;k+In.getHeight()<=squareWidth;k=k+In.getHeight()){
		for(l=0;l+In.getWidth()<=squareWidth;l=l+In.getWidth()){
			//generate the one small shape and saves the vector
			rectangle reverse(In.getWidth(),In.getHeight(),'i',k+(Co.getRadius()-squareWidth/2.),l+(Co.getRadius()-squareWidth/2.),0);
			rec.push_back(reverse);
		}
	}
	
	return;
	
	
	
}

void ComposedShape::draw(ofstream& outputStream,triangle Co,triangle In){
	int i;
	Co.draw(outputStream,0,0);
	for(i=0;i<tri.size();i++){
		tri[i].draw(outputStream,0,0);
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;
}
//All of the under functions provides drawing by the single shape classes draw functions
void ComposedShape::draw(ofstream& outputStream,triangle Co,rectangle In){
	int i;
	Co.draw(outputStream,0,0);
	for(i=0;i<rec.size();i++){
		rec[i].draw(outputStream);
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;
}

void ComposedShape::draw(ofstream& outputStream,triangle Co,circle In){
	int i;
	Co.draw(outputStream,0,0);
	for(i=0;i<circ.size();i++){
		circ[i].draw(outputStream,0,0);
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;
}

void ComposedShape::draw(ofstream& outputStream,circle Co,triangle In){
	int i;
	Co.draw(outputStream,0,0);
	for(i=0;i<tri.size();i++){
		tri[i].draw(outputStream,Co.getRadius(),Co.getRadius());
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;	
}

void ComposedShape::draw(ofstream& outputStream,circle Co,rectangle In){
	int i;
	Co.draw(outputStream,0,0);
	for(i=0;i<rec.size();i++){
		rec[i].draw(outputStream);
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;	
	
}

void ComposedShape::draw(ofstream& outputStream,circle Co,circle In){
	int i;
	Co.draw(outputStream,0,0);
	for(i=0;i<circ.size();i++){
		circ[i].draw(outputStream,Co.getRadius(),Co.getRadius());
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;	
}

void ComposedShape::draw(ofstream& outputStream,rectangle Co,triangle In){
	int i;
	Co.draw(outputStream);
	for(i=0;i<tri.size();i++){
		tri[i].draw(outputStream,0,0);
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;		
}

void ComposedShape::draw(ofstream& outputStream,rectangle Co,rectangle In){
	int i;
	Co.draw(outputStream);
	for(i=0;i<rec.size();i++){
		rec[i].draw(outputStream);
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;	
}

void ComposedShape::draw(ofstream& outputStream,rectangle Co,circle In){
	int i;
	Co.draw(outputStream);
	for(i=0;i<circ.size();i++){
		circ[i].draw(outputStream,0,0);
	}
	outputStream<<"</svg>";
	outputStream.close();
	return;	
}