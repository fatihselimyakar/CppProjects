#include "PolygonVect.h"
//HELPER FUNCTION
namespace{
    double CircleEquationY(double centerX,double centerY,int radius,double yourX){
        return sqrt(pow(radius,2)-pow(yourX-centerX,2))+centerY;
        //WİTH THE CİRCLE EQUATION I FİND THE X'S Y
    }
}
namespace SHAPE{
    PolygonVect::PolygonVect()noexcept:Polygon(0,0,0,'c'){/*EMPTY*/}

    //THIS CONSTRUCTOR GET THE POINT2D VECTOR AND GENERATES THE POLYGONDYN
    PolygonVect::PolygonVect(vector<Point2d>pointVector)noexcept:Polygon(){ polyvector=pointVector; }

    //THIS CONSTRUCTOR GET A RACTANGLE AND GENERATES THE POLYGONDYN
    PolygonVect::PolygonVect(Rectangle rec)throw(MyException):Polygon(){
        //I FIND THE POINTS ACCORDING TO STARTING POINTS TO ALL CORNER POİNTS WITH WITH AND HEIGHT
        Point2d pt(rec.getPosX(),rec.getPosY());
        polyvector.push_back(pt);
        pt.set(rec.getPosX()+rec.getWidth(),rec.getPosY());
        polyvector.push_back(pt);
        pt.set(rec.getPosX()+rec.getWidth(),rec.getPosY()+rec.getHeight());
        polyvector.push_back(pt);
        pt.set(rec.getPosX(),rec.getPosY()+rec.getHeight());
        polyvector.push_back(pt);

        rotate=0;
        pos_x=0;
        pos_y=0;
        if(rec.getPosition()=='i'||rec.getPosition()=='c')
            position=rec.getPosition();
        else
            throw MyException("Position is not true");
    }

    //THIS CONSTRUCTOR GET A TRIANGLE AND GENERATES THE POLYGONDYN
    PolygonVect::PolygonVect(Triangle tri)throw(MyException):Polygon(){
        Point2d pt(tri.getTriX(),tri.getTriY());
        polyvector.push_back(pt);
        pt.set(tri.getTri2X(),tri.getTri2Y());
        polyvector.push_back(pt);
        pt.set(tri.getTri3X(),tri.getTri3Y());
        polyvector.push_back(pt);

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
    PolygonVect::PolygonVect(Circle cir)throw(MyException):Polygon(){
        polyvector.reserve(100);
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
        Point2d pt;
        //FOR THE BOTTOM SIDE
        for(int i=0;i<50;i+=1,startingX+=increase){
            startingY=CircleEquationY(cir.getCenterCoordX(),cir.getCenterCoordY(),cir.getRadius(),startingX);
            pt.set(startingX,startingY);
            polyvector.push_back(pt);
        }
        //FOR THE TOP SIDE
        startingX=cir.getCenterCoordX()-cir.getRadius()+increase;
        auto it = polyvector.end();
        for(int i=0;i<50;i+=1,startingX+=increase){
            startingY=CircleEquationY(cir.getCenterCoordX(),cir.getCenterCoordY(),cir.getRadius(),startingX);
            reverseY=cir.getCenterCoordY()-(startingY-cir.getCenterCoordY());
            pt.set(startingX,reverseY);
            polyvector.insert(it,pt);
        }
    }

    //OVERRIDED DRAW FUNCTION
    void PolygonVect::draw(ostream& outputStream)const throw(MyException){
        if( getPosition()=='c'){
    		outputStream<<R"(<svg version="1.1")"<<endl;
    		outputStream<<R"(baseProfile="full" width="100%" height="100%")"<<endl;
    		outputStream<<R"(xmlns="http://www.w3.org/2000/svg">
    	<polygon points=")";
        //FOR THE UNKNOWN ARRAY SIZE I USED FOR LOOP
            for(int i=0;i< polyvector.size();i++)
                outputStream<<' '<<polyvector[i].getX()<<','<<polyvector[i].getY();
            outputStream<<R"(" stroke="black" fill="red" />)"<<endl;
    	}
    	else if( getPosition()=='i'){
    		outputStream<<R"(<polygon points=")";
            //FOR THE UNKNOWN ARRAY SIZE I USED FOR LOOP
            for(int i=0;i< polyvector.size();i++)
                outputStream<<' '<<polyvector[i].getX()<<','<<polyvector[i].getY();
            outputStream<<R"(" fill="green" stroke="black" transform="rotate()"<< getRotate()<<R"(,)"<< getPosX()<<R"(,)"<< getPosY()<<")\" />"<<endl;
    	}
        else
            throw MyException("UNVALID POSITON VALUE IN DRAW");

        return;
    }

    const Polygon::Point2d& PolygonVect::operator[](int index)const throw(MyException){
        if(index<0 || index>=polyvector.size())
            throw MyException("Your index value isn't true");
        return polyvector[index];
    }

}
