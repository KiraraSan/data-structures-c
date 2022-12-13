//1. Binary Tree

//Menghitung Node
int countAllNode(BinaryTree BT) {
    if (BT != NULL) {
        return 1 + countAllNode(BT->Left) + countAllNode(BT->Right);
    } else {
        return 0;
    }
}

//Mencari nilai maksimal dari suatu tree
int maxNode(BinaryTree BT) {
    if (BT->Right != NULL) {
        maxNode
    }
}

// Simetri
bool isSymetric(BinaryTree BT1, BinaryTree BT2) {
    if (BT1 == NULL && BT2 == NULL)
        return true;
    if (BT1 && BT2) 
        return isSymetric(BT1->Left, BT2_Right) && isSymetric(BT1->Right, BT2->Left);
    return false;
}  

//2. Sorting


//3. Searching

//Mencari maksimum node
int findMaxNode(List L) {
    if (isOneElement(L)) {
        return L-data;
    } else {
        int temp = findMaxNode(L->next);
        if (L->data > temp) {
            return L->data;
        } else {
            return temp;
        }
    }
}




/* =============================================================== */
//Soal UAS tahun lalu

//Jawaban binarysearch yg pertama = 2 kali kunjungan

//6. Tampilkan array secara terbalik
void printReverse(int A[], int i) {
    if (i < 10) {
        return;
    } else {
        printf("%d", A[i]);
        printReverse(A, i - 1);
    }
}

//7. 


//8. 
3 kali perulangan

