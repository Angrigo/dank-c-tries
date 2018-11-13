#include <stdio.h>

FILE *fmed;
float med = 0;
int a = 1;
char enom[50];
int evot;
int i=0;

int main(){
	printf("/////\n		Salve, sono il suo calcolatore della media degli esami, la prego di inserire le informazioni richieste.\n");
	
    while(a){
    	evot=0;
	    	printf("/////\n		Nome esame:");
	        scanf("%s", enom);
	    while(evot>31 || evot<18){
	        printf("/////\n		Voto per l'esame di %s:", enom);
	        scanf("%d", &evot);
	        if(evot>31 || evot<18) printf("\n!!!!!	Voto non corretto, la prego di reinserire.\n");
    	}
        printf("\nInserisci 0 per uscire e 1 per continuare: ");
        scanf("%d", &a);
        med=med+evot;
        i=i+1;
    }
    
    fmed= fopen("media.txt", "w");
    fprintf(fmed, "La media degli esami è %f", med/i);
    fclose(fmed);
}
