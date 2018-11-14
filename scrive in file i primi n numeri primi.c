#include<stdio.h>

FILE *f1;
char nome[50];
unsigned int a;
unsigned int i;
unsigned int k;

int primo(int n)
{
	for(i=2; i<n-1; i++){
		if(n%i==0) return 0;
	}
	return 1;
}

int main(){
	
	do{
	printf("\nInserire il nome del file dove mettere i numeri\n");
	scanf("%s", nome);
	}while(!fopen(nome, "w"));
	f1=fopen(nome, "w");
	
	printf("\nInserire i numeri\n");
	scanf("%d", &a);
	
	for(k=1; k<=a; k++){
		if(primo(k)){
			fprintf(f1, "%d\n", k);}
	}
	
	fclose(f1);
	printf("Fatto");
}
