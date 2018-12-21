#ifndef COMPOSEDSHAPE_H_

#define COMPOSEDSHAPE_H_
#include<iostream>
#include<fstream>
#include<vector>
#include"triangle.h"
#include"rectangle.h"
#include"circle.h"
#include"polygon.h"
#include"polyline.h"

using namespace POLYGON;
using namespace std;

class ComposedShape{
	public:
	//HW2'S TOOLS
	//These constructors for the combination of 3 types(rectangle,triangle,circle)
		class ShapeElem;
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
			:recIn(In),recCo(Co)
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
			:circIn(In),circCo(Co)
			{/*intentionally empty*/}

		//HW2'S TOOLS
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

		////HW3'S TOOLS
		vector<ShapeElem> getElemVec()const{ return innerShapeVec; }
		class ShapeElem{
			public:
				//These constructors are provides us know the type and we handle castable void variable
				enum Shapes{r=10,c,t};
				//ShapeElem(){/*int empty*/}
				ShapeElem(class triangle& innerTri){
					shapeObject=&innerTri;
					shape=t;
				}
				ShapeElem(class rectangle& innerRec){
					shapeObject=&innerRec;
					shape=r;
				}
				ShapeElem(class circle& innerCirc){
					shapeObject=&innerCirc;
					shape=c;
				}
				circle getCircleObject(){
					circle *circ=static_cast<class circle*>(shapeObject);
					return *circ; }
				rectangle getRectangleObject(){
					rectangle *rec=static_cast<class rectangle*>(shapeObject);
					return *rec; }
				triangle getTriangleObject(){
					triangle *tri=static_cast<class triangle*>(shapeObject);
					return *tri; }
				friend ostream& operator<<(ostream& outputStream,const ShapeElem& Shape);
				double getPerimeter();
				double getArea();

			private:
				void* shapeObject;
				Shapes shape;

		};


		//HW3'S TOOLS
		//ComposedShape's operator overloadings
		ComposedShape& operator+=(const ComposedShape& addShape);
		const ShapeElem& operator[](int index)const{ return innerShapeVec[index]; }
		//UPDATED FOR THE HW4'S POLYGON SVG PRINTING
		friend ostream& operator<<(ostream& outputStream,const ComposedShape& Shape);

		//HW2'S AND HW3'S FUNCTIONS(UPDATED BY HW4 FOR ADDING THE SHAPES IN THE POLYGON TYPE VECTOR)
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

		//HW2'S FUNCTIONS
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
		triangle triIn;//HW2
		triangle triCo;//HW2
		circle circIn;//HW2
		circle circCo;//HW2
		rectangle recIn;//HW2
		rectangle recCo;//HW2
		vector<triangle>tri;//HW2
		vector<rectangle>rec;//HW2
		vector<circle>circ;//HW2
		vector<ShapeElem>innerShapeVec;//HW3
		//FOR HW4
		vector<Polygon>allShapes;

};
//FOR THE TESTING WROTE FUNCTIONS OVERLOADS AND CLASSES FOR HW4
void testPolygonHw4();
void testPolylineHw4();
void testComposedShapeHw4();


#endif
