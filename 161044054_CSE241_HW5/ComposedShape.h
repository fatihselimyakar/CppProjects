#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
namespace SHAPE{
    class ComposedShape : public Shape{
    public:
        ComposedShape()noexcept;
        ComposedShape(Shape& in,Shape& con)noexcept;//GET THE TWO SHAPES AND MAKES

        void optimalFit()throw(MyException);//CALCULATES AND SAVES FOR NESTED SHAPE DRAW IN SVG
        virtual void draw(ostream& outputStream)const throw(MyException) override final;//DRAWS THE SVG RESPECT TO "shapes" VECTOR
        virtual double perimeter()const noexcept override final;//RETURNS "shapes"'S TOTAL PERIMETER
        virtual double area()const noexcept override final;//RETURNS "shapes"'S TOTAL AREA
        virtual Shape& operator++()noexcept override final;//for prefix
    	virtual Shape& operator++(int)noexcept override final;//for postfix
    	virtual Shape& operator--()noexcept override final;//for prefix
    	virtual Shape& operator--(int)noexcept override final;//for postfix*/

        Shape& getInner()const noexcept;
        Shape& getContainer()const noexcept;
        vector<Shape*>getShapePtrVec()const noexcept;

        ~ComposedShape();//FOR THE DYNAMIC ALLOCATE IN OPTIMAL FIT
    private:
        vector<Shape*>shapes;//holds optimaled shapes
        Shape* inner;//holds the inner any shape
        Shape* container;//holds the container any shape
    };

}
