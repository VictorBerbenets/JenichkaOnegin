
CC = g++

CFLAGS =-c -Wall

all : onegin

onegin : main.o FileFunctions.o SortingFunctions.o
	$(CC) FileFunctions.o SortingFunctions.o main.o -o onegin

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

FileFunctions.o  : FileFunctions.cpp
	$(CC) $(CFLAGS) FileFunctions.cpp

SortingFunctions.o : SortingFunctions.cpp
	$(CC) $(CFLAGS) SortingFunctions.cpp

clean:
	rm -rf * .o onegin