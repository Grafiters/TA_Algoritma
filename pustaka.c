#include "pustaka.h"

void menu(){ ///  ==> fungsi ini berguna untuk menampilkan menu yan gada
    puts("====== Kalender Kegiatan ======");
    puts("1. Tambah Kegiatan");
    puts("2. Tampilkan Kegiatan");
    puts("3. Hapus Kegiatan");
    puts("4. Cari Kegiatan");
    puts("5. Urutkan Kegiatan");
}

void inputKegiatan(){ /// ==> fungsi ini berguna untuk menginputkand data atau menambahkan data yang ada kepada client
    int i=0;
    printf("Masukan banyak data : "); scanf("%d", &batas);

    while(i<batas){
        printf("No. %d\n", i+1);
        printf("Masukan tanggal kegiatan (dd-mm-yy) : ");
        scanf("%d-%d-%d", &data[i].tgl.d, &data[i].tgl.m, &data[i].tgl.y);

        puts("");
        printf("Masukkan waktu kegiatan (mm:hh) : ");
        scanf("%d-%d", &data[i].wak.m, &data[i].wak.h);

        puts("");
        __fpurge(stdin);
        printf("Masukkan Nama Kegiatan : "); gets(data[i].kegiatan);
        printf("Masukkan Nama Terkait : "); gets(data[i].nama);
        i++;
    }
}

void showKegiatan(){ /// ==> fungsi ini berguna untuk menampilkan data yang ada pada ADT kalender
    int i=0;
    while(i<batas){
        printf("No. %d\n", i+1);
        printf("Tanggal Kegiatan : %d-%d-%d\n", data[i].tgl.d, data[i].tgl.m, data[i].tgl.y);
        printf("Nama Kegiatan : %s\n", data[i].kegiatan);
        printf("Orang Terkait : %s\n", data[i].nama);
        printf("Waktu Kegiatan : %d:%d", data[i].wak.m, data[i].wak.h);
        i++;
    }
}
