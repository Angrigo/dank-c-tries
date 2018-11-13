#include<stdio.h>

FILE * f1;
FILE * f2;
int numero;
char nome[50];
int i;

int primo(int n)
{
	for(i=2; i<n-1; i++){
		if(n%i==0) return 0;
	}
	return 1;
}

void scriviFile(int valore, FILE * a){
	if(primo(valore))
		fprintf(a, "%d\n", valore);
}

void copiaFile(FILE * a, FILE * b){
	while(fscanf(a, "%d", &numero)>0){
		scriviFile(numero, b);
	}
}

int main(){
	do{
	printf("Inserire il nome del file dove sono i numeri da controllare ... ");
	scanf("%s", nome);
	}while(!fopen(nome, "r"));
	f1=fopen(nome, "r");	
	f2=fopen("risultati.txt", "w");
	copiaFile(f1,f2);
	fclose(f1);
	fclose(f2);
	printf("Fatto, i numeri primi sono stati trovati");
}
