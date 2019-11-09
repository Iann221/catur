#include <stdio.h>

void move();

// dalam list linier, ada struct nama yang minta jenis bidanya dan struct posisi yang ngasi tau posisinya
// buat tipe data baru bernama Map, nama map : pion1, pion2, benteng1, buat 16 (nama-nama di list linier)
// isi structnya jenis bidak (pion, queen, benteng, dll) dan nomor (1,2,...,16)
// arr_bidak = ['Pion1','Pion2', .... , 'Benteng2']

void move() {
    // cek giliran hitam atau putih untuk menentukan list linier yang akan diakses, cek dari queue
    List giliran;
    CreateEmpty(&giliran);
    if (Head(queue) == putih) {
        giliran = list_ada_putih;
    }
    else {
        giliran = list_ada_hitam;
    }
    // lihat bidak yang masih ada di papan dari list linier dan memasukkan ke list_bisa_gerak
    List list_bisa_gerak;
    CreateEmpty(&list_bisa_gerak);
    address P;
    P = First(giliran);
    while (P != Nil) {
        if (cekbisagerak(Info(P).nama)) {
            InsVLast(&list_bisa_gerak , Info(P));
        }
    }
        
    // tampilkan bidak yang dapat bergerak
    P = First(list_bisa_gerak);
    int i;
    i = 1;
    printf("Daftar bidak yang bisa bergerak:\n");
    while (P != Nil) {
        printf("  %d. ", i);
        i++;
        PrintNamaBidak(Info(P).nama);
        printf(" (%d,%d)\n",Info(P).PosisiC,Info(P).PosisiR);
    }

    // disini user input nomor bidak yang ingin ia gerakkan
    printf("Pilih bidak yang ingin digerakkan: ");
    int input_nomor_bidak;
    scanf("%d",&input_nomor_bidak);
    // buat arr_available_kum itu arr_available versi kumulatif, jadi kita tau user ingin bidak apa yang digerakkan
    int arr_available_kum[16];
    // isi nilai arr_available_kum
    int jumlah_sementara;
    jumlah_sementara = 0;
    for (i = 1 ; i <= 16 ; i++) {
        if (arr_available[i] != 0) {
            arr_available_kum[i] = arr_available[i] + jumlah_sementara;
            jumlah_sementara = arr_available_kum[i];
        }
    }
    // kasi pilihan gerak berdasarkan input user
    i = 1;
    while (arr_available_kum[i] != input_nomor_bidak) {
        i++;
    }
    // sekarang i berisi indeks arr_kum yang mengandung nomor bidak yang ingin digerakkan menurut arr_bidak
    cekPilihanGerak(arr_bidak[i]); // prosedur ini menampilkan pilihan kemana aja dia bisa gerak, ingat variabel statik biar bisa diakses selanjutnya
    char input_posisi_selanjutnya[8];
    scanf("%s",&input_posisi_selanjutnya);
    // akses array yang ada di pilihan gerak bidaknya
    printf("Bidak kuda telah berpindah dari %s ke %s\n", {{gatau apa}} , {{gatau apa}});
}