default:
	g++ main.cpp -o main.exe --static -static-libgcc -static-libstdc++ -Wall -Wno-missing-braces -I e-maths -I ml -std=c++20
	./main.exe

darwin:
	g++ main.cpp -o main -Wall -Wno-missing-braces -I e-maths -I ml -std=c++20
	./main
darwin-build:
	g++ main.cpp -o main -Wall -Wno-missing-braces -I e-maths -I ml -std=c++20