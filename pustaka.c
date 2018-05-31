#include "pustaka.h"

void menu(){ ///  ==> fungsi ini berguna untuk menampilkan menu yan gada
    puts("====== Kalender Kegiatan ======");
    puts("1. Tambah Kegiatan");
    puts("2. Tampilkan Kegiatan");
    puts("3. Hapus Kegiatan");
    puts("4. Cari Kegiatan");
    puts("5. Urutkan Kegiatan");
    puts("");
}

void inputKegiatan(kalender *acara, int batas){ /// ==> fungsi ini berguna untuk menginputkand data atau menambahkan data yang ada kepada client
    kalender alarm;
    int i=0;
    while(i<batas){
        printf("===== Data Ke - %d =====\n", i+1);
        printf("Masukkan tanggal acara format (dd-mm-yy) = "); scanf("%d-%d-%d", &alarm.tgl.d, &alarm.tgl.m, &alarm.tgl.y);
        if(alarm.tgl.d>31){
            printf("format salah silahkan masukan lagi\n");
            printf("Masukan hari dd = "); scanf("%d", &alarm.tgl.d);
        }else if(alarm.tgl.m>12){
            printf("format salah silahkan masukan lagi\n");
            printf("Masukan bulan mm = "); scanf("%d", &alarm.tgl.m);
        }else if(alarm.tgl.d==28 && alarm.tgl.m==2 && alarm.tgl.y%4!=0){
            printf("format salah silahkan masukan lagi\n");
            printf("Masukkan tanggal acara format (dd-mm-yy) = "); scanf("%d-%d-%d", &alarm.tgl.d, &alarm.tgl.m, &alarm.tgl.y);
        }

        printf("Masukan waktu dengan format hh:mm (jam:menit) = "); scanf("%d:%d", &alarm.wak.h, &alarm.wak.m);
        if(alarm.wak.h>23 || alarm.wak.m>59){
            printf("format salah silahkan masukan lagi\n");
            printf("Masukan waktu dengan format hh:mm (jam:menit) = "); scanf("%d:%d", &alarm.wak.h, &alarm.wak.m);
        }

        __fpurge(stdin);
        fflush(stdin);

        printf("Masukkan Nama Keiagatan = "); gets(alarm.kegiatan);
        printf("Masukkan satu nama yang terkait = "); gets(alarm.nama);
        i++;
    }

    *acara = alarm;

    return acara;
}

void showAcara(kalender acara, int batas){
    int i=0;
    while(i<batas){
        printf("Nama Acara = %s \n", acara.kegiatan);
        printf("Tanggal Acara = %d-%d-%d\n", acara.tgl.d,acara.tgl.m, acara.tgl.y);
        i++;
    }
}

void showKegiatan(kalender acara, int batas){
    int i=0;
    while(i<batas){
        printf("No. %d\n", i+1);
        printf("Nama Acara \t= %s \n", acara.kegiatan);
        printf("Tanggal Acara \t= %d-%d-%d \n", acara.tgl.d, acara.tgl.m, acara.tgl.y);
        printf("Waktu Acara \t= %d:%d\n", acara.wak.h, acara.wak.m);
        printf("Nama bersangkutan = %s \n", acara.nama);
        i++;
    }
}

int hitungBatas(int batas){
    int hasil;
    hasil = hasil+batas;
    return hasil;
}

void credits(){
    puts("Andwingga");
    puts("Grafiters");
    puts("Sendra");
    puts("Edwin");
    puts("Thor");
}
