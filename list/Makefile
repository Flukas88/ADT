HEADERS = list.h

all: list.o list_big.o

list.o: list.c $(HEADERS)
	gcc list.c -o list.o 

list_big.o: list.c $(HEADERS)
	gcc -DBIG_STRING list.c -o list_big.o 

clean:
	-rm -f list.o list_big.o
