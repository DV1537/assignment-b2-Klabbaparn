TestRule: main.cpp
	g++ -g Shape.cpp Polygon.cpp Triangle.cpp Line.cpp OnePoint.cpp Functions.cpp main.cpp -o testProg.exe -static-libgcc -static-libstdc++