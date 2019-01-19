run : 161044054_main.o Shape.o Rectangle.o Circle.o Triangle.o ComposedShape.o Polygon.o PolygonDyn.o PolygonVect.o
	
	g++ -o run 161044054_main.o Shape.o Rectangle.o Circle.o Triangle.o ComposedShape.o Polygon.o PolygonDyn.o PolygonVect.o 

161044054_main.o : 161044054_main.cpp
	g++ -c 161044054_main.cpp -std=c++11

Shape.o : Shape.cpp
	g++ -c Shape.cpp -std=c++11

Rectangle.o : Rectangle.cpp
	g++ -c Rectangle.cpp -std=c++11

Circle.o : Circle.cpp
	g++ -c Circle.cpp -std=c++11

Triangle.o : Triangle.cpp
	g++ -c Triangle.cpp -std=c++11

ComposedShape.o : ComposedShape.cpp
	g++ -c ComposedShape.cpp -std=c++11

Polygon.o : Polygon.cpp
	g++ -c Polygon.cpp -std=c++11

PolygonDyn.o : PolygonDyn.cpp
	g++ -c PolygonDyn.cpp -std=c++11

PolygonVect.o : PolygonVect.cpp
	g++ -c PolygonVect.cpp -std=c++11

