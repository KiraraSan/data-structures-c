#include "header.h"

void createEmpty(BinaryTree *BT) {
	(*BT) = NULL;
}

bool isEmpty(BinaryTree BT) {
	return (BT == NULL);
}

bool isLeaf(BinaryTree BT) {
	return (isEmpty(BT->Left) && isEmpty(BT->Right));
}

bool isFound(BinaryTree BT, string jenisPokemon) {
	if (isEmpty(BT)) {
		return false;
	} else {
		return ((strcmpi(BT->pokemon.jenisPokemon, jenisPokemon) == 0) || (isFound(BT->Left, jenisPokemon)) || (isFound(BT->Right, jenisPokemon)));	
	}
}

address alokasi(int health, string jenisPokemon) {
	address P = NULL;
	P = (Node*)malloc(sizeof(Node));
	
	if (P == NULL) {
		return NULL;
	} else {
		strcpy(P->pokemon.jenisPokemon, jenisPokemon);
		P->pokemon.hp = health;
		P->Left = P->Right = NULL;
		return P;
	}	
}

void insTreeBST(BinaryTree *BT, address P) {
	if (isEmpty(*BT)) {
		(*BT) = P;
	} else {
		if (P->pokemon.hp < (*BT)->pokemon.hp) {
			insTreeBST(&(*BT)->Left, P);
		} else {
			insTreeBST(&(*BT)->Right, P);
		}
	}
}

void preOrder(BinaryTree BT) {
	if (!isEmpty(BT)) {
		printf("%d - ", BT->pokemon.hp);
		preOrder(BT->Left);
		preOrder(BT->Right);
	}
}

void inOrder(BinaryTree BT) {
	if (!isEmpty(BT)) {
		inOrder(BT->Left);
		printf("%d - ", BT->pokemon.hp);
		inOrder(BT->Right);
	}
}

void postOrder(BinaryTree BT) {
	if (!isEmpty(BT)) {
		postOrder(BT->Left);
		postOrder(BT->Right);
		printf("%d - ", BT->pokemon.hp);
	}
}

void deleteLeaf(address *P) {
	if (isLeaf(*P)) {
		address A = (*P);
		(*P) = NULL;
		free(A);
	}
}

void delTree(BinaryTree *BT) {
	if (isEmpty(*BT)) {
		return;
	} else {
		delTree(&(*BT)->Left);
		delTree(&(*BT)->Right);
		deleteLeaf(&(*BT));
	}
}

void delTreeAt(BinaryTree *BT, string jenisPokemon) {
	if (strcmpi((*BT)->pokemon.jenisPokemon, jenisPokemon) == 0) {
		delTree(&(*BT));
	} else {
		if (isFound((*BT)->Left, jenisPokemon)) {
			delTreeAt(&(*BT)->Left, jenisPokemon);
		} else {
			delTreeAt(&(*BT)->Right, jenisPokemon);
		}
	}
}

void updateTree(BinaryTree *BT, string jenisPokemon, string update) {
	if (strcmpi((*BT)->pokemon.jenisPokemon, jenisPokemon) == 0) {
		strcpy((*BT)->pokemon.jenisPokemon, update);
		return;
	} else {
		if (isFound((*BT)->Left, update)) {
			updateTree(&(*BT)->Left, jenisPokemon, update);
		} else {
			updateTree(&(*BT)->Right, jenisPokemon, update);		
		}
	}
}
