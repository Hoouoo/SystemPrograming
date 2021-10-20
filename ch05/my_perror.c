#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

extern void my_perror(const char *str){
	if(str == NULL)
		printf("%s\n",strerror(errno));
	else
		printf("%s : %s\n", str, strerror(errno));
}

int main (int argc, char *argv[]){
        FILE *f;

        if(argc < 2){ // Filename 
                printf("Usage : strerror_show nofilename\n");
                exit(1);
        }

        if( ( f = fopen(argv[1], "r")) == NULL){  // Not found File
                
		printf("my_perror Result : \n");
		my_perror(NULL);
		my_perror("fopen");
		printf("perror Result : \n");
		perror(NULL);
		perror("fopen");
		exit(1);
        }

        printf("Open a file \"%s\".\n", argv[1]);

       fclose(f);
}
