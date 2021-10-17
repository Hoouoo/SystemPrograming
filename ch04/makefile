calculator : a.out
	gcc -I./lib -L./lib -o calculator main.c -l_calculator

a.out : ./lib/calculator.o
	ar rcs ./lib/lib_calculator.a ./lib/calculator.o

calculator.o : ./lib/calculator.c
	gcc -c ./lib/calculator.c

clean :
	rm -f calculator calculator.o lib_calculator.a
