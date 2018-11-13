#include<stdio.h>

FILE * f1;
FILE * f2;
int numero;
char nome[50];
int s=1;

int fattoriale(int n)
{
  if (n == 0) return 1;
  else return n*fattoriale(n-1);
}

void scriviFile(int valore, FILE * a){
	fprintf(a, "%d\n", fattoriale(valore));
	s=1;
}

void copiaFile(FILE * a, FILE * b){
	while(fscanf(a, "%d", &numero)>0){
		scriviFile(numero, b);
	}
}

int main(){
	do{
	printf("Inserire il nome del file dove sono i numeri da fattorizzare ... ");
	scanf("%s", nome);
	}while(!fopen(nome, "r"));
	f1=fopen(nome, "r");
	printf("Inserire il nome del file dove inserire i fattorizzati ... ");
	scanf("%s", nome);
	f2=fopen(nome, "w");
	copiaFile(f1,f2);
	fclose(f1);
	fclose(f2);
	printf("Fatto");
}
