directory.o : directory.cc directory.h utils.h
	g++ -c -std=c++11 -O6 directory.cc

document.o : document.cc document.h
	g++ -c -std=c++11 -O6 document.cc

motore_ricerca.o : motore_ricerca.cc motore_ricerca.h
	g++ -c -std=c++11 -O6 motore_ricerca.cc

utils.o : utils.cc utils.h
	g++ -c -std=c++11 -O6 utils.cc

main.o : main.cpp document.h directory.h motore_ricerca.h
	g++ -c -std=c++11 -O6 main.cpp

Main : main.o directory.o document.o motore_ricerca.o utils.o                                 
	g++ -o Main main.o directory.o document.o motore_ricerca.o utils.o 

all: Main
