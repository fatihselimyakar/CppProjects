#include"ComposedShape.h"

void ComposedShape::optimalFit(triangle Co,triangle In){
	//FOR HW4'S BIG SHAPE
	Polygon polyTriCo(Co);
	allShapes.push_back(polyTriCo);

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
			//FOR HW2
			triangle normal(In.getLateral(),'i',x+plus,y,x+In.getLateral()/2.0+plus,y+(In.getLateral()*SQR3DIV2),x-(In.getLateral()/2.0)+plus,y+(In.getLateral()*SQR3DIV2),0,0,0);
			tri.push_back(normal);
			//FOR HW4'S INNER POLYGON
			Polygon polyTri(normal);
			allShapes.push_back(polyTri);
			//FOR HW3
			ShapeElem push(normal);
			innerShapeVec.push_back(push);
			//for the reverse type triangle's and the if is need to last line
			if(k!=1){
				//set the one small shape and saves the vector
				//FOR HW2
				normal.set(In.getLateral(),'i',x+plus,y+(2*In.getLateral()*SQR3DIV2),x+In.getLateral()/2.0+plus,y+(In.getLateral()*SQR3DIV2),x-(In.getLateral()/2.0)+plus,y+(In.getLateral()*SQR3DIV2),0);
				tri.push_back(normal);
				//FOR HW4'S SMALL SHAPE
				Polygon polyTri2(normal);
				allShapes.push_back(polyTri2);
				//FOR HW3
				ShapeElem push(normal);
				innerShapeVec.push_back(push);

			}

		}
		m=m+1;
		x=x-In.getLateral()/2.0;//updating x coordinates
		y=y+In.getLateral()*SQR3DIV2;//updating y coordinates
	}
	return;
}
void ComposedShape::optimalFit(triangle Co,rectangle In){
	//FOR HW4'S BIG SHAPE
	Polygon polyTriCo(Co);
	allShapes.push_back(polyTriCo);
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
				//FOR HW2
				rectangle drawRec(In.getHeight(),In.getWidth(),'i',x+plus,y,0);
				rec.push_back(drawRec);
				//FOR HW3
				ShapeElem push(drawRec);
				innerShapeVec.push_back(push);
				//FOR HW4
				Polygon polyRecIn(drawRec);
				allShapes.push_back(polyRecIn);

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
				ShapeElem push(drawRec);
				innerShapeVec.push_back(push);
				rec.push_back(drawRec);
				//FOR HW4'S INNER SHAPE
				Polygon polyRecIn(drawRec);
				allShapes.push_back(polyRecIn);
			}
			m=m-2*(In.getWidth()/SQR3);
			x=x+In.getWidth()/SQR3;
			y=y-In.getWidth();
		}

	}
	return;
}
void ComposedShape::optimalFit(triangle Co,circle In){
	//FOR THE HW4'S BIG SHAPE
	Polygon polyTriCo(Co);
	allShapes.push_back(polyTriCo);
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
			circle drawCirc(In.getRadius(),'i',x+plus,y,0,0,0);
			ShapeElem push(drawCirc);
			innerShapeVec.push_back(push);
			circ.push_back(drawCirc);
			//FOR HW4
			Polygon polyCircIn(drawCirc);
			allShapes.push_back(polyCircIn);
		}
		//updates
		m=m-4*(In.getRadius()/SQR3);
		x=x+2*(In.getRadius()/SQR3);
		y=y-2*In.getRadius();
	}
	return;
}
void ComposedShape::optimalFit(rectangle Co,triangle In){
	//FOR THE HW4'S BIG SHAPE
	Polygon polyRecCo(Co);
	allShapes.push_back(polyRecCo);

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
				triangle normal(In.getLateral(),'i',i,j,In.getLateral()+i,j,(In.getLateral()/2.0)+i,SQR3*(In.getLateral()/2.0)+j,0,0,0);
				ShapeElem push(normal);
				innerShapeVec.push_back(push);
				tri.push_back(normal);
				//FOR HW4
				Polygon polyTriIn(normal);
				allShapes.push_back(polyTriIn);
			}
		}
		//prints reverse type triangle
		double k,l;
		for(l=(SQR3*(In.getLateral()/2.0));l<=Co.getHeight();l=l+(SQR3*(In.getLateral()/2.0))){
			for(k=In.getLateral()/2.0;k+In.getLateral()<=Co.getWidth();k=k+In.getLateral()){
				//generate the one small shape and saves the vector
				triangle normal(In.getLateral(),'i',k,l,In.getLateral()/2.0+k,l-(SQR3*(In.getLateral()/2.0)),In.getLateral()+k,l,0,0,0);
				ShapeElem push(normal);
				innerShapeVec.push_back(push);
				tri.push_back(normal);
				//FOR HW4
				Polygon polyTriIn(normal);
				allShapes.push_back(polyTriIn);
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
				triangle normal(In.getLateral(),'i',i,j,i,j+In.getLateral(),SQR3*(In.getLateral()/2.0)+i,(In.getLateral()/2.0)+j,0,0,0);
				ShapeElem push(normal);
				innerShapeVec.push_back(push);
				tri.push_back(normal);
				//FOR HW4
				Polygon polyTriIn(normal);
				allShapes.push_back(polyTriIn);
			}
		}
		//prints normal type triangle
		double k,l;
		for(l=(In.getLateral()/2.0);l+In.getLateral()<=Co.getHeight();l=l+In.getLateral()){
			for(k=(SQR3*(In.getLateral()/2.0));k<=Co.getWidth();k=k+(SQR3*(In.getLateral()/2.0))){
				//generate the one small shape and saves the vector
				triangle normal(In.getLateral(),'i',k,l,k-(SQR3*(In.getLateral()/2.0)),In.getLateral()/2.0+l,k,In.getLateral()+l,0,0,0);
				ShapeElem push(normal);
				innerShapeVec.push_back(push);
				tri.push_back(normal);
				//FOR HW4
				Polygon polyTriIn(normal);
				allShapes.push_back(polyTriIn);
			}
		}
	}
	return;
}
void ComposedShape::optimalFit(rectangle Co,rectangle In){
	//FOR THE HW4'S BIG SHAPE
	Polygon polyRecCo(Co);
	allShapes.push_back(polyRecCo);

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
				ShapeElem push(normal);
				innerShapeVec.push_back(push);
				rec.push_back(normal);
				//FOR THE HW4
				Polygon polyRecIn(normal);
				allShapes.push_back(polyRecIn);
			}
		}
		//this part prints added and rotated rectangles
		for(k=i;k+smallheight<=Co.getWidth();k=k+smallheight){
			for(l=0;l+smallwidth<=Co.getHeight();l=l+smallwidth){
				//generate the one small shape and saves the vector
				rectangle normal2(smallwidth,smallheight,'i',k,l,0);
				ShapeElem push(normal2);
				innerShapeVec.push_back(push);
				rec.push_back(normal2);
				//FOR THE HW4
				Polygon polyRecIn2(normal2);
				allShapes.push_back(polyRecIn2);
			}
		}


	}
	else{
		int i,j,k,l;
		for(i=0;i+smallheight<=Co.getWidth();i=i+smallheight){
			for(j=0;j+smallwidth<=Co.getHeight();j=j+smallwidth){
				//generate the one small shape and saves the vector
				rectangle reverse(smallwidth,smallheight,'i',i,j,0);
				ShapeElem push(reverse);
				innerShapeVec.push_back(push);
				rec.push_back(reverse);
				//FOR THE HW4
				Polygon polyRecIn(reverse);
				allShapes.push_back(polyRecIn);

			}
		}
		//this part prints added and rotated reverse rectangles
		for(k=0;k+smallwidth<=Co.getWidth();k=k+smallwidth){
			for(l=j;l+smallheight<=Co.getHeight();l=l+smallheight){
				//generate the one small shape and saves the vector
				rectangle reverse2(smallheight,smallwidth,'i',k,l,0);
				ShapeElem push(reverse2);
				innerShapeVec.push_back(push);
				rec.push_back(reverse2);
				//FOR THE HW4
				Polygon polyRecIn2(reverse2);
				allShapes.push_back(polyRecIn2);
			}
		}
	}
	return;
}
void ComposedShape::optimalFit(rectangle Co,circle In){
	//FOR THE HW4'S BIG SHAPE
	Polygon polyRecCo(Co);
	allShapes.push_back(polyRecCo);
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
			circle drawCirc(In.getRadius(),'i',i,j,0,0,0);
			ShapeElem push(drawCirc);
			innerShapeVec.push_back(push);
			circ.push_back(drawCirc);
			//FOR THE HW4
			Polygon polyCircIn(drawCirc);
			allShapes.push_back(polyCircIn);
		}
	}
	//for the printing exception issue
	if((control_ex1<3*In.getRadius()&&control_ex1>=excause)&&(control_ex2<3*In.getRadius()&&control_ex2>=excause)){

		int k,l;
		double m=2*In.getRadius();
		double n=(Co.getHeight()/(2*In.getRadius()))*2*In.getRadius()+(SQR3DIV2*In.getRadius());
		for(k=0;k<(Co.getWidth()/(2*In.getRadius()));k++){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',m,n,0,0,0);
			ShapeElem push(drawCirc);
			innerShapeVec.push_back(push);
			circ.push_back(drawCirc);
			//FOR THE HW4
			Polygon polyCircIn(drawCirc);
			allShapes.push_back(polyCircIn);

			m=m+2*In.getRadius();
		}
		m=(Co.getWidth()/(2*In.getRadius()))*2*In.getRadius()+(SQR3DIV2*In.getRadius());
		n=2*In.getRadius();
		for(l=1;l<(Co.getHeight()/(2*In.getRadius()));l++){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',m,n,0,0,0);
			ShapeElem push(drawCirc);
			innerShapeVec.push_back(push);
			circ.push_back(drawCirc);
			//FOR THE HW4
			Polygon polyCircIn(drawCirc);
			allShapes.push_back(polyCircIn);

			n=n+2*In.getRadius();
		}
	}
	else if(control_ex2<3*In.getRadius()&&control_ex2>=excause){
		int k;
		double m=2*In.getRadius();
		double n=(Co.getHeight()/(2*In.getRadius()))*2*In.getRadius()+(SQR3DIV2*In.getRadius());
		for(k=1;k<(Co.getWidth()/(2*In.getRadius()));k++){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',m,n,0,0,0);
			ShapeElem push(drawCirc);
			innerShapeVec.push_back(push);
			circ.push_back(drawCirc);
			//FOR THE HW4
			Polygon polyCircIn(drawCirc);
			allShapes.push_back(polyCircIn);

			m=m+2*In.getRadius();
		}
	}
	else if(control_ex1<3*In.getRadius()&&control_ex1>=excause){
		int l;
		double m=(Co.getWidth()/(2*In.getRadius()))*2*In.getRadius()+(SQR3DIV2*In.getRadius());
		double n=2*In.getRadius();
		for(l=1;l<(Co.getHeight()/(2*In.getRadius()));l++){
			//generate the one small shape and saves the vector
			circle drawCirc(In.getRadius(),'i',m,n,0,0,0);
			ShapeElem push(drawCirc);
			innerShapeVec.push_back(push);
			circ.push_back(drawCirc);
			//FOR THE HW4
			Polygon polyCircIn(drawCirc);
			allShapes.push_back(polyCircIn);

			n=n+2*In.getRadius();
		}
	}
	return;
}
void ComposedShape::optimalFit(circle Co,circle In){
	//FOR THE HW4's BIG shape
	Polygon polyCircCo(Co);
	allShapes.push_back(polyCircCo);
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
		circle smallC(In.getRadius(),'i',Co.getRadius(),Co.getRadius(),0,0,0);
		ShapeElem push(smallC);
		innerShapeVec.push_back(push);
		circ.push_back(smallC);
		//FOR THE HW4
		Polygon polyCircIn(smallC);
		allShapes.push_back(polyCircIn);

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
				circle smallC(In.getRadius(),'i',x+plus,y,rotate,Co.getCenterCoordX(),Co.getCenterCoordY());//container.radius'a göre rotate var
				ShapeElem push(smallC);
				innerShapeVec.push_back(push);
				circ.push_back(smallC);
				//FOR THE HW4
				Polygon polyCircIn(smallC);
				allShapes.push_back(polyCircIn);
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
	//FOR THE HW4' big shape
	Polygon polyCircCo(Co);
	allShapes.push_back(polyCircCo);
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
				triangle smallTri(In.getLateral(),'i',x+plus,y,x+In.getLateral()/2.0+plus,y+(In.getLateral()*SQR3DIV2),(x-In.getLateral()/2.0)+plus,y+(In.getLateral()*SQR3DIV2),rotate,Co.getCenterCoordX(),Co.getCenterCoordY());
				ShapeElem push(smallTri);
				innerShapeVec.push_back(push);
				tri.push_back(smallTri);
				//FOR THE HW4
				Polygon polyTriIn(smallTri);
				allShapes.push_back(polyTriIn);
			}
			//this loop for the reverse align triangle
			if(k!=1){
				int rotate2;
				for(rotate2=0;rotate2<360;rotate2=rotate2+60){
					//generate the one small shape and saves the vector
					triangle reverseSmallTri(In.getLateral(),'i',x+plus,y+(2*In.getLateral()*SQR3DIV2),x+In.getLateral()/2.0+plus,y+(In.getLateral()*SQR3DIV2),(x-In.getLateral()/2.0)+plus,y+(In.getLateral()*SQR3DIV2),rotate2,Co.getCenterCoordX(),Co.getCenterCoordY());
					ShapeElem push(reverseSmallTri);
					innerShapeVec.push_back(push);
					tri.push_back(reverseSmallTri);
					//FOR THE HW4
					Polygon polyTriIn(reverseSmallTri);
					allShapes.push_back(polyTriIn);

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
	//FOR THE HW4' big shape
	Polygon polyCircCo(Co);
	allShapes.push_back(polyCircCo);

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
			ShapeElem push(normal);
			innerShapeVec.push_back(push);
			rec.push_back(normal);
			//FOR THE HW4
			Polygon polyRecIn(normal);
			allShapes.push_back(polyRecIn);
		}
	}
	for(k=i;k+In.getHeight()<=squareWidth;k=k+In.getHeight()){
		for(l=0;l+In.getWidth()<=squareWidth;l=l+In.getWidth()){
			//generate the one small shape and saves the vector
			rectangle reverse(In.getWidth(),In.getHeight(),'i',k+(Co.getRadius()-squareWidth/2.),l+(Co.getRadius()-squareWidth/2.),0);
			ShapeElem push(reverse);
			innerShapeVec.push_back(push);
			rec.push_back(reverse);
			//FOR THE HW4
			Polygon polyRecIn(reverse);
			allShapes.push_back(polyRecIn);
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

//I cast the value with the enum variable then I call the function
double ComposedShape::ShapeElem::getPerimeter(){
	if(shape==r){
		rectangle *pRec = static_cast<class rectangle*>(shapeObject);
		return pRec->periLength();
	}
	else if(shape==c){
		circle *pCirc = static_cast<class circle*>(shapeObject);
		return pCirc->periLength();
	}
	else if(shape==t){
		triangle *pTri = static_cast<class triangle*>(shapeObject);
		return pTri->periLength();
	}
	else
		return 0;
}
//I cast the value with the enum variable then I call the function
double ComposedShape::ShapeElem::getArea(){
	if(shape==r){
		rectangle *pRec = static_cast<class rectangle*>(shapeObject);
		return pRec->area();
	}
	else if(shape==t){
		triangle *pTri = static_cast<class triangle*>(shapeObject);
		return pTri->area();
	}
	else if(shape==c){
		circle *pCirc = static_cast<class circle*>(shapeObject);
		return pCirc->area();
	}
	else
		return 0;
}
//I add the new composedShape variable from old one
ComposedShape& ComposedShape::operator+=(const ComposedShape& addShape){//BUNA BAK BİDAHA
	triIn=addShape.getTriIn();
	triCo=addShape.getTriCo();
	circIn=addShape.getCircIn();
	circCo=addShape.getCircCo();
	recIn=addShape.getRecIn();
	recCo=addShape.getRecCo();
	innerShapeVec=addShape.innerShapeVec;

	return *this;
}
//I cast the value with the enum variable then I call the function
ostream& operator<<(ostream& outputStream,const ComposedShape::ShapeElem& Shape){
	if(Shape.shape==ComposedShape::ShapeElem::r){
		rectangle *pRec = static_cast<class rectangle*>(Shape.shapeObject);
		outputStream<<*pRec;
	}
	else if(Shape.shape==ComposedShape::ShapeElem::t){
		triangle *pTri = static_cast<class triangle*>(Shape.shapeObject);
		outputStream<<*pTri;
	}
	else if(Shape.shape==ComposedShape::ShapeElem::c){
		circle *pCirc = static_cast<class circle*>(Shape.shapeObject);
		outputStream<<*pCirc;
	}
	return outputStream;
}
//FOR HW4 DRAWING THE POLYGON TYPE SHAPE
ostream& operator<<(ostream& outputStream,const ComposedShape& Shape){
	for(int i=0;i<Shape.allShapes.size();i++){
		outputStream<<Shape.allShapes[i];

	}
	outputStream<<"</svg>";
	return outputStream;
}

//FOR THE TESTING POLYGON_H
void testPolygonHw4(){
	ofstream outputStream;
	//I MAKE THE RECTANGLE TRIANGLE AND CIRCLE TYPE ARRAYS
	rectangle RecArr[4]={{20,10,'i'},{20,10,'i'},{100,200,'c',0,0,0},{150,330,'c',0,0,0}};
	triangle TriArr[4]={{15,'i'},{20,'i'},{100,'c',50,0,0,SQR3DIV2*100,100,SQR3DIV2*100,0,0,0},{250,'c',125,0,0,SQR3DIV2*250,250,SQR3DIV2*250,0,0,0}};
	circle CircArr[4]={{20,'i'},{50,'i'},{290,'c',290,290,0,0,0},{300,'c',300,300,0,0,0}};

	//I MAKE THE POINT2D VECTOR(BASIC SQUARE COORDINATES) FOR USE THE POLYGON CONSTRUCTOR
	vector<Polygon::Point2d>sampleVector;
	Polygon::Point2d point1(0,50);
	sampleVector.push_back(point1);
	point1.set(0,200);
	sampleVector.push_back(point1);
	point1.set(150,200);
	sampleVector.push_back(point1);
	point1.set(150,50);
	sampleVector.push_back(point1);

	//I MAKE THE POINT2D VECTOR(BASIC TRIANGLE COORDINATES) FOR USE THE POLYGON CONSTRUCTOR
	vector<Polygon::Point2d>sampleVector2;
	Polygon::Point2d point2(350,0);
	sampleVector2.push_back(point2);
	point2.set(150,200);
	sampleVector2.push_back(point2);
	point2.set(350,200);
	sampleVector2.push_back(point2);

	//I MAKE THE POLYGON AND POLYLINE ARRAY WITH THE POLYGON CONSTRUCTORS AND DRAW THE POLYGON SAMPLES
	Polygon polyArray[5]={sampleVector,RecArr[3],TriArr[2],CircArr[3],sampleVector2};

	//OPERATOR TESTS
	cout<<"***Polygon Tests***"<<endl;
	Polygon add1point(1,1);
	add1point[0].set(75,0);
	Polygon sum=polyArray[0]+add1point;//btw I test [] operator and = operator
	outputStream.open("SamplePolygonPlusOp.svg");
	outputStream<<sum;
	outputStream<<"</svg>";//testing the << operator too
	outputStream.close();
	cout<<"[],+,<<,= tests completed"<<endl;
	if(polyArray[0]==polyArray[0]){
		cout<<"== test completed"<<endl;
	}
	if(polyArray[0]!=polyArray[1]){
		cout<<"!= test completed"<<endl;
	}
	//for the my sampleVector in polyArray[0] tests the getters
	cout<<"getter test->Capacity:"<<polyArray[0].getCapacity()<<" Size:"<<polyArray[0].getSize()<<" Rotate degree:"<<polyArray[0].getRotateDegree()<<" Rotate by x:"<<polyArray[0].getRotateByX()<<" Rotate by y:"<<polyArray[0].getRotateByY()<<" Pos:"<<polyArray[0].getPos()<<endl;

    //DRAW THE MY SAMPLES IN SVG
	outputStream.open("SamplePOLYGON1.svg");
	outputStream<<polyArray[0];
	outputStream<<"</svg>";
	outputStream.close();

	outputStream.open("SamplePOLYGON2.svg");
	outputStream<<polyArray[1];
	outputStream<<"</svg>";
	outputStream.close();

	outputStream.open("SamplePOLYGON3.svg");
	outputStream<<polyArray[2];
	outputStream<<"</svg>";
	outputStream.close();

	outputStream.open("SamplePOLYGON4.svg");
	outputStream<<polyArray[3];
	outputStream<<"</svg>";
	outputStream.close();

	outputStream.open("SamplePOLYGON5.svg");
	outputStream<<polyArray[4];
	outputStream<<"</svg>";
	outputStream.close();

	cout<<"Polygon draw and function tests completed!"<<endl<<endl;

}

//FOR THE TESTING COMPOSEDSHAPE_H_ WITH POLYGON_H
void testComposedShapeHw4(){
	ofstream outputStream;
	//I MAKE THE RECTANGLE TRIANGLE AND CIRCLE TYPE ARRAYS
	cout<<"***ComposedShape Test***"<<endl;
	rectangle RecArr[4]={{20,10,'i'},{20,10,'i'},{100,200,'c',0,0,0},{150,330,'c',0,0,0}};
	triangle TriArr[4]={{15,'i'},{20,'i'},{100,'c',50,0,0,SQR3DIV2*100,100,SQR3DIV2*100,0,0,0},{250,'c',125,0,0,SQR3DIV2*250,250,SQR3DIV2*250,0,0,0}};
	circle CircArr[4]={{20,'i'},{50,'i'},{290,'c',290,290,0,0,0},{300,'c',300,300,0,0,0}};

	//COMPOSEDSHAPE ARRAY AND DRAWING WITH USE POLYGON OVERLOADS
	//THERE IS A VECTOR OF POLYGON IN COMPOSED SHAPE CLASS THEN I PUSHBACK THE COORDINATES IN OVERLOADED OPTIMALFIT FUNCTIN
	//AND FINALLY I PRINT THE SVG FILE FROM OVERLOADED "<<" OPERATOR AND MODIFIED OPTIMALFIT FUNCTION FOR THE POLYGON
	ComposedShape CompArr[9]={{RecArr[2],RecArr[0]},{RecArr[3],TriArr[1]},{RecArr[3],CircArr[1]},{TriArr[3],RecArr[1]},{TriArr[3],TriArr[0]},{TriArr[3],CircArr[1]},{CircArr[3],RecArr[1]},{CircArr[3],TriArr[1]},{CircArr[3],CircArr[0]}};//I make the ComposedShape type class including to other type classes array's variable

	outputStream.open("SampleRR.svg");
	CompArr[0].optimalFit(CompArr[0].getRecCo(),CompArr[0].getRecIn());
	outputStream<<CompArr[0];
	outputStream.close();

	outputStream.open("SampleRT.svg");
	CompArr[1].optimalFit(CompArr[1].getRecCo(),CompArr[1].getTriIn());
	outputStream<<CompArr[1];
	outputStream.close();

	outputStream.open("SampleRC.svg");
	CompArr[2].optimalFit(CompArr[2].getRecCo(),CompArr[2].getCircIn());
	outputStream<<CompArr[2];
	outputStream.close();

	outputStream.open("SampleTR.svg");
	CompArr[3].optimalFit(CompArr[3].getTriCo(),CompArr[3].getRecIn());
	outputStream<<CompArr[3];
	outputStream.close();

	outputStream.open("SampleTT.svg");
	CompArr[4].optimalFit(CompArr[4].getTriCo(),CompArr[4].getTriIn());
	outputStream<<CompArr[4];
	outputStream.close();

	outputStream.open("SampleTC.svg");
	CompArr[5].optimalFit(CompArr[5].getTriCo(),CompArr[5].getCircIn());
	outputStream<<CompArr[5];
	outputStream.close();

	outputStream.open("SampleCR.svg");
	CompArr[6].optimalFit(CompArr[6].getCircCo(),CompArr[6].getRecIn());
	outputStream<<CompArr[6];
	outputStream.close();

	outputStream.open("SampleCT.svg");
	CompArr[7].optimalFit(CompArr[7].getCircCo(),CompArr[7].getTriIn());
	outputStream<<CompArr[7];
	outputStream.close();

	outputStream.open("SampleCC.svg");
	CompArr[8].optimalFit(CompArr[8].getCircCo(),CompArr[8].getCircIn());
	outputStream<<CompArr[8];
	outputStream.close();

	cout<<"ComposedShape Test completed!"<<endl<<endl;
}

//FOR THE TESTING POLYLINE_H
void testPolylineHw4(){
	using namespace POLYLINE;
	ofstream outputStream;
	//I MAKE THE RECTANGLE TRIANGLE AND CIRCLE TYPE ARRAYS
	rectangle RecArr[4]={{20,10,'i'},{20,10,'i'},{100,200,'c',0,0,0},{150,330,'c',0,0,0}};
	triangle TriArr[4]={{15,'i'},{20,'i'},{100,'c',50,0,0,SQR3DIV2*100,100,SQR3DIV2*100,0,0,0},{250,'c',125,0,0,SQR3DIV2*250,250,SQR3DIV2*250,0,0,0}};
	circle CircArr[4]={{20,'i'},{50,'i'},{290,'c',290,290,0,0,0},{300,'c',300,300,0,0,0}};

	//I MAKE THE POINT2D VECTOR(BASIC SQUARE COORDINATES) FOR USE THE POLYGON CONSTRUCTOR
	vector<Polygon::Point2d>sampleVector;
	Polygon::Point2d point1(0,50);
	sampleVector.push_back(point1);
	point1.set(0,200);
	sampleVector.push_back(point1);
	point1.set(150,200);
	sampleVector.push_back(point1);
	point1.set(150,50);
	sampleVector.push_back(point1);

	//I MAKE THE POINT2D VECTOR(BASIC TRIANGLE COORDINATES) FOR USE THE POLYGON CONSTRUCTOR
	vector<Polygon::Point2d>sampleVector2;
	Polygon::Point2d point2(200,0);
	sampleVector2.push_back(point2);
	point2.set(0,200);
	sampleVector2.push_back(point2);
	point2.set(200,200);
	sampleVector2.push_back(point2);

	//I MAKE THE POLYLINE ARRAY WITH THE POLYLINE CONSTRUCTORS AND DRAW THE POLYLINE SAMPLES
	Polyline polyArray[5]={sampleVector,RecArr[3],TriArr[2],CircArr[3],sampleVector2};

	//OPERATOR TESTS
	cout<<"***Polyline Tests***"<<endl;
	Polyline add1point(1,1);
	add1point[0].set(75,0);
	Polyline sum=polyArray[0]+add1point;//btw I test [] operator and = operator
	outputStream.open("SamplePolylinePlusOp.svg");
	outputStream<<sum;
	outputStream<<"</svg>";
	outputStream.close();
	cout<<"[],+,<<,= tests completed"<<endl;
	if(polyArray[0]==polyArray[0]){
		cout<<"== test completed"<<endl;
	}
	if(polyArray[0]!=polyArray[1]){
		cout<<"!= test completed"<<endl;
	}
	//for the my circle in polyArray[3] tests the getters
	cout<<"getter test->Capacity:"<<polyArray[3].getCapacity()<<" Size:"<<polyArray[3].getSize()<<" Rotate degree:"<<polyArray[3].getRotateDegree()<<" Rotate by x:"<<polyArray[3].getRotateByX()<<" Rotate by y:"<<polyArray[3].getRotateByY()<<" Pos:"<<polyArray[3].getPos()<<endl;

	//DRAW THE MY SAMPLES IN SVG
	outputStream.open("SamplePOLYLINE1.svg");
	outputStream<<polyArray[0];
	outputStream<<"</svg>";
	outputStream.close();

	outputStream.open("SamplePOLYLINE2.svg");
	outputStream<<polyArray[1];
	outputStream<<"</svg>";
	outputStream.close();

	outputStream.open("SamplePOLYLINE3.svg");
	outputStream<<polyArray[2];
	outputStream<<"</svg>";
	outputStream.close();

	outputStream.open("SamplePOLYLINE4.svg");
	outputStream<<polyArray[3];
	outputStream<<"</svg>";
	outputStream.close();

	outputStream.open("SamplePOLYLINE5.svg");
	outputStream<<polyArray[4];
	outputStream<<"</svg>";
	outputStream.close();

	cout<<"Polyline draw and function tests completed!"<<endl<<endl;
}
