#include<stdio.h>

int i;

int** createMatrix(int r, int c){ //rows and columns
	int ** m;
	**m = malloc(r*sizeof(int));
	for(i=0; ; i++){
		*(m+1) = malloc(c*sizeof(int));
	}
	return m;
}

int main(){
	int **matrix;
	matrix = createMatrix(5,5);
	
	for(){
		
	}
	free(matrix);
}
