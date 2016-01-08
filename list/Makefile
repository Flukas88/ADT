HEADERS = list.h

all: list.o list_big.o ctags

list.o: list.c $(HEADERS)
	gcc -std=gnu99 -g list.c -o list.o 

list_big.o: list.c $(HEADERS)
	gcc -std=gnu99 -g -DMAX_EL=10 -DBIG_STRING list.c -o list_big.o 

ctags: 
	ctags -R *
clean:
	-rm -f list.o list_big.o
