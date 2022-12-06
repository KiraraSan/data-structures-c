#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node* address;
typedef struct Node* BinaryTree;

typedef char string[100];

typedef struct {
	string jenisSandal;
	int ukuranSandal;
	string warnaSandal;
} Sandal;

typedef struct {
	int biner;
} Biner;

typedef struct Node {
	Sandal sandal;
	Biner biner;
	address Left;
	address Right;
} Node;

void createEmpty(BinaryTree *BT);

bool isEmpty(BinaryTree BT);
bool isLeaf(BinaryTree BT);
bool isFound(BinaryTree BT, string jenisSandal);
bool isUkuranUnik(BinaryTree BT, int ukuranSandal);

address alokasi(string jenisSandal, int ukuran, string warnaSandal);
address alokasiBiner(int biner);

void insTreeBST(BinaryTree *BT, address P);
void delTreeAt(BinaryTree *BT, string jenisSandal);
void delTree(BinaryTree *BT);

void preOrder(BinaryTree BT);
void inOrder(BinaryTree BT);
void postOrder(BinaryTree BT);

void updateTree(BinaryTree *BT, string jenisSandal, string update, string warnaSandal);
void cekSimetri(BinaryTree *BT);
