#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define toString(x) #x
#define FALSE 0
#define TRUE 1

extern int my_assert(int expression){
	if (expression == FALSE){
		printf("%s: %s:%d ", __func__,__FILE__,__LINE__);

		return FALSE;
	}else
		return TRUE;
}

void foo(int num){
	
	printf("my_assert() Result : \n");
	if(my_assert(((num >= 0) && (num <= 100))) == FALSE){
		printf("%s: Assertion '%s' failed.\n", __func__,toString((((num >= 0) && (num <= 100)))));
		abort();
	}

	printf("foo : num = %d\n", num);
}

int main(int argc, char *argv[]){
    int num;

    if (argc < 2)
    {
        fprintf(stderr, "Usage : my_assert_test aNumber\n(0 <= Number <= 100)\n");
        exit(1);
    }

    num = atoi(argv[1]);
    foo(num);
}
