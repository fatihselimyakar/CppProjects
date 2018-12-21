#include "polygon.h"
//THIS NAMESPACE FOR HELPER FUNCTION
namespace{
    double CircleEquationY(double centerX,double centerY,int radius,double yourX){
        return sqrt(pow(radius,2)-pow(yourX-centerX,2))+centerY;
        //WİTH THE CİRCLE EQUATION I FİND THE X'S Y
    }
}
//THIS NAMESPACE FOR POLYGON CLASS AND FUNTIONS
namespace POLYGON{
    //POINT2D'CONSTRUCTOR IT GENERATES X AND Y
    Polygon::Point2d::Point2d(double newX,double newY){
        if(newX>=0&&newY>=0){
            polygonX=newX;
            polygonY=newY;
        }
        else{
            cout<<"Error your constructor isn't true"<<endl;
            exit(1);
        }
    }
    void Polygon::Point2d::set(double newX,double newY){
        if(newX>=0&&newY>=0){
            polygonX=newX;
            polygonY=newY;
        }
        else{
            cout<<"Error your set function isn't true"<<endl;
            exit(1);
        }
    }
    double Polygon::Point2d::getX()const{ return polygonX; }
    double Polygon::Point2d::getY()const{ return polygonY; }
    //POLYGON CONSTRUCTORS
    //GENERATES ACCORDING TO POINT2D VECTOR
    Polygon::Polygon(vector<Point2d>pointVector){
        capacity=pointVector.capacity();
        size=pointVector.size();
        pos='c';
        rotateDegree=0;
        rotateByX=0;
        rotateByY=0;
        if(capacity<=0||size<=0){
            cout<<"Error your constructor isn't true"<<endl;
            exit(1);
        }
        points= new Point2d[capacity];
        for(int i=0;i<size;i++)
            points[i]=pointVector[i];
    }
    Polygon::Polygon():capacity(50),size(0),rotateDegree(0),rotateByX(0),rotateByY(0),pos('c'){ points=new Point2d[capacity]; }
    //COPY CONSTRUCTOR
    Polygon::Polygon(const Polygon& object){
        points=new Point2d[object.getCapacity()];
        capacity=object.getCapacity();
        size=object.getSize();
        rotateDegree=object.getRotateDegree();
        rotateByX=object.getRotateByX();
        rotateByY=object.getRotateByY();
        pos=object.getPos();
        for(int i=0;i<size;i++)
            points[i]=object.points[i];
    }
    //THIS CONSTRUCTOR GENERATE THE POLYGON TYPE WITH SIZE AND CAPACITY
    Polygon::Polygon(int newCapacity,int newSize){
        rotateDegree=0;
        rotateByX=0;
        rotateByY=0;
        pos='c';
        capacity=newCapacity;
        size=newSize;
        if(capacity<=0||size<=0){
            cout<<"Error your constructor isn't true"<<endl;
            exit(1);
        }
        points=new Point2d[capacity];
    }
    //THIS CONSTRUCTOR GENERATE THE POLYGON TYPE WITH RECTANGLE TYPE PARAMETER
    Polygon::Polygon(rectangle rec){
        points=new Point2d[4];
        //I FIND THE POINTS ACCORDING TO STARTING POINTS TO ALL CORNER POİNTS WITH WITH AND HEIGHT
        points[0].set(rec.getRectX(),rec.getRectY());
        points[1].set(rec.getRectX()+rec.getWidth(),rec.getRectY());
        points[2].set(rec.getRectX()+rec.getWidth(),rec.getRectY()+rec.getHeight());
        points[3].set(rec.getRectX(),rec.getRectY()+rec.getHeight());

        capacity=4;
        size=4;
        rotateDegree=0;
        rotateByX=0;
        rotateByY=0;
        if(rec.getPosition()=='i'||rec.getPosition()=='c'){
            pos=rec.getPosition();
        }
        else{
            cout<<"Position is not true"<<endl;
            exit(1);
        }
    }
    //THIS CONSTRUCTOR GENERATE THE POLYGON TYPE WITH TRIANGLE TYPE PARAMETER
    Polygon::Polygon(triangle tri){
        points=new Point2d[3];
        //DIRECTLY I ASSIGNED THE POINTS
        points[0].set(tri.getTriX(),tri.getTriY());
        points[1].set(tri.getTri2X(),tri.getTri2Y());
        points[2].set(tri.getTri3X(),tri.getTri3Y());
        capacity=3;
        size=3;
        if(tri.getRotate()<=360&&tri.getRotate()>=0)
            rotateDegree=tri.getRotate();
        else{
            cout<<"degree is not true"<<endl;
            exit(1);
        }
        if(tri.getPosition()=='i'||tri.getPosition()=='c'){
            pos=tri.getPosition();
        }
        else{
            cout<<"Position is not true"<<endl;
            exit(1);
        }
    	rotateByX=tri.getTriRotateByX();
        rotateByY=tri.getTriRotateByY();

    }
    //THIS CONSTRUCTOR GENERATE THE POLYGON TYPE WITH CIRCLE TYPE PARAMETER
    Polygon::Polygon(circle cir){
        points=new Point2d[100];
        capacity=100;
        size=100;
        if(cir.getRotate()<=360&&cir.getRotate()>=0)
            rotateDegree=cir.getRotate();
        else{
            cout<<"degree is not true"<<endl;
            exit(1);
        }
        if(cir.getPosition()=='i'||cir.getPosition()=='c'){
            pos=cir.getPosition();
        }
        else{
            cout<<"Position is not true"<<endl;
            exit(1);
        }
        //I USED THE CIRCLE EQUATION WHILE I AM FINDING THE 100 POINT
        //AND I USED HELPER FUNTION "CircleEquationY()" TOO
        rotateByX=cir.getCirRotateByX();
        rotateByY=cir.getCirRotateByY();
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
    //ASSIGNMENT OPERATOR OVERLOAD
    Polygon& Polygon::operator=(const Polygon& rightSide){
        if(*this==rightSide){
            return *this;
        }
        delete[]points;
		points=new Point2d[rightSide.capacity];
		for(int i=0;i<rightSide.size;i++)
			points[i]=rightSide.points[i];
		size=rightSide.size;
		capacity=rightSide.capacity;
        rotateDegree=rightSide.rotateDegree;
        rotateByX=rightSide.rotateByX;
        rotateByY=rightSide.rotateByY;
        pos=rightSide.pos;

		return *this;
    }
    Polygon::Point2d& Polygon::operator[](int index)const{
        if(index<0 || index>=size){
            cout<<"Your index value isn't true"<<endl;
            exit(1);
        }
        return points[index];
    }
    //CONVERSION OPERATOR OVERLOADS
    bool Polygon::operator==(const Polygon& rightSide){
        if((capacity!=rightSide.capacity)||(size!=rightSide.size)||(rotateDegree!=rightSide.rotateDegree)||(rotateByY!=rightSide.rotateByY)||(rotateByX!=rightSide.rotateByX)||(pos!=rightSide.pos))
            return false;
        for(int i=0;i<size;i++){
            int zero=points[i].getX()-rightSide.points[i].getX();
            int zero2=points[i].getY()-rightSide.points[i].getY();
            if(zero!=0||zero2!=0)
                return false;
        }
        return true;
    }
    //IT IS REVERSE TO "==" BECAUSE OF IT I USE OVERLOADED "=="
    bool Polygon::operator!=(const Polygon& rightSide){
        return !(*this==rightSide);
    }
    //FOR ADD THE NEW ELEMENTS THE POINTS ARRAY
    Polygon Polygon::operator+(const Polygon& rightSide){
        Polygon temp(capacity+rightSide.capacity,size+rightSide.size);
		int i;
		for(i=0;i<size;i++)
			temp.points[i]=points[i];
		for(int j=0;j<rightSide.size;j++){
			temp.points[j+i]=rightSide.points[j];
		}
		return temp;
    }
    //FOR GETTING FUCTIONS.
    int Polygon::getCapacity()const{ return capacity; }
    int Polygon::getSize()const{ return size; }
    int Polygon::getRotateDegree()const{ return rotateDegree; }
    double Polygon::getRotateByX()const{ return rotateByX; }
    double Polygon::getRotateByY()const{ return rotateByY; }
    char Polygon::getPos()const{ return pos; }

    //THIS OVERLOAD FOR THE PRINTING SVG
    ostream& operator<<(ostream& outputStream,const Polygon& object){
        if(object.getPos()=='c'){
    		outputStream<<R"(<svg version="1.1")"<<endl;
    		outputStream<<R"(baseProfile="full" width="100%" height="100%")"<<endl;
    		outputStream<<R"(xmlns="http://www.w3.org/2000/svg">
    	<polygon points=")";
        //FOR THE UNKNOWN ARRAY SIZE I USED FOR LOOP
        for(int i=0;i<object.getSize();i++){
            outputStream<<' '<<object[i].getX()<<','<<object[i].getY();
        }
        outputStream<<R"(" stroke="black" fill="red" />)"<<endl;
    	}
    	else if(object.getPos()=='i'){
    		outputStream<<R"(<polygon points=")";
            //FOR THE UNKNOWN ARRAY SIZE I USED FOR LOOP
            for(int i=0;i<object.getSize();i++){
                outputStream<<' '<<object[i].getX()<<','<<object[i].getY();
            }
            outputStream<<R"(" fill="green" stroke="black" transform="rotate()"<<object.getRotateDegree()<<R"(,)"<<object.getRotateByX()<<R"(,)"<<object.getRotateByY()<<")\" />"<<endl;
    	}

        return outputStream;
    }

}
