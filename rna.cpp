#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node {
    char data;
    Node* next;
};

// FUNGSI DASAR LINKED LIST

Node* buatNode(char huruf) {
    Node* baru = new Node;
    baru->data = huruf;
    baru->next = NULL;
    return baru;
}

void tampilkan(Node* mulai) {
    Node* sekarang = mulai;
    while (sekarang != NULL) {
        cout << sekarang->data;
        if (sekarang->next != NULL) {
            cout << " -> ";
        }
        sekarang = sekarang->next;
    }
    cout << endl;
}

// FITUR: INPUT & MANIPULASI DNA

void inputDNA(Node*& head, string dna) {
    head = NULL;
    Node* akhir = NULL;

    for (int i = 0; i < dna.length(); i++) {
        Node* nodeBaru = buatNode(dna[i]);
        if (head == NULL) {
            head = nodeBaru;
            akhir = head;
        } else {
            akhir->next = nodeBaru;
            akhir = nodeBaru;
        }
    }
}

// FUNGSI BARU: Ubah Rantai ke Antisense

Node* transkripsiKeRNA(Node* dna) {
    Node* rna = NULL;
    Node* akhir = NULL;
    Node* sekarang = dna;

    while (sekarang != NULL) {
        char hasil;

        if (sekarang->data == 'A') hasil = 'U';
        else if (sekarang->data == 'T') hasil = 'A';
        else if (sekarang->data == 'C') hasil = 'G';
        else if (sekarang->data == 'G') hasil = 'C';
        else hasil = '?';

        Node* nodeBaru = buatNode(hasil);

        if (rna == NULL) {
            rna = nodeBaru;
            akhir = rna;
        } else {
            akhir->next = nodeBaru;
            akhir = nodeBaru;
        }

        sekarang = sekarang->next;
    }

    return rna;
}

// ===================
// PROGRAM UTAMA (MAIN)
// ===================

int main() {
    Node* head = NULL;
    string input;
    cout << "Masukkan rantai DNA (contoh: ATCG): ";
    cin >> input;

    inputDNA(head, input);

    cout << "\nDNA asli        : ";
    tampilkan(head);

    Node* rna = transkripsiKeRNA(head);
    cout << "Hasil RNA   : ";
    tampilkan(rna);

    return 0;
}
