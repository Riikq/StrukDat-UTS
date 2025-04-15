#include <iostream>
#include <string>
using namespace std;

void tampilkanMenu() {
    cout << "\n===== MENU SIMULASI DNA/RNA =====\n";
    cout << "1. Input Ranta Sense\n";
    cout << "2. Tampilkan Rantai Sense DNA\n";
    cout << "3. Ubah ke Rantai Antisense\n";
    cout << "4. Transkripsi ke mRNA\n";
    cout << "5. Hitung Panjang Rantai DNA\n";
    cout << "6. Menerjemahkan menjadi Susunan Asam Amino\n";
    cout << "7. Tampilkan Riwayat Perubahan\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

void menu() {
    int pilihan;
    tampilkanMenu();
    cin >> pilihan;

    while (pilihan != 0) {
        if (pilihan == 1) {
            inputDNA();
        } else if (pilihan == 2) {
            tampilkanRantaiSense();
        } else if (pilihan == 3) {
            ubahKeAntiSense();
        } else if (pilihan == 4) {
            transkripsiKeRNA();
        } else if (pilihan == 5) {
            getAminoAcid();
        } else if (pilihan == 6) {
            hitung_Panjang(dnaHead){}
        } else if (pilihan == 7) {
            tampilkan_histori();
        } else {
            cout << "Pilihan tidak valid.\n";
        }

        tampilkanMenu();
        cin >> pilihan;
    }

    cout << "Keluar dari program.\n";
}
