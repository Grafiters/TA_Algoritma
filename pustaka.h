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
    char nama[50][50];
    tanggal tgl;
    waktu wak;
}kalender;

int hitungBatas(int batas);

void menu();
void inputKegiatan(kalender *acara, int batas);
void showAcara(kalender acara, int batas);
void showKegiatan(kalender acara, int batas);

void credits();

#endif // PUSTAKA_H_INCLUDED
