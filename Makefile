.PHONY: all clean

all: example

example: example.o ExplicitEulerSODE.o 
	g++ -o example example.o ExplicitEulerSODE.o

ExplicitEulerSODE.o: SODE.hpp ExplicitEulerSODE.hpp ExplicitEulerSODE.cpp
	g++ -c ExplicitEulerSODE.cpp

example.o: example.cpp
	g++ -c example.cpp

clean:
	rm example.o ExplicitEulerSODE.o example
