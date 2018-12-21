driver : rectangle.o triangle.o circle.o ComposedShape.o 161044054_main.o
	g++ -o driver rectangle.o triangle.o circle.o ComposedShape.o 161044054_main.o

161044054_main.o : 161044054_main.cpp
	g++ -c -std=c++0x 161044054_main.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++0x ComposedShape.cpp

rectangle.o : rectangle.cpp
	g++ -c -std=c++0x rectangle.cpp

triangle.o : triangle.cpp
	g++ -c -std=c++0x triangle.cpp

circle.o : circle.cpp
	g++ -c -std=c++0x circle.cpp

clean:
	rm *.o driver
