#ifndef POLYLINE_H

#define POLYLINE_H
#include"polygon.h"
#include<iostream>

using namespace POLYGON;
using namespace std;
//I OPENED THE POLYLINE NAMESPACE TWO OF FIRST FOR THE PROTOTYPES
//THEN I WILL OPEN THE .CPP FOR IMPLEMENTS
namespace POLYLINE{
    //ALL OF THESE FUNCTIONS AND OVERLOADS (EXCEPT << OVERLOAD) I USE THE WROTE POLYGON FUNCTIONS AND OVERLOADS
    class Polyline{
  public:
      Polyline();
      Polyline(Polygon &object);
      Polyline(vector<Polygon::Point2d>pointVector);
      Polyline(int newCapacity,int newSize);
      Polyline(rectangle rec);
      Polyline(triangle tri);
      Polyline(circle cir);

      friend ostream& operator<<(ostream& outputStream,const Polyline& object);
      Polyline& operator=(const Polyline& rightSide);
      Polygon::Point2d& operator[](int index)const;
      bool operator==(const Polyline& rightSide);
      bool operator!=(const Polyline& rightSide);
      Polyline operator+(const Polyline& rightSide);

      Polygon getPrintline()const;
      int getCapacity()const;
      int getSize()const;
      int getRotateDegree()const;
      int getRotateByX()const;
      int getRotateByY()const;
      char getPos()const;
  private:
      Polygon printline;
  };

}

#endif
