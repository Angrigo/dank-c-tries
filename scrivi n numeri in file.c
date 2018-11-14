#include<stdio.h>

FILE *f1;
char nome[50];
int n;
int i;
int main(){
	do{
	printf("Inserire il nome del file dove mettere i numeri");
	scanf("%s", nome);
	}while(!fopen(nome, "w"));
	f1=fopen(nome, "w");
	printf("Inserire i numeri");
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		fprintf(f1, "%d\n", i);
	}
	
	fclose(f1);
	printf("Fatto");
}
