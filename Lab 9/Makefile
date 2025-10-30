# Lab 9 Makefile
all: lab9

lab9: main.o matrix.o
	g++ -std=c++11 -o lab9 main.o matrix.o

main.o: main.cpp matrix.h
	g++ -std=c++11 -c main.cpp

matrix.o: matrix.cpp matrix.h
	g++ -std=c++11 -c matrix.cpp

clean:
	rm -f *.o lab9


