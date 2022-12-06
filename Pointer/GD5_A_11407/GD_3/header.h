#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DataMAX 10

typedef char string[10];

typedef struct {
    int id;
    string nama;
    string tanggalTerbit;
} Data;

Data makeData(int id, string nama, string t);
void initData(Data data[]);
void tampilData(Data data[]);
void inputan(Data *ptrDisplay);
Data* cariBerdasarID(Data *ptrDisplay, Data data[], int id);
