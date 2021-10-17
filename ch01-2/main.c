#include <stdio.h>
#include "lib_calculator.h"

int main(){
	printf("A = 8, B = 2\n");
	printf("ADD : %d\n", add(8, 2));
	printf("SUBTRACT : %d\n", subtract(8,2));
	printf("MULTIPLE : %d\n", multiple(8,2));
	printf("DIVIDE : %d\n", divide(8,2));

	return 0;
}
