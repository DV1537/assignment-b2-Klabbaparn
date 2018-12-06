TestRule: main.cpp
	g++ -g Shape.cpp Polygon.cpp Triangle.cpp Line.cpp Point.cpp OnePoint.cpp Functions.cpp main.cpp -o main.exe -static-libgcc -static-libstdc++