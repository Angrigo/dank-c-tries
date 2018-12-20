#include <stdio.h>
#include <stdlib.h>
#define FILE_MATRICE "Matrice.txt"
#define FILE_PARAMS "Parametri.txt"
#define FILE_SUMMARY "Sommario.txt"

void leggiParams(int *num_r, int *num_c){
	FILE *fi = fopen(FILE_PARAMS, "r");
	fscanf(fi, "%d%d", num_r, num_c);
	fclose(fi);
}

void leggiMatrix(int r, int c, int **mat){
	int i,j;
	FILE *fi = fopen(FILE_MATRICE, "r");
	if(fi!=NULL){
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			int a;
			fscanf(fi,"%d", &a);
			mat[i][j]=a;
		}
	}
	fclose(fi);
	}else{
		printf("ERRORE LETTURA MATRICE");
	}
}
void maxRow(int r, int c, int **mat, int *vettore){
	int i,j;
	for(i=0; i<r; i++){
		vettore[i]=mat[i][0];
		for(j=0; j<c; j++){
			if(mat[i][j]>vettore[i])
				vettore[i]=mat[i][j];
		}
	}
}
void writeFile(int *arr, int l){
	int i;
	FILE *fi = fopen(FILE_SUMMARY, "w");
	for(i=0; i<l; i++){
		fprintf(fi, "Valore max di riga %d: %d\n", i+1, arr[i]);
	}
	fclose(fi);
}
int** createMatrix(int r, int c){
	int ** a;
	int i;
	a= (int **) malloc (sizeof(int *) * r);
	for(i=0; i<r; i++){
		*(a+i) = malloc(sizeof(int) * c); 
	}
	return a;
}
int main(){
	int r,c,i;
	int *dati;
	int **m;

	leggiParams(&r,&c); 
	
	//mem alloc for array
	dati = (int *) malloc(r*sizeof(int));
	//mem alloc for matrix
	m = createMatrix(r,c);

	leggiMatrix(r,c,m);
	maxRow(r,c,m,dati);
	writeFile(dati, r);
	
	//libero la memoria
	for(i=0; i<r; i++){
		free(m[i]);
	}
	free(m);
	free(dati);
	
}

