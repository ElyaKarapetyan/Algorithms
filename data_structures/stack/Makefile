all: stack

stack: main.o stack.o
	g++ -std=c++11 main.o stack.o  -o stack

main.o: main.cpp stack.hpp
	g++ -std=c++11 -c main.cpp

stack.o: stack.cpp stack.hpp
	g++ -std=c++11 -c stack.cpp

clean:
	rm -rf *.o stack
