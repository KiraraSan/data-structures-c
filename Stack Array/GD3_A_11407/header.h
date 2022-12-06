#include <stdio.h>
#include <stdlib.h>

#define max_stack 10

typedef int infoType;

typedef struct {
	int top;
	infoType data[max_stack];
} Stack;

void init(Stack *s);
void push(Stack *s, infoType data);
infoType pop(Stack *s);
void show(Stack s);
int isEmpty(Stack s);
int isFull(Stack s);
