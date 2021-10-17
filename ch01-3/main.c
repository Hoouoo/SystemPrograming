#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
int main()
{
        void *handle;
        int (*add)(int,int),(*subtract)(int,int),(*multiple)(int,int),(*divide)(int,int);
        char *error;

        handle = dlopen("./lib/lib_calculator.so", RTLD_LAZY);
        if(!handle) {
                fputs(dlerror(),stderr);
                exit(1);
        }

        add = dlsym(handle, "add");
        if((error = dlerror()) != NULL) {
                fprintf(stderr,"%s", error);
                exit(1);
        }

        subtract = dlsym(handle, "subtract");
        if((error = dlerror()) != NULL) {
                fprintf(stderr,"%s", error);
                exit(1);
        }

        multiple = dlsym(handle, "multiple");
        if((error = dlerror()) != NULL) {
                fprintf(stderr,"%s", error); 
                exit(1);
        }

        divide = dlsym(handle, "divide");
        if((error = dlerror()) != NULL) {
                fprintf(stderr,"%s", error);
                exit(1);
        }

	printf("A = 8 / B = 2\n");
        printf("ADD: %d \n",(*add)(8,2));
        printf("SUBTRACT: %d \n",(*subtract)(8,2));
        printf("MULTIPLE: %d \n",(*multiple)(8,2));
        printf("DIVIDE :%d \n", (*divide)(8,2));
}
