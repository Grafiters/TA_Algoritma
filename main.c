#include "pustaka.h"

int main()
{
    daftar:
    menu();
    int pilih;
    printf("Silahkan pilih Menu = "); scanf("%d", &pilih);
    fflush(stdin);
    switch(pilih){
        case 1:
            inputKegiatan();
            system("cls");
            goto daftar;
            break;
        case 2:
            showKegiatan();
            system("cls");
            goto daftar;
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            urutKegiatan(batas);
            showKegiatan();
            break;
    }

    return 0;
}
