default:
	g++ main.cpp -o main.exe --static -static-libgcc -static-libstdc++ -Wall -Wno-missing-braces -I e-maths -std=c++20
	./main.exe

build:
	g++ main.cpp -O3 -o main.exe --static -static-libgcc -static-libstdc++ -Wall -Wno-missing-braces -I e-maths -std=c++20