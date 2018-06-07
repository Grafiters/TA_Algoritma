#include "pustaka.h"

int jumlah, hapus, b, p, w;
int sampai, limit=0, pilih;
char nama[50];

int main()
{
    kalender acara[100];
    daftar:
//    system("clear");
    system("cls");
    menu();

    printf("Silahkan pilih Menu = "); scanf("%d", &pilih);

    __fpurge(stdin);
    fflush(stdin);
    switch(pilih){
        case 1:
            system("cls");
//            system("clear");
            printf("Masukan jumlah kegiatan = "); scanf("%d", &jumlah);
            sampai = jumlah + limit;
            int j;
            for(j=limit;j<sampai;j++){
                __fpurge(stdin);
                fflush(stdin);
                printf("No. %d\n", j+1);
                inputKegiatan(&acara[j]);
            }
            limit += jumlah;
//            system("clear");
            system("cls");
            goto daftar;
            break;
        case 2:
//            system("clear");
            system("cls");
            printf("1. lihat acara\n");
            printf("2. lihat details acara\n");
            printf("pilih melihat kegiatan = "); scanf("%d", &p);
            if(p==1){
                __fpurge(stdin);
                fflush(stdin);
                int i, k;
                for(k=0;k<sampai;k++){
                    printf("No. %d\n", k+1);
                    showAcara(acara[k]);
                }
                printf("klik 0 untuk kembali ke menu utama = "); scanf("%d", &i);
                if(i==0){
                    goto daftar;
                }else{
                    return 0;
                }
            }else if(p==2){
                int i, k;
//                system("clear");
                system("cls");
                __fpurge(stdin);
                fflush(stdin);
                for(k=0;k<sampai;k++){
                    printf("No. %d\n", k+1);
                    showKegiatan(acara[k]);
                }
                printf("klik 0 untuk kembali ke menu utama = "); scanf("%d", &i);
                if(i==0){
                    goto daftar;
                }else{
                    return 0;
                }
            }else{
                printf("anda salah nomor");
                goto daftar;
            }
            break;
        case 3:
//          system("clear");
            system("cls");
            __fpurge(stdin);
            fflush(stdin);
            int c;
            for(c=0;c<limit;c++){
                printf("No. %d\n", c+1);
                showKegiatan(acara[c]);
            }
            printf("Masukan data yang ingin anda hapus = "); scanf("%d", &hapus);

//            __fpurge(stdin);
            fflush(stdin);

            hapus -= 1;

            showKegiatan(acara[hapus]);

            char yakin;
            printf("apakah anda yakin ingin menghapus data ini (y/n ) = "); scanf("%c", &yakin);
                if(yakin == 'y'){
                    hapuskegiatan(acara,limit);
                }
            limit --;
            goto daftar;
            break;
        case 4:
//            system("clear");
            system("cls");
            int y;
            printf("Masukkan nama yang akan dicari : "); gets(nama);

            cariKegiatan(acara,nama,limit);

            printf("0 kembali ke menu = "); scanf("%d", &y);
            if (y==0)
            {
                goto daftar;
            }
            break;
        case 5:
//            system("clear");
            system("cls");
            int l;
            urutKegiatan(acara,limit);
            printf("klik 0 untuk kembali ke menu utama = "); scanf("%d", &l);
                if(l==0){
                    goto daftar;
                }else{
                    return 0;
                }
//            __fpurge(stdin);
            fflush(stdin);
            break;
        case 6:
//            system("clear");
            system("cls");
            credits();
            int a;
            printf("klik 0 untuk kembali ke menu utama = "); scanf("%d", &a);
                if(a==0){
                    goto daftar;
                }else{
                    return 0;
                }
            break;
        default:
            printf("= Maaf Anda Kurang Beruntung = \n");
 //           __fpurge(stdin);
            fflush(stdin);
    }
    return 0;
}
