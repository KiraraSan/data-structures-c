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

bool isFound(BinaryTree BT, string jenisSandal) {
	if (isEmpty(BT))
		return false;
	 else 
		return ((strcmpi(BT->sandal.jenisSandal, jenisSandal) == 0) || (isFound(BT->Left, jenisSandal)) || (isFound(BT->Right, jenisSandal)));	
}

bool isUkuranUnik(BinaryTree BT, int ukuranSandal) {
	if (isEmpty(BT))
		return false;
	else 
		return ((BT->sandal.ukuranSandal = ukuranSandal) || (isUkuranUnik(BT->Left, ukuranSandal)) || (isUkuranUnik(BT->Right, ukuranSandal)));	
	
}

address alokasi(string jenisSandal, int ukuran, string warnaSandal) {
	address P = NULL;
	P = (Node*)malloc(sizeof(Node));
	
	if (P == NULL) {
		return NULL;
	} else {
		strcpy(P->sandal.jenisSandal, jenisSandal);
		strcpy(P->sandal.warnaSandal, warnaSandal);
		P->sandal.ukuranSandal = ukuran;
		P->Left = P->Right = NULL;
		return P;
	}	
}

address alokasiBiner(int biner) {
	address PB = NULL;
	PB = (Node*)malloc(sizeof(Node));
	
	if (PB == NULL) {
		return NULL;
	} else {
		PB->biner.biner = biner;
		PB->Left = PB->Right = NULL;
		return PB;
	}	
}

void insTreeBST(BinaryTree *BT, address P) {
	if (isEmpty(*BT)) {
		(*BT) = P;
	} else {
		if (P->sandal.ukuranSandal < (*BT)->sandal.ukuranSandal) {
			insTreeBST(&(*BT)->Left, P);
		} else {
			insTreeBST(&(*BT)->Right, P);
		}
	}
}

void preOrder(BinaryTree BT) {
	if (!isEmpty(BT)) {
		printf("%s - ", BT->sandal.jenisSandal);
		preOrder(BT->Left);
		preOrder(BT->Right);
	}
}

void inOrder(BinaryTree BT) {
	if (!isEmpty(BT)) {
		inOrder(BT->Left);
		printf("%s - ", BT->sandal.jenisSandal);
		inOrder(BT->Right);
	}
}

void postOrder(BinaryTree BT) {
	if (!isEmpty(BT)) {
		postOrder(BT->Left);
		postOrder(BT->Right);
		printf("%s - ", BT->sandal.jenisSandal);
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

void delTreeAt(BinaryTree *BT, string jenisSandal) {
	if (strcmpi((*BT)->sandal.jenisSandal, jenisSandal) == 0) {
		delTree(&(*BT));
	} else {
		if (isFound((*BT)->Left, jenisSandal)) {
			delTreeAt(&(*BT)->Left, jenisSandal);
		} else {
			delTreeAt(&(*BT)->Right, jenisSandal);
		}
	}
}

void updateTree(BinaryTree *BT, string jenisSandal, string update, string warnaSandal) {
	if (strcmpi((*BT)->sandal.jenisSandal, jenisSandal) == 0) {
		strcpy((*BT)->sandal.jenisSandal, update);
		strcpy((*BT)->sandal.warnaSandal, warnaSandal);
		return;
	} else {
		if (isFound((*BT)->Left, update)) {
			updateTree(&(*BT)->Left, jenisSandal, update, warnaSandal);
		} else {
			updateTree(&(*BT)->Right, jenisSandal, update, warnaSandal);		
		}
	}
}

void cekSimetri(BinaryTree *BT) {
	if (&(*BT)->Left == (&(*BT)->Right)) {
		printf("\n\tStatus     : Simetri");
	} else {
		printf("\n\tStatus     : Tidak Simetri");
	}
}

