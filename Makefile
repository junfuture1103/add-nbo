all: jun_add

jun_add: jun_add.o
	g++ -o jun_add jun_add.o

jun_add.o: jun_add.cpp
	g++ -c -o jun_add.o jun_add.cpp

clean:
	rm -f jun_add *.o
