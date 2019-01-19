#include "PolygonDyn.h"
//HELPER FUNTION
namespace{
    double CircleEquationY(double centerX,double centerY,int radius,double yourX){
        return sqrt(pow(radius,2)-pow(yourX-centerX,2))+centerY;
        //WİTH THE CİRCLE EQUATION I FİND THE X'S Y
    }
}

namespace SHAPE{
    PolygonDyn::PolygonDyn()noexcept:Polygon(0,0,0,'c'),capacity(50){ points=new Point2d[capacity]; }

    //THIS CONSTRUCTOR GET THE POINT2D VECTOR AND GENERATES THE POLYGONDYN
    PolygonDyn::PolygonDyn(vector<Point2d>pointVector)throw(MyException):Polygon(){
        capacity=pointVector.capacity();
        size=pointVector.size();
        position='c';
        rotate=0;
        pos_x=0;
        pos_y=0;
        if(capacity<=0||size<=0)
            throw MyException("Error your constructor isn't true");
        points= new Point2d[capacity];
        for(int i=0;i<size;i++)
            points[i]=pointVector[i];
    }

    PolygonDyn::PolygonDyn(int newCapacity,int newSize)throw(MyException):Polygon(){
        rotate=0;
        pos_x=0;
        pos_y=0;
        position='c';
        capacity=newCapacity;
        size=newSize;
        if(capacity<=0||size<=0)
            throw MyException("Error your constructor isn't true");
        points=new Point2d[capacity];
    }

    //THIS CONSTRUCTOR GET A RACTANGLE AND GENERATES THE POLYGONDYN
    PolygonDyn::PolygonDyn(Rectangle rec)throw(MyException):Polygon(){
        points=new Point2d[4];
        //I FIND THE POINTS ACCORDING TO STARTING POINTS TO ALL CORNER POİNTS WITH WITH AND HEIGHT
        points[0].set(rec.getPosX(),rec.getPosY());
        points[1].set(rec.getPosX()+rec.getWidth(),rec.getPosY());
        points[2].set(rec.getPosX()+rec.getWidth(),rec.getPosY()+rec.getHeight());
        points[3].set(rec.getPosX(),rec.getPosY()+rec.getHeight());

        capacity=4;
        size=4;
        rotate=0;
        pos_x=0;
        pos_y=0;
        if(rec.getPosition()=='i'||rec.getPosition()=='c')
            position=rec.getPosition();
        else
            throw MyException("Position is not true");
    }

    //THIS CONSTRUCTOR GET A TRIANGLE AND GENERATES THE POLYGONDYN
    PolygonDyn::PolygonDyn(Triangle tri)throw(MyException):Polygon(){
        points=new Point2d[3];
        //DIRECTLY I ASSIGNED THE POINTS
        points[0].set(tri.getTriX(),tri.getTriY());
        points[1].set(tri.getTri2X(),tri.getTri2Y());
        points[2].set(tri.getTri3X(),tri.getTri3Y());
        capacity=3;
        size=3;
        if(tri.getRotate()<=360&&tri.getRotate()>=0)
            rotate=tri.getRotate();
        else
            throw MyException("degree is not true");

        if(tri.getPosition()=='i'||tri.getPosition()=='c')
            position=tri.getPosition();
        else
            throw MyException("Position is not true");

    	pos_x=tri.getPosX();
        pos_y=tri.getPosY();
    }

    //THIS CONSTRUCTOR GET A CIRCLE AND GENERATES THE POLYGONDYN
    PolygonDyn::PolygonDyn(Circle cir)throw(MyException):Polygon(){
        points=new Point2d[100];
        capacity=100;
        size=100;
        if(cir.getRotate()<=360&&cir.getRotate()>=0)
            rotate=cir.getRotate();
        else
            throw MyException("degree is not true");

        if(cir.getPosition()=='i'||cir.getPosition()=='c')
            position=cir.getPosition();
        else
            throw MyException("Position is not true");
        //I USED THE CIRCLE EQUATION WHILE I AM FINDING THE 100 POINT
        //AND I USED HELPER FUNTION "CircleEquationY()" TOO
        pos_x=cir.getPosX();
        pos_y=cir.getPosY();
        double increase=(2*cir.getRadius())/50.1;
        double startingX=cir.getCenterCoordX()-cir.getRadius();
        double startingY;
        double reverseY;
        //FOR THE BOTTOM SIDE
        for(int i=0;i<50;i+=1,startingX+=increase){
            startingY=CircleEquationY(cir.getCenterCoordX(),cir.getCenterCoordY(),cir.getRadius(),startingX);
            points[i].set(startingX,startingY);
        }
        //FOR THE TOP SIDE
        startingX=cir.getCenterCoordX()-cir.getRadius()+increase;
        for(int i=0;i<50;i+=1,startingX+=increase){
            startingY=CircleEquationY(cir.getCenterCoordX(),cir.getCenterCoordY(),cir.getRadius(),startingX);
            reverseY=cir.getCenterCoordY()-(startingY-cir.getCenterCoordY());
            points[99-i].set(startingX,reverseY);
        }
    }

    //OVERLOADED [] OPERATOR
    Polygon::Point2d& PolygonDyn::operator[](int index)const throw(MyException){
        if(index<0 || index>=size)
            throw MyException("Your index value isn't true");
        return points[index];
    }

    //OVERRIDED FUNCTION
    void PolygonDyn::draw(ostream& outputStream)const throw(MyException){
        if( getPosition()=='c'){
    		outputStream<<R"(<svg version="1.1")"<<endl;
    		outputStream<<R"(baseProfile="full" width="100%" height="100%")"<<endl;
    		outputStream<<R"(xmlns="http://www.w3.org/2000/svg">
    	<polygon points=")";
        //FOR THE UNKNOWN ARRAY SIZE I USED FOR LOOP
            for(int i=0;i< getSize();i++)
                outputStream<<' '<<points[i].getX()<<','<<points[i].getY();
            outputStream<<R"(" stroke="black" fill="red" />)"<<endl;
    	}
    	else if( getPosition()=='i'){
    		outputStream<<R"(<polygon points=")";
            //FOR THE UNKNOWN ARRAY SIZE I USED FOR LOOP
            for(int i=0;i< getSize();i++)
                outputStream<<' '<<points[i].getX()<<','<<points[i].getY();
            outputStream<<R"(" fill="green" stroke="black" transform="rotate()"<< getRotate()<<R"(,)"<< getPosX()<<R"(,)"<< getPosY()<<")\" />"<<endl;
    	}
        else
            throw MyException("UNVALID POSITION TYPE IN THE DRAW");

        return;
    }

    //GETTERS
    int PolygonDyn::getCapacity()const noexcept{ return capacity; }
    int PolygonDyn::getSize()const noexcept{ return size; }

    PolygonDyn& PolygonDyn::operator=(const PolygonDyn& rightSide)noexcept{//assignment operator
        if(*this==rightSide)
            return *this;

        delete[]points;
		points=new Point2d[rightSide.capacity];
		for(int i=0;i<rightSide.size;i++)
			points[i]=rightSide.points[i];
		size=rightSide.size;
		capacity=rightSide.capacity;
        rotate=rightSide.rotate;
        pos_x=rightSide.pos_x;
        pos_y=rightSide.pos_y;
        position=rightSide.position;

		return *this;
    }

    PolygonDyn::PolygonDyn(const PolygonDyn& object)noexcept{//copy constructor
        points=new Point2d[ getCapacity()];
        capacity= getCapacity();
        size= getSize();
        rotate= getRotate();
        pos_x= getPosX();
        pos_y= getPosY();
        position= getPosition();
        for(int i=0;i<size;i++)
            points[i]= points[i];
    }

    PolygonDyn::~PolygonDyn()noexcept{ delete[] points; }//destructor
}
