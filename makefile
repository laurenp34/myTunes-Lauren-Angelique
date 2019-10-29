all: SongNodeFunctions.o playlist.o main.o
	gcc -o songnodetest SongNodeFunctions.o playlist.o main.o

SongNodeFunctions.o: SongNodeFunctions.c SongNodeFunctions.h
	gcc -c node.c

playlist.o: playlist.c playlist.h
	gcc -c playlist.c

main.o: main.c node.h
	gcc -c main.c

run:
	./songnodetest

clean:
	rm *.o
	rm *~
