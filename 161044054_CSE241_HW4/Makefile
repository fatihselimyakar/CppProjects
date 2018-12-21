driver : rectangle.o triangle.o circle.o ComposedShape.o polygon.o polyline.o 161044054_main.o
	g++ -o driver rectangle.o triangle.o circle.o polygon.o polyline.o ComposedShape.o 161044054_main.o

161044054_main.o : 161044054_main.cpp
	g++ -c -std=c++11 161044054_main.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++11 ComposedShape.cpp

rectangle.o : rectangle.cpp
	g++ -c -std=c++11 rectangle.cpp

triangle.o : triangle.cpp
	g++ -c -std=c++11 triangle.cpp

circle.o : circle.cpp
	g++ -c -std=c++11 circle.cpp

polygon.o : polygon.cpp
	g++ -c -std=c++11 polygon.cpp

polyline.o : polyline.cpp
	g++ -c -std=c++11 polyline.cpp

clean:
	rm *.o driver
