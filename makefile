

all: prog 

main.o: main.c funcoes.h menu.h global.h
	gcc -c main.c -o main.o

funcoes.o: funcoes.c funcoes.h global.h
	gcc -c funcoes.c -o funcoes.o

menu.o: menu.c menu.h global.h
	gcc -c menu.c -o menu.o

prog: main.o funcoes.o menu.o
	gcc main.o funcoes.o menu.o -o prog

run: 
	./prog

clean: 
	rm -f *.o prog
