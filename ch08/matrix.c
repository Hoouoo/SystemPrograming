#include <stdio.h>
#include <stdlib.h>

int main(){
	int row, col, i, j;

	printf("Input matrix size: ");
	scanf("%d %d", &row, &col);
	int *matrixA, *matrixB;
	int *matrixSum;
	
	matrixA = (int *)malloc(row * col * sizeof(int));
	matrixB = (int *)malloc(row * col * sizeof(int));
	
	matrixSum = (int *)malloc(row * col * sizeof(int));

	if(matrixA == NULL || matrixB == NULL || matrixSum == NULL) {
                printf("Memory malloc Error");
                exit(-1);
        }

	printf("Input Matrix A \n");
	for( i = 0; i < row*col; i++){
		scanf("%d", &matrixA[i]);
	}

	printf("Input Matrix B \n");
	for( i = 0; i < row*col; i++){
		scanf("%d", &matrixB[i]);
	}

	for( i=0; i < row * col ; i++){
		matrixSum[i] = matrixA[i] + matrixB[i];
	}

	printf("======================Result Add Matrix===================\n");
	for( i=-0; i < row; i++){
		for( j= 0; j < col; j++){
			printf("%d ", matrixSum[i*j]);
		}
		printf("\n");
	}
					
			

	free(matrixA);
	free(matrixB);
	free(matrixSum);
}
