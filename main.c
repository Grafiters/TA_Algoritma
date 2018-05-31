#include "pustaka.h"

int jumlah;
int sampai = 0;

int main()
{
    kalender acara;
    daftar:
    menu();

    int pilih;
    printf("Silahkan pilih Menu = "); scanf("%d", &pilih);

    sampai = sampai + jumlah;

    fflush(stdin);
    switch(pilih){
        case 1:
            printf("Masukan jumlah kegiatan = "); scanf("%d", &jumlah);
            inputKegiatan(&acara, jumlah);
            goto daftar;
            break;
        case 2:
            printf("1. lihat acara\n");
            printf("2. lihat details acara\n");
            int p;
            printf("pilih melihat kegiatan = "); scanf("%d", &p);
            if(p==1){
                int i;
                showAcara(acara,sampai);
                printf("klik 0 untuk kembali ke menu utama = "); scanf("%d", &i);
                if(i==0){
                    goto daftar;
                }
            }else if(p==2){
                int i;
                showKegiatan(acara, sampai);
                printf("klik 0 untuk kembali ke menu utama = "); scanf("%d", &i);
                if(i==0){
                    goto daftar;
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
            break;
    }
    return 0;
}
