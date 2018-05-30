#ifndef PUSTAKA_H_INCLUDED
#define PUSTAKA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int d;
    int m;
    int y;
}tanggal;

typedef struct{
    int m;
    int h;
}waktu;

typedef struct{
    char kegiatan[50];
    char nama[50];
    tanggal tgl;
    waktu wak;
}kalender;

kalender data[];

int batas;
int tukar(int *num1, int *num2);
int inner_rec(int data[], int cur, int arrSize);

void menu();
void inputKegiatan();
void showKegiatan();
void urutKegiatan(int batas);

#endif // PUSTAKA_H_INCLUDED
