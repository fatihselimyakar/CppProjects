#ifndef POLYGON_H

#define POLYGON_H
#include<iostream>
#include<vector>
#include<cmath>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
using namespace std;
//I OPENED THE POLYGON NAMESPACE TWO OF FIRST FOR THE PROTOTYPES
//THEN I WILL OPEN THE .CPP FOR IMPLEMENTS
namespace POLYGON{

    class Polygon{
  public:
    class Point2d;
    //CONSTRUCTORS
    Polygon();
    Polygon(vector<Point2d>pointVector);
    Polygon(int newCapacity,int newSize);
    Polygon(rectangle rec);
    Polygon(triangle tri);
    Polygon(circle cir);
    Polygon(const Polygon& object);//copy constructor

    //OPERATOR OVERLOADS
    Polygon& operator=(const Polygon& rightSide);//assignment for big three
    Point2d& operator[](int index)const;
    bool operator==(const Polygon& rightSide);
    bool operator!=(const Polygon& rightSide);
    Polygon operator+(const Polygon& rightSide);
    friend ostream& operator<<(ostream& outputStream,const Polygon& object);

    //GETTERS
    int getCapacity()const;
    int getSize()const;
    int getRotateDegree()const;
    double getRotateByX()const;
    double getRotateByY()const;
    char getPos()const;

    //FOR THE 2D POINTS THE "Point2d" CLASS
    class Point2d{
    public:
   	Point2d(){/*intentionally empty*/}
        Point2d(double newX,double newY);
        void set(double newX,double newY);
        double getX()const;
        double getY()const;
    private:
        double polygonX;
        double polygonY;
    };

    ~Polygon(){ delete[] points; }//destructor
    private:
        //MEMBERS
        Point2d *points;//IT HOLDS THE POINTS
        int capacity;//IT IS THE CAPACITY OF "*points"
        int size;//IT IS THE SIZE OF "*points"
        int rotateDegree;//IT IS THE DEGREE OF ROTATE FOR THE RECTANGLE,TRIANGLE,CIRCLE
        double rotateByX;//REFERENCE POINT'S X
        double rotateByY;//REFERENCE POINT'S Y
        char pos;//BEING INNER OR CONTAINER ISSUE

  };

}


#endif
