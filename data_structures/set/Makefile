all: set

set: main.o set.o
	g++ -std=c++11 main.o set.o -o set

main.o: main.cpp set.hpp
	g++ -std=c++11 -c main.cpp

set.o: set.cpp set.hpp
	g++ -std=c++11 -c set.cpp

clean:
	rm -rf *.o set
