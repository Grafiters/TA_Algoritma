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

//int hitungBatas(int batas);
void credits();
void menu();
void inputKegiatan(kalender *acara);
void showAcara(kalender acara);
void showKegiatan(kalender acara);
void urutKegiatan(kalender *acara);
void tukarNilai(int *a, int *b);
void tukarNulaiSementara(int *a, int *b);
void urutKegiatan(kalender acara[], int limit);

#endif // PUSTAKA_H_INCLUDED
