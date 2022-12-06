#include "header.h"

void init(Stack *s) {
	(*s).top = -1;
}

int isFull(Stack s) {
	return s.top == max_stack - 1;
}

int isEmpty(Stack s) {
	return s.top == -1;
}

void push(Stack *s, infoType data) {
	(*s).top++;
	(*s).data[(*s).top] = data;
}

infoType pop(Stack *s) {
	infoType temp;
	
	temp = (*s).data[(*s).top];
	(*s).top--;
	
	return temp;
}

void show(Stack s) {
	int i;
	
	for(i=0; i!=s.top+1; i++) {
		printf("| %d ", s.data[i]);
	}
	printf("|");
}
