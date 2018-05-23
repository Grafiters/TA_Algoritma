#ifndef PUSTAKA_H_INCLUDED
#define PUSTAKA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char kegiatan[50];
    int tanggal;
    int waktu;
    char nama[50];
}kalender;

kalender makeKegiatan(char kegiatan[], int tanggal, int waktu, char nama[]);

void menu();
void inputKegiatan(kalender P);
void showKegiatan(kalender P);

#endif // PUSTAKA_H_INCLUDED
