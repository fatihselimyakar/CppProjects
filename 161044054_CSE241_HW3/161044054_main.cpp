#include"ComposedShape.h"

int main(){//The main provides us draw the svg files and get the input values from user
	//File declaretion and opening
	ofstream outputStream;
	cout<<"TESTING FUNCTIONS"<<endl<<endl;
	
	rectangle RecArr[4]={{200,100,'i'},{20,10,'i'},{100,200,'c'},{150,330,'c',0,0,0}};
	triangle TriArr[4]={{15,'i'},{20,'i'},{100,'c'},{250,'c',15,15,30,30,40,40,0,0,0}};
	circle CircArr[4]={{20,'i'},{50,'i'},{290,'c'},{300,'c',150,150,0,0,0}};
	
	//I test wrote functions
	cout<<"***Static Functions Test****"<<endl;
	cout<<"Circle area and perimeter:"<<circle::calcTotalArea()<<" "<<circle::calcTotalPerimeter()<<endl;
	cout<<"Rectangle area and perimeter:"<<rectangle::calcTotalArea()<<" "<<rectangle::calcTotalPerimeter()<<endl;
	cout<<"Triangle area and perimeter:"<<triangle::calcTotalArea()<<" "<<triangle::calcTotalPerimeter()<<endl<<endl;
	
	
	cout<<"RECTANGLE TEST"<<endl;
	cout<<"****post increment****"<<endl;
	RecArr[3]++;
	RecArr[3].output();
	cout<<"****pre increment****"<<endl;
	++RecArr[3];
	RecArr[3].output();
	cout<<"****post decrement****"<<endl;
	RecArr[3]--;
	RecArr[3].output();
	cout<<"****pre decrement****"<<endl;
	--RecArr[3];
	RecArr[3].output();
	cout<<"****plus****"<<endl;
	RecArr[3]=RecArr[3]+10.0;
	RecArr[3].output();
	cout<<"****minus****"<<endl;
	RecArr[3]=RecArr[3]-10.0;
	RecArr[3].output();
	cout<<"****Comparison operator test****"<<endl;
	if(RecArr[2]==RecArr[2]){
		cout<<"== test passed"<<endl;
	}
	if(RecArr[3]>RecArr[2]){
		cout<<"> test passed"<<endl;
	}
	if(RecArr[3]>=RecArr[2]){
		cout<<">= test passed"<<endl;
	}
	if(RecArr[2]<RecArr[3]){
		cout<<"< test passed"<<endl;
	}
	if(RecArr[2]<=RecArr[3]){
		cout<<"<= test passed"<<endl;
	}
	if(RecArr[2]!=RecArr[3]){
		cout<<"!= test passed"<<endl;
	}
	cout<<"****CALCULATE TEST****"<<endl;
	cout<<"Perimeter:"<<RecArr[3].periLength()<<endl;
	cout<<"Area:"<<RecArr[3].area()<<endl;
	/*DRAW IN SVG*/
	outputStream.open("oneRec.svg");
	outputStream<<RecArr[3];
	outputStream<<"</svg>";
	outputStream.close();
	
	cout<<"\nTRIANGLE TEST"<<endl;
	cout<<"****post increment****"<<endl;
	TriArr[3]++;
	TriArr[3].output();
	cout<<"****pre increment****"<<endl;
	++TriArr[3];
	TriArr[3].output();
	cout<<"****post decrement****"<<endl;
	TriArr[3]--;
	TriArr[3].output();
	cout<<"****pre decrement****"<<endl;
	--TriArr[3];
	TriArr[3].output();
	cout<<"****plus****"<<endl;
	TriArr[3]=TriArr[3]+10.0;
	TriArr[3].output();
	cout<<"****minus****"<<endl;
	TriArr[3]=TriArr[3]-10.0;
	TriArr[3].output();
	cout<<"****Comparison operator test****"<<endl;
	if(TriArr[0]==TriArr[2]){
		cout<<"== test failed"<<endl;
	}
	else{
		cout<<"== test passed"<<endl;
	}
	if(TriArr[3]>TriArr[2]){
		cout<<"> test passed"<<endl;
	}
	if(TriArr[3]>=TriArr[2]){
		cout<<">= test passed"<<endl;
	}
	if(TriArr[2]<TriArr[3]){
		cout<<"< test passed"<<endl;
	}
	if(TriArr[2]<=TriArr[3]){
		cout<<"<= test passed"<<endl;
	}
	if(TriArr[2]!=TriArr[3]){
		cout<<"!= test passed"<<endl;
	}
	cout<<"****CALCULATE TEST****"<<endl;
	cout<<"Perimeter:"<<TriArr[3].periLength()<<endl;
	cout<<"Area:"<<TriArr[3].area()<<endl;
	/*DRAW IN SVG*/
	outputStream.open("oneTri.svg");
	outputStream<<TriArr[3];
	outputStream<<"</svg>";
	outputStream.close();
	
	cout<<"\nCIRCLE TEST"<<endl;
	cout<<"****post increment****"<<endl;
	CircArr[3]++;
	CircArr[3].output();
	cout<<"****pre increment****"<<endl;
	++CircArr[3];
	CircArr[3].output();
	cout<<"****post decrement****"<<endl;
	CircArr[3]--;
	CircArr[3].output();
	cout<<"****pre decrement****"<<endl;
	--CircArr[3];
	CircArr[3].output();
	cout<<"****plus****"<<endl;
	CircArr[3]=CircArr[3]+10.0;
	CircArr[3].output();
	cout<<"****minus****"<<endl;
	CircArr[3]=CircArr[3]-10.0;
	CircArr[3].output();
	cout<<"****Comparison operator test****"<<endl;
	if(CircArr[2]==CircArr[0]){
		cout<<"== test failed"<<endl;
	}
	else{
		cout<<"== test passed"<<endl;
	}
	if(CircArr[3]>CircArr[2]){
		cout<<"> test passed"<<endl;
	}
	if(CircArr[3]>=CircArr[2]){
		cout<<">= test passed"<<endl;
	}
	if(CircArr[2]<CircArr[3]){
		cout<<"< test passed"<<endl;
	}
	if(CircArr[2]<=CircArr[3]){
		cout<<"<= test passed"<<endl;
	}
	if(CircArr[2]!=CircArr[3]){
		cout<<"!= test passed"<<endl;
	}
	cout<<"****CALCULATE TEST****"<<endl;
	cout<<"Perimeter:"<<CircArr[3].periLength()<<endl;
	cout<<"Area:"<<CircArr[3].area()<<endl;
	outputStream.open("oneCirc.svg");
	outputStream<<CircArr[3];
	outputStream<<"</svg>";
	outputStream.close();


	

	ComposedShape CompArr[9]={{RecArr[2],RecArr[0]},{RecArr[3],TriArr[1]},{RecArr[3],CircArr[1]},{TriArr[3],RecArr[1]},{TriArr[2],TriArr[0]},{TriArr[3],CircArr[1]},{CircArr[3],RecArr[1]},{CircArr[3],TriArr[1]},{CircArr[2],CircArr[0]}};//I make the ComposedShape type class including to other type classes array's variable
	
	cout<<"\n****SHAPE ELEM TEST****"<<endl;
	ComposedShape::ShapeElem elem(CircArr[3]);
	cout<<"Shape elem perimeter:"<<elem.getPerimeter()<<endl;
	//PRINTING SVG	
	cout<<"Shape elem area:"<<elem.getArea()<<endl;
	outputStream.open("shapeElemSample.svg");
	outputStream<<elem;
	outputStream<<"</svg>";
	outputStream.close();

	cout<<"\n****COMPOSED SHAPE TEST****"<<endl;
	ComposedShape trying;
	trying+=CompArr[0];
	cout<<"+= test"<<endl;
	trying.getRecCo().output();
	trying[0];
	

	
	//Drawing svg for all combination different svg files with draw(includes other classes draws) and optimalfit(in the getted values)
	outputStream.open("SampleRR.svg");
	CompArr[0].optimalFit(CompArr[0].getRecCo(),CompArr[0].getRecIn());
	CompArr[0].draw(outputStream,CompArr[0].getRecCo(),CompArr[0].getRecIn());
	outputStream.close();
	
	outputStream.open("SampleRT.svg");
	CompArr[1].optimalFit(CompArr[1].getRecCo(),CompArr[1].getTriIn());
	CompArr[1].draw(outputStream,CompArr[1].getRecCo(),CompArr[1].getTriIn());
	outputStream.close();
	
	outputStream.open("SampleRC.svg");
	CompArr[2].optimalFit(CompArr[2].getRecCo(),CompArr[2].getCircIn());
	CompArr[2].draw(outputStream,CompArr[2].getRecCo(),CompArr[2].getCircIn());
	outputStream.close();
	
	outputStream.open("SampleTR.svg");
	CompArr[3].optimalFit(CompArr[3].getTriCo(),CompArr[3].getRecIn());
	CompArr[3].draw(outputStream,CompArr[3].getTriCo(),CompArr[3].getRecIn());
	outputStream.close();
	
	outputStream.open("SampleTT.svg");
	CompArr[4].optimalFit(CompArr[4].getTriCo(),CompArr[4].getTriIn());
	CompArr[4].draw(outputStream,CompArr[4].getTriCo(),CompArr[4].getTriIn());
	outputStream.close();
	
	outputStream.open("SampleTC.svg");
	CompArr[5].optimalFit(CompArr[5].getTriCo(),CompArr[5].getCircIn());
	CompArr[5].draw(outputStream,CompArr[5].getTriCo(),CompArr[5].getCircIn());
	outputStream.close();
	
	outputStream.open("SampleCR.svg");
	CompArr[6].optimalFit(CompArr[6].getCircCo(),CompArr[6].getRecIn());
	CompArr[6].draw(outputStream,CompArr[6].getCircCo(),CompArr[6].getRecIn());
	outputStream.close();
	
	outputStream.open("SampleCT.svg");
	CompArr[7].optimalFit(CompArr[7].getCircCo(),CompArr[7].getTriIn());
	CompArr[7].draw(outputStream,CompArr[7].getCircCo(),CompArr[7].getTriIn());
	outputStream.close();
	
	outputStream.open("SampleCC.svg");
	CompArr[8].optimalFit(CompArr[8].getCircCo(),CompArr[8].getCircIn());
	CompArr[8].draw(outputStream,CompArr[8].getCircCo(),CompArr[8].getCircIn());
	
	outputStream<<"</svg>";
	outputStream.close();
	
	cout<<"Tests and Svg file drawing has been completed"<<endl;
	
	return 0;
}
