#include "Triangle.h"
namespace SHAPE{
    //IN DERIVED CLASS CONSTRUCTORS I USE THE BASE CLASS CONSTRUCTORS FOR THE INHERITENCE
    Triangle::Triangle()noexcept:Shape(),triX(0.0),tri2X(0.0),tri3X(0.0),triY(0.0),tri2Y(0.0),tri3Y(0.0){ name="triangle"; }
    Triangle::Triangle(int lateralVal,char positionVal,double trixVal,double triyVal,double tri2xVal,double tri2yVal,double tri3xVal,double tri3yVal,int rotateVal,double pos_xVal,double pos_yVal)throw(MyException):Shape(pos_xVal,pos_yVal,rotateVal,positionVal){
        name="triangle";
        if(trixVal<0||tri2xVal<0||tri3xVal<0||triyVal<0||tri2yVal<0||tri3yVal<0||lateralVal<0)
            throw MyException("UNVALID TRIANGLE VALUES");
        else{
            triX=trixVal;
            triY=triyVal;
            tri2X=tri2xVal;
            tri2Y=tri2yVal;
            tri3X=tri3xVal;
            tri3Y=tri3yVal;
            lateral=lateralVal;
        }
    }
    Triangle::Triangle(int lateralVal,char positionVal)throw(MyException):Shape(0.0,0.0,0,positionVal),triX(0.),tri2X(0.),tri3X(0.),triY(0.),tri2Y(0.),tri3Y(0.){
        name="triangle";
        if(lateralVal<0)
            throw MyException("UNVALID TRIANGLE VALUES");
        else
            lateral=lateralVal;
    }
    Triangle::Triangle(double trixVal,double triyVal,double tri2xVal,double tri2yVal,double tri3xVal,double tri3yVal)noexcept:Shape(),triX(trixVal),tri2X(tri2xVal),tri3X(tri3xVal),triY(triyVal),tri2Y(tri2yVal),tri3Y(tri3yVal){ name="triangle"; }

    //OVERRIDED FUNCTIONS
    double Triangle::area()const noexcept{ return (lateral*lateral*SQR3)/4.; }
    double Triangle::perimeter()const noexcept{ return 3*lateral; }

    void Triangle::draw(ostream& outputStream)const throw(MyException){
        if(this->position=='c'){
    		outputStream<<R"(<svg version="1.1")"<<endl;
    		outputStream<<R"(baseProfile="full")"<<endl;
    		outputStream<<R"(height=")"<<this->lateral<<R"(" width=")"<<this->lateral<<R"(" xmlns="http://www.w3.org/2000/svg">>
    	<polygon points=")"<<this->lateral/2.0<<R"( 0 0 )"<<this->lateral*SQR3DIV2<<R"( )"<<this->lateral<<R"( )"<<this->lateral*SQR3DIV2<<R"(" fill="red" />)"<<endl;
    	}
    	else if(this->position=='i')
    		outputStream<<R"(<polygon points=")"<<this->triX<<R"( )"<<this->triY<<R"( )"<<this->tri2X<<R"( )"<<this->tri2Y<<R"( )"<<this->tri3X<<R"( )"<<this->tri3Y<<R"(" fill="green" transform="rotate()"<<this->rotate<<R"(,)"<<this->pos_x<<R"(,)"<<this->pos_y<<")\" />"<<endl;
        else
            throw MyException("UNVALID POSITION");

    	return;
    }

    //IN OPERATOR ++,-- OVERLOADS BECAUSE OF THE RETURNIN PROBLEMS I USE THE POINTERS
    Shape& Triangle::operator++()noexcept{
         Triangle t1(lateral,position,++triX,++triY,++tri2X,++tri2Y,++tri3X,++tri3Y,rotate,pos_x,pos_y);
         Shape*temp=&t1;
         return *temp;
     }
    Shape& Triangle::operator++(int ignore)noexcept{
        Triangle t1(lateral,position,triX++,triY++,tri2X++,tri2Y++,tri3X++,tri3Y++,rotate,pos_x,pos_y);
        Shape*temp=&t1;
        return *temp;
    }
    Shape& Triangle::operator--()noexcept{
        Triangle t1(lateral,position,--triX,--triY,--tri2X,--tri2Y,--tri3X,--tri3Y,rotate,pos_x,pos_y);
        Shape*temp=&t1;
        return *temp;
     }
    Shape& Triangle::operator--(int ignore)noexcept{
        Triangle t1(lateral,position,triX--,triY--,tri2X--,tri2Y--,tri3X--,tri3Y--,rotate,pos_x,pos_y);
        Shape*temp=&t1;
        return *temp;
    }

    void Triangle::set(int lateralVal,char positionVal,double trixVal,double triyVal,double tri2xVal,double tri2yVal,double tri3xVal,double tri3yVal,int rotateVal,double pos_xVal,double pos_yVal)throw(MyException){
        if(lateralVal>0)
    		lateral=lateralVal;
    	else
    		throw MyException("Program aborted!(UNVALID LATERAL)");

    	if(positionVal=='i'||positionVal=='c')
    		position=positionVal;
    	else
    		throw MyException("Program aborted!(UNVALID POSITION)");

    	if(trixVal>=0)
    		triX=trixVal;
    	else
    		throw MyException("Program aborted!(UNVALID COORDINATE)");

    	if(triyVal>=0)
    		triY=triyVal;
    	else
    		throw MyException("Program aborted!(UNVALID COORDINATE)");

    	if(tri2xVal>=0)
    		tri2X=tri2xVal;
    	else
    		throw MyException("Program aborted!(UNVALID COORDINATE)");

    	if(tri2yVal>=0)
    		tri2Y=tri2yVal;
    	else
    		throw MyException("Program aborted!(UNVALID COORDINATE)");

    	if(tri3xVal>=0)
    		tri3X=tri3xVal;
    	else
    		throw MyException("Program aborted!(UNVALID COORDINATE)");

    	if(tri3yVal>=0)
    		tri3Y=tri3yVal;
    	else
    		throw MyException("Program aborted!(UNVALID COORDINATE)");

    	rotate=rotateVal;

    	return;
    }

    //GETTERS
    double Triangle::getTriX()const noexcept{ return triX; }
    double Triangle::getTriY()const noexcept{ return triY; }
    double Triangle::getTri2X()const noexcept{ return tri2X; }
    double Triangle::getTri2Y()const noexcept{ return tri2Y; }
    double Triangle::getTri3X()const noexcept{ return tri3X; }
    double Triangle::getTri3Y()const noexcept{ return tri3Y; }
    int Triangle::getLateral()const noexcept{ return lateral; }


}
