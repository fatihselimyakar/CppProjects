#include "polyline.h"
//THIS NAMESPACE FOR POLYLINE CLASS AND FUNTIONS
namespace POLYLINE{
    Polyline::Polyline(){ Polygon copy;
                printline=copy; }
    Polyline::Polyline(Polygon &object):printline(object){/*intentionally empty*/}
    Polyline::Polyline(vector<Polygon::Point2d>pointVector){ Polygon copy(pointVector);
                                                   printline=copy; }
    Polyline::Polyline(int newCapacity,int newSize){ Polygon copy(newCapacity,newSize);
                                           printline=copy; }
    Polyline::Polyline(rectangle rec){ Polygon copy(rec);
                             printline=copy; }
    Polyline::Polyline(triangle tri){ Polygon copy(tri);
                            printline=copy; }
    Polyline::Polyline(circle cir){ Polygon copy(cir);
                          printline=copy; }

    Polygon Polyline::getPrintline()const{ return printline; }
    int Polyline::getCapacity()const{ return printline.getCapacity(); }
    int Polyline::getSize()const{ return printline.getSize(); }
    int Polyline::getRotateDegree()const{ return printline.getRotateDegree(); }
    int Polyline::getRotateByX()const{ return printline.getRotateByX(); }
    int Polyline::getRotateByY()const{ return printline.getRotateByY(); }
    char Polyline::getPos()const{ return printline.getPos(); }

    Polyline& Polyline::operator=(const Polyline& rightSide){ printline=rightSide.printline; return *this; }
    Polygon::Point2d& Polyline::operator[](int index)const{ return printline[index]; }
    bool Polyline::operator==(const Polyline& rightSide){ return printline==rightSide.printline; }
    bool Polyline::operator!=(const Polyline& rightSide){ return printline!=rightSide.printline; }
    ostream& operator<<(ostream& outputStream,const Polyline& object){
        if(object.printline.getPos()=='c'){
    		outputStream<<R"(<svg version="1.1")"<<endl;
    		outputStream<<R"(baseProfile="full" width="100%" height="100%")"<<endl;
    		outputStream<<R"(xmlns="http://www.w3.org/2000/svg">
    	<polyline points=")";
        //FOR THE UNKNOWN VECTOR SIZE I USED FOR LOOP
        for(int i=0;i<object.printline.getSize();i++){
            outputStream<<' '<<object.printline[i].getX()<<','<<object.printline[i].getY();
        }
        outputStream<<R"(" fill="none" stroke="black" />)"<<endl;
    	}
    	else if(object.printline.getPos()=='i'){
    		outputStream<<R"(<polyline points=")";
            //FOR THE UNKNOWN VECTOR SIZE I USED FOR LOOP
            for(int i=0;i<object.printline.getSize();i++){
                outputStream<<' '<<object.printline[i].getX()<<','<<object.printline[i].getY();
            }
            outputStream<<R"(" fill="none" stroke="black" transform="rotate()"<<object.printline.getRotateDegree()<<R"(,)"<<object.printline.getRotateByX()<<R"(,)"<<object.printline.getRotateByY()<<")\" />"<<endl;
    	}

        return outputStream;
    }

     Polyline Polyline::operator+(const Polyline& rightSide){
         Polygon sumOfPoly=printline+rightSide.printline;
         Polyline returnIt(sumOfPoly);
         return returnIt;
     }

}
