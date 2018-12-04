#include<stdio.h>
#include<stdlib.h>

int* stack;
int q = 0;
int isEmpty(){
		
}

int pop(int n){
	n=*(stack+n);
	q--;
	stack = (int *) realloc(stack, q*sizeof(int));
	return n;
}

void push(int x){
	q++;
	stack = (int *) realloc(stack, q*sizeof(int));
	*(stack+q) = x;
}

int main(){
	int i;
	
	push(7);
	push(45);
	push(89);
	int value = pop(q);
	value = pop(q);
	push(1013);
	
	for(i=1; i<=q; i++){
		printf("%d\n", *(stack+i));
	}
	
}
