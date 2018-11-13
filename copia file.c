#include<stdio.h>

FILE *f1;
FILE *f2;
char nome[50];

void copiaFile(FILE *a, FILE *b){
	while(fscanf(a, "%s", nome)>0){
		fprintf(b, "%s\n", nome);
	}
}

int main(){
	do{
	printf("Inserire il nome del file da copiare");
	scanf("%s", nome);
	}while(!fopen(nome, "r"));
	f1=fopen(nome, "r");
	printf("Inserire il nome del secondo file");
	scanf("%s", nome);
	f2=fopen(nome, "w");
	copiaFile(f1,f2);
	fclose(f1);
	fclose(f2);
	printf("Fatto");
}
