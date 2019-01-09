#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

int main(){
	int exit = 0;
	char ** alunni = malloc(sizeof(char*));
	int ** voti = malloc(sizeof(int*));
	float * media;
	int ch;
	int fi;
	int fo;
	int ma;
	int best = 0;
	char nome[MAX];
	
	int id=0;
	int i;
	do{
		ch=0;
		fi=0;
		fo=0;
		ma=0;
		
		printf("Inserisci nome studente: ");
		scanf("%s", nome);
		alunni = (char**) realloc(alunni, (id+1)*sizeof(char*));
		alunni[id]= (char *) malloc(sizeof(char*)*MAX);
		strcpy(alunni[id], nome);

		while(ch<18 || fi<18 || fo<18 || ma<18 || ch>30 || fi>30 || fo>30 || ma>30){
			printf("Inserisci voti in chimica fisica fondamenti matematica in ordine\n");
			scanf("%d %d %d %d", &ch, &fi, &fo, &ma);
		}
		
		voti = (int**) realloc(voti, sizeof(int*)*(id+1));
		voti[id] = (int*) malloc(sizeof(int)*4);
		voti[id][0]=ch;
		voti[id][1]=fi;
		voti[id][2]=fo;
		voti[id][3]=ma;
		
		id++;
		
		printf("Vuoi continuare? 0 per continuare");
		scanf("%d", &exit);
	}while(exit==0);
	media = (float *) malloc((id+2)*sizeof(float));
	ch=0;
	for(i=0; i<id; i++){
		media[i] = (voti[i][0]+voti[i][1]+voti[i][2]+voti[i][3])/4;
		printf("\nStudente: %s ha i voti: %d %d %d %d\n", alunni[i], voti[i][0], voti[i][1], voti[i][2], voti[i][3]);
		if(media[i]>ch){
			ch=media[i];
			best=i;
		}
	}
	printf("\n\nStudente migliore %s con una media di %f", alunni[best],media[best]);
	
	
}
