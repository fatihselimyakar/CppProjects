enum class shape{R,C,T};//I declared the new enum class for shape type 

struct shapeInfo{//This struct is necessary to implement a properties of shapes
	shape Shape;
	int width,height,radius,lateral;
};

void rectangleMeasure(int& width,int& height);

void  circleMeasure(int& radius);

void  triangleMeasure(int& lateral);

void getInput(shapeInfo& container,shapeInfo& small);
	
void rectInRect(shapeInfo container,shapeInfo small);

void circInRect(shapeInfo container,shapeInfo small);

void triInRect(shapeInfo container,shapeInfo small);

void triInTri(shapeInfo container,shapeInfo small);

void rectInTri(shapeInfo container,shapeInfo small);

void circInTri(shapeInfo container,shapeInfo small);

void triInCirc(shapeInfo container,shapeInfo small);

void circInCirc(shapeInfo container,shapeInfo small);

void recInCirc(shapeInfo container, shapeInfo small);

void calcAndDraw(shapeInfo container,shapeInfo small);