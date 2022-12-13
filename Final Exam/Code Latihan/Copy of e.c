#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 6

typedef char String[20];

typedef struct {
    String name;
    int age;
} Person;

typedef struct {
    Person p[MAX];
} Data;

void print(Data d, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Name : %s, Age : %d \n", d.p[i].name, d.p[i].age);
    }
}

void insertData(Data *d){
    int i;
    for(i = 0; i < MAX; i++){
        printf("Name : "); scanf("%s", d->p[i].name);
        printf("Age : "); scanf("%d", &d->p[i].age);
    }
}

void swap(Person *a, Person *b){
    Person temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSortAge(Data *d){
    int i, j;
    for(i = 0; i < MAX - 1; i++){
        for(j = 0; j < MAX - i - 1; j++){
            if(d->p[j].age > d->p[j + 1].age){
                swap(&d->p[j], &d->p[j + 1]);
            }
        }
    }
}

void BubbleSortName(Data *d){
    int i, j;
    for(i = 0; i < MAX - 1; i++){
        for(j = 0; j < MAX - i - 1; j++){
            if(strcmp(d->p[j].name, d->p[j + 1].name) > 0){
                swap(&d->p[j], &d->p[j + 1]);
            }
        }
    }
}

void binarySearchAge(Data d, int n, int x){
    int bawah = 0, atas = n - 1, tengah;
    Data temp;
    int loop = 0;
    while(bawah <= atas){
        tengah = (bawah + atas) / 2;
        if(d.p[tengah].age == x){
            printf("\nFound %d at index %d in the array", x, tengah);
            printf("\nData visit : \n"); print(temp, loop);
            printf("\nLoop %d times", loop+1);
            return;
        }else if(d.p[tengah].age < x){
            bawah = tengah + 1;
            temp.p[loop] = d.p[tengah];
        }else{
            atas = tengah - 1;
            temp.p[loop] = d.p[tengah];
        }
        loop++;
    }
    printf("Not found %d in the array a ", x);
}

void binarySearchName(Data d, int n, String x){
    int bawah = 0, atas = n - 1, tengah;
    Data temp;
    int loop = 0;
    while(bawah <= atas){
        tengah = (bawah + atas) / 2;
        if(strcmp(d.p[tengah].name, x) == 0){
            printf("\nFound %s at index %d in the array", x, tengah);
            printf("\nData visit : \n"); print(temp, loop);
            printf("\nLoop %d times", loop+1);
            return;
        }else if(strcmp(d.p[tengah].name, x) < 0){
            bawah = tengah + 1;
            temp.p[loop] = d.p[tengah];
        }else{
            atas = tengah - 1;
            temp.p[loop] = d.p[tengah];
        }
        loop++;
    }
    printf("Not found %s in the array a ", x);
}

int main(){
    system("clear");
    int age;
    String name;
    Data d;
    insertData(&d);
    system("clear");
    printf("Data before sorting : \n");
    print(d, MAX);
    BubbleSortName(&d);
    printf("\nData after sorting : \n");
    print(d, MAX);
    printf("\n");
    printf("Binary Search Name : "); scanf("%s", &name);
    binarySearchName(d, MAX, name);
    return 0;
}