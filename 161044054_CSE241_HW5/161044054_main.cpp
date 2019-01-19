#include "ComposedShape.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
using namespace SHAPE;
int main(){
    try{
        ofstream outputStream;

        Rectangle r1(23,8,'i'),r2(330,150,0,0,0,'c');
        Triangle t1(20,'i'),t2(250,'c',125,0,0,SQR3DIV2*250,250,SQR3DIV2*250,0,0,0);
        Circle c1(18,'i'),c2(0,0,0,'c',290,290,290);
        ComposedShape compRR(r1,r2),compRT(t1,r2),compRC(c1,r2),compTR(r1,t2),compTT(t1,t2),compTC(c1,t2),compCT(t1,c2),compCR(r1,c2),compCC(c1,c2);
        PolygonDyn pd(c2),pd2(r1);
        PolygonVect pv(t2);

        //GLOBAL << OVERLOAD AND SHAPE HYERARCHY TESTING
        outputStream.open("singleRectangle.svg");
        outputStream<<r2;
        outputStream<<"</svg>";
        outputStream.close();

        outputStream.open("singleCircle.svg");
        outputStream<<c2;
        outputStream<<"</svg>";
        outputStream.close();

        outputStream.open("singleTriangle.svg");
        outputStream<<t2;
        outputStream<<"</svg>";
        outputStream.close();

        outputStream.open("singlePolygonDyn.svg");
        outputStream<<pd;
        outputStream<<"</svg>";
        outputStream.close();

        outputStream.open("singlePolygonVect.svg");
        outputStream<<pv;
        outputStream<<"</svg>";
        outputStream.close();

        outputStream.open("ComposedRR.svg");
        compRR.optimalFit();
        outputStream<<compRR;
        outputStream.close();

        outputStream.open("ComposedRT.svg");
        compRT.optimalFit();
        outputStream<<compRT;
        outputStream.close();

        outputStream.open("ComposedRC.svg");
        compRC.optimalFit();
        outputStream<<compRC;
        outputStream.close();

        outputStream.open("ComposedTR.svg");
        compTR.optimalFit();
        outputStream<<compTR;
        outputStream.close();

        outputStream.open("ComposedTT.svg");
        compTT.optimalFit();
        outputStream<<compTT;
        outputStream.close();

        outputStream.open("ComposedTC.svg");
        compTC.optimalFit();
        outputStream<<compTC;
        outputStream.close();

        outputStream.open("ComposedCT.svg");
        compCT.optimalFit();
        outputStream<<compCT;
        outputStream.close();

        outputStream.open("ComposedCR.svg");
        compCR.optimalFit();
        outputStream<<compCR;
        outputStream.close();

        outputStream.open("ComposedCC.svg");
        compCC.optimalFit();
        outputStream<<compCC;
        outputStream.close();

        //GLOBAL FUNCTION TESTING

        //PRINTALL
        //In this testing I use the compCC's vector as a sample Shape* Vector
        vector<Shape*>SampleVector=compCC.getShapePtrVec();
        outputStream.open("printAllSample.svg");
        printAll(outputStream,SampleVector);
        outputStream.close();

        //CONVERTALL
        //In this testing I use the compTT's vector as a sample Shape* Vector
        vector<Shape*>SampleVector2=compTT.getShapePtrVec();
        outputStream.open("convertAllSample.svg");
        printAll(outputStream,convertAll(SampleVector2));
        outputStream.close();

        //PRINTPOLLY
        //In this testing I use the SampleVecPoly as a sample Shape* Vector
        vector<Shape*>SampleVecPoly;
        SampleVecPoly.push_back(&pv);
        SampleVecPoly.push_back(&pd2);
        outputStream.open("printPolySample.svg");
        printPoly(outputStream,SampleVecPoly);
        outputStream.close();

        //SORTSHAPES
        cout<<"****Global \"sortShapes\" Function Test****"<<endl;
        vector<Shape*>SampleVector3;//I generate new Shape* vector and filled by push_back
        SampleVector3.push_back(&t2);
        SampleVector3.push_back(&c2);
        SampleVector3.push_back(&r2);
        SampleVector3.push_back(&c1);
        SampleVector3.push_back(&r1);
        cout<<"Unsorted Areas:";
        for(int i=0;i<SampleVector3.size();i++)
            cout<<SampleVector3[i]->area()<<' ';
        cout<<"\nSorted Areas:";
        sortShapes(SampleVector3);
        for(int i=0;i<SampleVector3.size();i++)
            cout<<SampleVector3[i]->area()<<' ';

        //AREA TEST
        cout<<"\n\n****Area Function Test****"<<endl;
        cout<<"Rectangle(r1) area:"<<r1.area()<<endl;
        cout<<"Circle(c1) area:"<<c1.area()<<endl;
        cout<<"Triangle(t1) area:"<<t1.area()<<endl;
        cout<<"ComposedShape(compCT)total area:"<<compCT.area()<<endl;

        //PERIMETER TEST
        cout<<"\n****Perimeter Function Test****"<<endl;
        cout<<"Rectangle(r1) perimeter:"<<r1.perimeter()<<endl;
        cout<<"Circle(c1) perimeter:"<<c1.perimeter()<<endl;
        cout<<"Triangle(t1) perimeter:"<<t1.perimeter()<<endl;
        cout<<"ComposedShape(compCT)total perimeter:"<<compCT.perimeter()<<endl;

        //--,++ TEST
        cout<<"\n****Overloaded ++,-- Operator Test****"<<endl;
        cout<<"previous triangle values:"<<t1.getTriX()<<' '<<t1.getTriY()<<endl;
        cout<<"previous rectangle values:"<<r1.getPosX()<<' '<<r1.getPosY()<<endl;
        cout<<"previous circle values:"<<c1.getCenterCoordX()<<' '<<c1.getCenterCoordY()<<endl;
        ++c1; ++t1; ++r1;
        cout<<"after the pre ++ Circle:"<<c1.getCenterCoordX()<<' '<<c1.getCenterCoordY()<<endl;
        cout<<"after the pre ++ Triangle:"<<t1.getTriX()<<' '<<t1.getTriY()<<endl;
        cout<<"after the pre ++ Rectangle:"<<r1.getPosX()<<' '<<r1.getPosY()<<endl;
        c1++; t1++; r1++;
        cout<<"after the post ++ Circle:"<<c1.getCenterCoordX()<<' '<<c1.getCenterCoordY()<<endl;
        cout<<"after the post ++ Triangle:"<<t1.getTriX()<<' '<<t1.getTriY()<<endl;
        cout<<"after the post ++ Rectangle:"<<r1.getPosX()<<' '<<r1.getPosY()<<endl;
        --c1; --t1; --r1;
        cout<<"after the pre -- Circle:"<<c1.getCenterCoordX()<<' '<<c1.getCenterCoordY()<<endl;
        cout<<"after the pre -- Triangle:"<<t1.getTriX()<<' '<<t1.getTriY()<<endl;
        cout<<"after the pre -- Rectangle:"<<r1.getPosX()<<' '<<r1.getPosY()<<endl;
        c1--; t1--; r1--;
        cout<<"after the post -- Circle:"<<c1.getCenterCoordX()<<' '<<c1.getCenterCoordY()<<endl;
        cout<<"after the post -- Triangle:"<<t1.getTriX()<<' '<<t1.getTriY()<<endl;
        cout<<"after the post -- Rectangle:"<<r1.getPosX()<<' '<<r1.getPosY()<<endl;

        //COMPARE OPERATOR TESTS
        cout<<"\n****Overloaded Compare Operator Test****"<<endl;
        cout<<"r1 area="<<r1.area()<<" c2 area="<<c2.area()<<" \"r1==c2\" result="<<(r1==c2)<<endl;
        cout<<"r1 area="<<r1.area()<<" c2 area="<<c2.area()<<" \"r1!=c2\" result="<<(r1!=c2)<<endl;
        cout<<"r1 area="<<r1.area()<<" c2 area="<<c2.area()<<" \"r1<c2\" result="<<(r1<c2)<<endl;
        cout<<"r1 area="<<r1.area()<<" c2 area="<<c2.area()<<" \"r1<=c2\" result="<<(r1<=c2)<<endl;
        cout<<"r1 area="<<r1.area()<<" c2 area="<<c2.area()<<" \"r1>c2\" result="<<(r1>c2)<<endl;
        cout<<"r1 area="<<r1.area()<<" c2 area="<<c2.area()<<" \"r1>=c2\" result="<<(r1>=c2)<<endl;

    }
    catch(MyException e){
        cerr<<e.what();
        exit(1);
    }
    catch(...){
        exit(1);
    }

    return 0;
}
