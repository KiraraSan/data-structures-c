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
	string jenisPokemon;
	int hp;
} Pokemon;

typedef struct Node {
	Pokemon pokemon;
	address Left;
	address Right;
} Node;

void createEmpty(BinaryTree *BT);

bool isEmpty(BinaryTree BT);
bool isLeaf(BinaryTree BT);
bool isFound(BinaryTree BT, string jenisPokemon);

address alokasi(int health, string jenisPokemon);

void insTreeBST(BinaryTree *BT, address P);
void delTreeAt(BinaryTree *BT, string jenisPokemon);
void delTree(BinaryTree *BT);

void preOrder(BinaryTree BT);
void inOrder(BinaryTree BT);
void postOrder(BinaryTree BT);

void updateTree(BinaryTree *BT, string jenisPokemon, string update);
