#include "pustaka.h"

void menu(){ ///  ==> fungsi ini berguna untuk menampilkan menu yan gada
    puts("====== Kalender Kegiatan ======");
    puts("1. Tambah Kegiatan");
    puts("2. Tampilkan Kegiatan");
    puts("3. Hapus Kegiatan");
    puts("4. Cari Kegiatan");
    puts("5. Urutkan Kegiatan");
    puts("6. Credits");
    puts("");
}

void inputKegiatan(kalender *acara){ /// ==> fungsi ini berguna untuk menginputkand data atau menambahkan data yang ada kepada client
    kalender alarm;
        printf("Masukkan tanggal acara format (dd-mm-yy) = "); scanf("%d-%d-%d", &alarm.tgl.d, &alarm.tgl.m, &alarm.tgl.y);

        /*=====================================================================================*/
        /*          fungsi untuk mengecek apakah data yang dimasukan sudah atau belom          */
        /*kalau data belum benar maka akan mengulang untuk memasukkan data kembali sampai benar*/
        /*=====================================================================================*/

        /*=====================================================================================*/
        /*   fungsi untuk mengecek apakah data tanggal, bulan, tahun sudah benar atau belom    */
        /*=====================================================================================*/

        if(alarm.tgl.d>31||alarm.tgl.d<1){
            printf("format salah silahkan masukan lagi\n");
            printf("Masukkan tanggal acara format (dd-mm-yy) = "); scanf("%d-%d-%d", &alarm.tgl.d, &alarm.tgl.m, &alarm.tgl.y);
        }else if(alarm.tgl.m>12||alarm.tgl.m<1){
            printf("format salah silahkan masukan lagi\n");
            printf("Masukkan tanggal acara format (dd-mm-yy) = "); scanf("%d-%d-%d", &alarm.tgl.d, &alarm.tgl.m, &alarm.tgl.y);
        }else if(alarm.tgl.d==28 && alarm.tgl.m==2 && alarm.tgl.y%4!=0){
            printf("format salah silahkan masukan lagi\n");
            printf("Masukkan tanggal acara format (dd-mm-yy) = "); scanf("%d-%d-%d", &alarm.tgl.d, &alarm.tgl.m, &alarm.tgl.y);
        }else if(alarm.tgl.d>30 && alarm.tgl.m==4 || alarm.tgl.m==6 || alarm.tgl.m==9 || alarm.tgl.m==11){
            printf("format salah silahkan masukan lagi\n");
            printf("Masukan hari dd = "); scanf("%d", &alarm.tgl.d);
        }

        /*=====================================================================================*/
        /*        fungsi untuk mengecek apakah data jam dan menit sudah benar atau belom       */
        /*=====================================================================================*/

        printf("Masukan waktu dengan format hh:mm (jam:menit) = "); scanf("%d:%d", &alarm.wak.h, &alarm.wak.m);
        if(alarm.wak.h>23 || alarm.wak.m>59){
            printf("format salah silahkan masukan lagi\n");
            printf("Masukan waktu dengan format hh:mm (jam:menit) = "); scanf("%d:%d", &alarm.wak.h, &alarm.wak.m);
        }

//        __fpurge(stdin);
        fflush(stdin);

        printf("Masukkan Nama Keigiatan \t= "); gets(alarm.kegiatan);
        printf("Masukkan satu nama yang terkait = "); gets(alarm.nama);

    *acara = alarm;

    return acara;
}

void showAcara(kalender acara){

        /*==============================================================*/
        /*                         Show Acara                           */
        /*fungsi ini berguna untuk menampilkan data dari struct kalender*/
        /*==============================================================*/

        printf("Nama Acara = %s \n", acara.kegiatan);
        printf("Tanggal Acara = %d-%d-%d\n", acara.tgl.d,acara.tgl.m, acara.tgl.y);
}

void cariKegiatan (kalender acara[],char cari_nama[],int batas){

    /*======================================================================*/
    /*                            Cari Kegiatan                             */
    /*   fungsi ini berguna untuk mencari nilai dari data struct yang ada   */
    /*======================================================================*/

    int a,b;
    char z;
    int banding;


    for (a=0;a<batas;a++)
    {
        banding=strcmp(acara[a].nama,cari_nama); ///untuk menyamakan data nama dengan nama yang dicari
        if (banding==0){
            printf("data ditemukan\n");
            printf("apa data ini ditampilkan (y/t): "); scanf("%c",&z); ///untuk memilih mau ditampilkan apa tidak
            if (z=='y'){
                printf("Nama Acara\t\t= %s\n", acara[a].kegiatan);
                printf("Tanggal Acara \t\t= %d-%d-%d\n", acara[a].tgl.d, acara[a].tgl.m, acara[a].tgl.y);
                printf("Waktu Acara \t\t= %d:%d\n", acara[a].wak.h, acara[a].wak.m);
                printf("Nama bersangkutan \t= %s\n", acara[a].nama);
                puts("");
            }
        }else{
            printf("data tidak ditemukan\n");
        }
    }
}

void showKegiatan(kalender acara){

    /*==============================================================*/
    /*                       Show Detail Acara                      */
    /*fungsi ini berguna untuk menampilkan data dari struct kalender*/
    /*==============================================================*/

    printf("Nama Acara\t= %s\n", acara.kegiatan);
    printf("Tanggal Acara \t= %d-%d-%d\n", acara.tgl.d, acara.tgl.m, acara.tgl.y);
    printf("Waktu Acara \t= %d:%d\n", acara.wak.h, acara.wak.m);
    printf("Nama bersangkutan = %s\n", acara.nama);
}

void hapuskegiatan (kalender acara[],int limit){

    /*=====================================================================================*/
    /*                                     Hapus Kegiatan                                  */
    /*            untuk mengatur data yang suda dihapus dan akan ditaruh di bawah          */
    /*=====================================================================================*/

    int i;
    for(i=0;i<limit;i++){
        tukarNilaiSementara(&acara[i], &acara[i+1]);
    }
}

void tukarNilai(int *a, int *b){

    /*=====================================================================================*/
    /*                                     Tukar Nilai                                     */
    /*                            untuk menukar data yang tanggal                          */
    /*=====================================================================================*/

    int temp = *a;
        *a = *b;
        *b = temp;
}

void tukarNilaiSementara(kalender *a, kalender *b){

    /*=====================================================================================*/
    /*                                     Tukar Kegiatan                                  */
    /*                            untuk menukar data dari struct                           */
    /*=====================================================================================*/

    kalender temp = *a;
        *a = *b;
        *b = temp;
}

void urutKegiatan(kalender acara[], int limit){

    /*=====================================================================================*/
    /*                                     Urut Kegiatan                                   */
    /*                     Untuk Menkar urutan Kegiatan yang ada di struct                 */
    /*=====================================================================================*/

    int temp[limit];
    int i,j;
    kalender urut[limit];
    for (i=0;i<limit;i++){
        temp[i]=(acara[i].tgl.d/10)+ acara[i].tgl.m+(acara[i].tgl.y*10);
        urut[i]=acara[i];
    }
    for (i=0;i<limit;i++){
        for(j=i;j<limit;j++){
            if(temp[j]>temp[j+1]){
                tukarNilai(&temp[j],&temp[j+1]);
                tukarNilaiSementara(&urut[j],&urut[j+1]);
            }
        }
    }
}

void credits(){
    puts("Andwingga");
    puts("Grafiters");
    puts("Sendra");
    puts("Edwin");
    puts("Thor");
}
