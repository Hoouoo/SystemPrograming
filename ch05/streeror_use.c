#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void main (int argc, chasr *argv[]){
	FILE *f;

	if(argc < 2){
		printf("Usage : strerror_show nofilename\n");
		exit(1);
	}

	if( ( f = fopen(argv[i], "r")) == NULL){
		printf("Cannot open a file \ "$s\" ... (error message : %s) \n", argv[1], strerror(errno));
		exit(1);
	}
	
	printf("Open a file \"%s"\.\n", argv[1]);

	fclose(f);
}
