#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node {
    char data;
    Node* next;
};

// ========================
// FUNGSI DASAR LINKED LIST
// ========================

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
// =============================
// FITUR: INPUT & MANIPULASI DNA
// =============================

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

// ======================================
// FUNGSI BARU: Ubah Rantai ke Antisense
// ======================================

Node* ubahKeAntisense(Node* sense) {
    Node* antisense = NULL;
    Node* akhir = NULL;
    Node* sekarang = sense;

    while (sekarang != NULL) {
        char pasangan;

        if (sekarang->data == 'A') pasangan = 'T';
        else if (sekarang->data == 'T') pasangan = 'A';
        else if (sekarang->data == 'C') pasangan = 'G';
        else if (sekarang->data == 'G') pasangan = 'C';
        else pasangan = '?';

        Node* baru = buatNode(pasangan);

        if (antisense == NULL) {
            antisense = baru;
            akhir = antisense;
        } else {
            akhir->next = baru;
            akhir = baru;
        }

        sekarang = sekarang->next;
    }

    return antisense;
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

    Node* antisense = ubahKeAntisense(head);
    cout << "Antisense DNA   : ";
    tampilkan(antisense);

    return 0;
}
