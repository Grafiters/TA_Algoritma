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
        if(data[i].tgl.d>28 && data[i].tgl.m==2 && data[i].tgl.y%4 != 0){
            printf("format anda salah silahkan masukkan kembali = ");
            scanf("%d-%d-%d", &data[i].tgl.d, &data[i].tgl.m, &data[i].tgl.y);
        }else if(data[i].tgl.d>31){
            printf("format anda salah silahkan masukkan kembali = ");
            scanf("%d-%d-%d", &data[i].tgl.d, &data[i].tgl.m, &data[i].tgl.y);
        }else if(data[i].tgl.m>12){
            printf("format anda salah silahkan masukkan kembali = ");
            scanf("%d-%d-%d", &data[i].tgl.d, &data[i].tgl.m, &data[i].tgl.y);
        }

        puts("");
        printf("Masukkan waktu kegiatan (hh:mm) : ");
        scanf("%d-%d", &data[i].wak.h, &data[i].wak.m);
        if(data[i].wak.h>23){
            printf("format anda salah silahkan masukkan kembali = ");
            scanf("%d-%d", &data[i].wak.h, &data[i].wak.m);
        }else if(data[i].wak.m>59){
            printf("format anda salah silahkan masukkan kembali = ");
            scanf("%d-%d", &data[i].wak.h, &data[i].wak.m);
        }

        puts("");
        fflush(stdin);
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

int tukar(int *num1, int *num2){
    int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
}

int inner_rec(int data[], int cur, int arrSize){
    if(data[arrSize-1]<data[cur]){
        return cur=arrSize;
    }else{
        return inner_rec(data,cur,arrSize-1);
    }
}

void urutKegiatan(int batas){
    if(batas==0){
        int post=inner_rec(data,batas-1,batas);
        tukar(&data[post],&data[batas-1]);
    }else{
        int post=inner_rec(data,batas-1,batas);
        tukar(&data[post],&data[batas-1]);
        urutKegiatan(batas-1);
    }
}
