#ifndef COMPOSEDSHAPE_H_

#define COMPOSEDSHAPE_H_
#include<iostream>
#include<fstream>
#include<vector>
#include"triangle.h"
#include"rectangle.h"
#include"circle.h"


using namespace std;

class ComposedShape{
	public:
	//These constructors for the combination of 3 types(rectangle,triangle,circle)
		ComposedShape(){/*intentionally empty*/}
		ComposedShape(triangle Co,triangle In)
			:triIn(In),triCo(Co)
			{/*intentionally empty*/}
		ComposedShape(triangle Co,rectangle In)
			:triCo(Co),recIn(In)
			{/*intentionally empty*/}
		ComposedShape(triangle Co,circle In)
			:triCo(Co),circIn(In)
			{/*intentionally empty*/}
		ComposedShape(rectangle Co,triangle In)
			:recCo(Co),triIn(In)
			{/*intentionally empty*/}
		ComposedShape(rectangle Co,rectangle In)
			:recCo(Co),recIn(In)
			{/*intentionally empty*/}
		ComposedShape(rectangle Co,circle In)
			:recCo(Co),circIn(In)
			{/*intentionally empty*/}
		ComposedShape(circle Co,rectangle In)
			:circCo(Co),recIn(In)
			{/*intentionally empty*/}
		ComposedShape(circle Co,triangle In)
			:circCo(Co),triIn(In)
			{/*intentionally empty*/}
		ComposedShape(circle Co,circle In)
			:circCo(Co),circIn(In)
			{/*intentionally empty*/}
		
		//getter functions for information hiding and encapsulation
		triangle getTriIn()const{ return triIn; }
		triangle getTriCo()const{ return triCo; }
		rectangle getRecIn()const{ return recIn; }
		rectangle getRecCo()const{ return recCo; }
		circle getCircIn()const{ return circIn; }
		circle getCircCo()const{ return circCo; }
		circle getCirc(int num)const{ return circ[num]; }
		triangle getTri(int num)const{return tri[num];}
		rectangle getRec(int num)const{ return rec[num]; }
		
		//This overloaded functions provide us calculate and saving the vectors according to big and small shape types
		void optimalFit(triangle Co,triangle In);
		void optimalFit(triangle Co,rectangle In);
		void optimalFit(triangle Co,circle In);
		void optimalFit(rectangle Co,triangle In);
		void optimalFit(rectangle Co,rectangle In);
		void optimalFit(rectangle Co,circle In);
		void optimalFit(circle Co,circle In);
		void optimalFit(circle Co,triangle In);
		void optimalFit(circle Co,rectangle In);
	
		//This overloaded functions provide us drawing according to shape type vectors
		void draw(ofstream& outputStream,triangle Co,triangle In);
		void draw(ofstream& outputStream,triangle Co,rectangle In);
		void draw(ofstream& outputStream,triangle Co,circle In);
		void draw(ofstream& outputStream,circle Co,triangle In);
		void draw(ofstream& outputStream,circle Co,rectangle In);
		void draw(ofstream& outputStream,circle Co,circle In);
		void draw(ofstream& outputStream,rectangle Co,triangle In);
		void draw(ofstream& outputStream,rectangle Co,rectangle In);
		void draw(ofstream& outputStream,rectangle Co,circle In);
	private:
		triangle triIn;
		triangle triCo;
		circle circIn;
		circle circCo;
		rectangle recIn;
		rectangle recCo;
		vector<triangle>tri;
		vector<rectangle>rec;
		vector<circle>circ;
};


#endif