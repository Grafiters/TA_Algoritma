#include "pustaka.h"

void menu(){
    puts("====== Kalender Kegiatan ======");
    puts("1. Tambah Kegiatan");
    puts("2. Tampilkan Kegiatan");
    puts("3. Hapus Kegiatan");
    puts("4. Cari Kegiatan");
    puts("5. Urutkan Kegiatan");
}

kalender makeKegiatan(char kegiatan[], int tanggal, int waktu, char nama[]){
    kalender baru;
    strcpy(baru.kegiatan, kegiatan);
    strcpy(baru.nama, nama);
    baru.tanggal = tang;
    baru.waktu = wak;
}

void inputKegiatan(){
    kalender P;
    printf("Masukan Namak Kegiatan = "); gets(P.kegiatan);
    printf("Masukan tanggal kegiatan = "); scanf("%d", &P.tanggal);
    printf("Masukkan Waktu Kegiatan = "); scanf("%d", &P.waktu);
    printf("Masukkan nama terkait = "); gets(P.nama);
}

void showKegiatan(kalender P){
    printf("%d %s %d %s", P.tanggal, P.kegiatan, P.waktu, P.nama);
}
