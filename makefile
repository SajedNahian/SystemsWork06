all: structs.o
	gcc -o out structs.o

structs.o: structs.c footballplayer.h
	gcc -c structs.c

clean:
	rm *.o
	rm *.exe