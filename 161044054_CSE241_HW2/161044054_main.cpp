#include"ComposedShape.h"

int main(){//The main provides us draw the svg files and get the input values from user
	//File declaretion and opening
	ofstream outputStream;
	cout<<"TESTING FUNCTIONS"<<endl;
	//TESTING CONSTRUCTORS
	rectangle RecArr[4]={{20,10,'i'},{100,200,'c'},{},{150,330,'c',0,0,0}};
	triangle TriArr[4]={{15,'i'},{100,'c'},{},{250,'c',15,15,30,30,40,40,0}};
	circle CircArr[4]={{15,'i'},{290,'c'},{},{300,'c',20,20,0}};
	
	RecArr[3].output();
	TriArr[3].output();
	RecArr[3].output();
	
	TriArr[2].set(30,'i',20,20,0);//I set the default constructor to inner triangle which is lateral is 30
	cout<<"With the getter functions(triangle):"<<TriArr[2].getLateral()<<' '<<TriArr[2].getPosition()<<endl;
	
	RecArr[2].set(12,15);//I set the default constructor's width and height
	RecArr[2].set('i');//I set the default constructor's position
	cout<<"With the getter functions(rectangle):"<<RecArr[3].getHeight()<<' '<<RecArr[3].getWidth()<<' '<<RecArr[3].getPosition()<<endl;
	
	CircArr[2].set(11,'i',20,20,0);//I set the default constructor to inner triangle which is lateral is 11
	cout<<"With the getter functions(circle):"<<CircArr[2].getRadius()<<' '<<CircArr[2].getPosition()<<endl;

	ComposedShape CompArr[9]={{RecArr[1],RecArr[0]},{RecArr[3],TriArr[2]},{RecArr[3],CircArr[2]},{TriArr[3],RecArr[2]},{TriArr[1],TriArr[0]},{TriArr[3],CircArr[2]},{CircArr[3],RecArr[2]},{CircArr[3],TriArr[2]},{CircArr[1],CircArr[0]}};//I make the ComposedShape type class including to other type classes array's variable
	
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
	outputStream.close();
	
	cout<<"Svg file drawing has been completed"<<endl;
	
	return 0;
}