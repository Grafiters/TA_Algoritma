#include "pustaka.h"

int jumlah;
int sampai, limit=0;

int main()
{
    kalender acara[100];
    daftar:
    menu();

    int pilih;
    printf("Silahkan pilih Menu = "); scanf("%d", &pilih);

    fflush(stdin);
    switch(pilih){
        case 1:
            system("clear");
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
            system("clear");
            goto daftar;
            break;
        case 2:
            printf("1. lihat acara\n");
            printf("2. lihat details acara\n");
            int p;
            printf("pilih melihat kegiatan = "); scanf("%d", &p);
            if(p==1){
                __fpurge(stdin);
                fflush(stdin);
                system("clear");
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
                system("clear");
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
            break;
        case 4:
            break;
        case 5:
            urutKegiatan(acara,limit);
            int i;
            printf("klik 0 untuk kembali ke menu utama = "); scanf("%d", &i);
                if(i==0){
                    goto daftar;
                }else{
                    return 0;
                }
            break;
        case 6:
            credits();
            int i;
            printf("klik 0 untuk kembali ke menu utama = "); scanf("%d", &i);
                if(i==0){
                    goto daftar;
                }else{
                    return 0;
                }
            break;
        default:
            printf("= Maaf Anda Kurang Beruntung = \n");
            __fpurge(stdin);
            fflush(stdin);
    }
    return 0;
}
