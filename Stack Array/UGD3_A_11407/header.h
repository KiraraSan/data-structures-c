#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[50];

typedef struct {
	string judul;
	string nama;
	string jenis;
	float harga;
} Max;

typedef struct {
	int top;
	Max max[10];
} Stack;

void inisialisasi(Stack *S);
void push(Stack *S, Max max);
Max pop(Stack *S);
int found(Stack S, string judul);
void show(Stack S);
void edit(Stack *S);
int isEmpty(Stack S);
int isFull(Stack S);
