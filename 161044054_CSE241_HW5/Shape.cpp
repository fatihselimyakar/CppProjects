#include "Shape.h"
namespace SHAPE{
    //SHAPE CONSTRUCTORS
    Shape::Shape()noexcept:pos_x(0.0),pos_y(0.0),rotate(0),position('c'){ name="default"; }
    Shape::Shape(double x,double y,int newRotate,char p)throw(MyException){
        name="default";
        if(x<0||y<0)
            throw MyException("Pos_x and pos_y are not smaller than 0");
        else{
            pos_x=x;
            pos_y=y;
        }
        if(newRotate>360||newRotate<0)
            throw MyException("Rotate must be between the 0 and 360");
        else
            rotate=newRotate;
        if(p=='c'||p=='i')
            position=p;
        else
            throw MyException("Position must be c or i");

    }
    Shape::Shape(double x,double y)throw(MyException){
        name="default";
        if(x<0||y<0)
            throw MyException("Pos_x and pos_y are not smaller than 0");
        else{
            pos_x=x;
            pos_y=y;
        }
        rotate=0;
        position='c';
    }

    //COMPARE OPERATOR OVERLOADS RESPECT TO AREA
    const bool Shape::operator==(const Shape& rightSide)const noexcept{ return area()==rightSide.area(); }
    const bool Shape::operator!=(const Shape& rightSide)const noexcept{ return area()!=rightSide.area(); }
    const bool Shape::operator>(const Shape& rightSide)const noexcept{ return  area()>rightSide.area(); }
    const bool Shape::operator<(const Shape& rightSide)const noexcept{ return  area()<rightSide.area(); }
    const bool Shape::operator>=(const Shape& rightSide)const noexcept{ return  area()>=rightSide.area(); }
    const bool Shape::operator<=(const Shape& rightSide)const noexcept{ return  area()<=rightSide.area(); }

    //GETTERS
    double Shape::getPosX()const noexcept{ return pos_x; }
    double Shape::getPosY()const noexcept{ return pos_y; }
    int Shape::getRotate()const noexcept{ return rotate; }
    string Shape::getName()const noexcept{ return name; }
    char Shape::getPosition()const noexcept{return position; }

    //SETTERS
    void Shape::set(double x,double y,int newRotate,char p) throw(MyException){
        if(x<0||y<0)
            throw MyException("Pos_x and pos_y are not smaller than 0");
        else{
            pos_x=x;
            pos_y=y;
        }
        if(newRotate<=360&&newRotate>=0)
            throw MyException("Rotate between the 0 and 360");
        else
            rotate=newRotate;
        if(p=='c'||p=='i')
            throw MyException("Position must be c or i");
        else
            position=p;
        return;
    }
    void Shape::set(double x,double y) throw(MyException){
        if(x<0||y<0)
            throw MyException("Pos_x and pos_y are not smaller than 0");
        else{
            pos_x=x;
            pos_y=y;
        }
        return;
    }

    //GLOBAL FUNCTION'S IMPLEMENTATIONS
    //(except CONVERTALL that is end of the ComposedShape)

    //In this function in printing I use the virtual overrided function draw(All derived class have this function) for the code reusability
    ostream& operator<<(ostream& outputStream,const Shape& PrintingShape) noexcept{
        PrintingShape.draw(outputStream);
        return outputStream;
    }

    //I use global overloaded << operator for the printing vector beacuse << is not shape type dependent
    void printAll(ostream& outputStream,const vector<Shape*>PrintingVector)noexcept{
        for(int i=0;i<PrintingVector.size();i++)
            outputStream<<(*PrintingVector[i]);
        outputStream<<"</svg>";
        return;
    }

    //I use other global functions in processing this function for printing PolygonDyn and PolygonVect
    void printPoly(ostream& outputStream,const vector<Shape*>PrintingVector)throw(MyException){
        for(int i=0;i<PrintingVector.size();i++){
            if(PrintingVector[i]->getName()!="polygon")//if object is not polygon error occurs
                throw MyException("UNVALID SHAPE TYPE IN PRINTPOLLY");
            else
                outputStream<<(*PrintingVector[i]);
        }
        outputStream<<"</svg>";
        return;
    }

    //I IMPLEMENT THE SIMPLE BUBBLE SORT ALGORITHM WITH MY VECTORS AND THEIR AREA FUNCTIONS
    void sortShapes(vector<Shape*>& SortingVector)noexcept{
        for(int i=0;i<SortingVector.size()-1;i++){
            for(int j=0;j<SortingVector.size()-i-1;j++){
                if (SortingVector[j]->area()>SortingVector[j+1]->area()){
                    Shape* temp=SortingVector[j];
                    SortingVector[j]=SortingVector[j+1];
                    SortingVector[j+1]=temp;
                }
            }
        }
        return;
    }

}
