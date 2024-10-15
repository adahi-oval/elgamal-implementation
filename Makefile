elgamal: elgamal.o
	g++ -std=c++14 -g -Wall -o elgamal elgamal.o

elgamal.o: elgamal.cpp
	g++ -c elgamal.cpp

debug:
	g++ -std=c++14 -g3 elgamal.cpp -o elgamal_debug

clean:
	rm *.o elgamal elgamal_debug