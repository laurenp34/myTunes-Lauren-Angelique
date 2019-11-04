all: SongNodeFunctions.o SongLibraryFunctions.o main.o
	gcc -o songnodetest SongNodeFunctions.o SongLibraryFunctions.o main.o

SongNodeFunctions.o: SongNodeFunctions.c SongNodeFunctions.h
	gcc -c SongNodeFunctions.c

SongLibraryFunctions.o: SongLibraryFunctions.c SongLibraryFunctions.h
	gcc -c SongLibraryFunctions.c

main.o: main.c SongNodeFunctions.h SongLibraryFunctions.h
	gcc -c main.c

run:
	./songnodetest

clean:
	rm *.o
	rm *~
