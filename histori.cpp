#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void tambah_nukleotida(Node*& head, char nukleotida) {
    Node* baru = new Node{nukleotida, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilkan_rantai(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

string rantaiKeString(Node* head) {
    string hasil;
    Node* temp = head;
    while (temp != nullptr) {
        hasil += temp->data;
        temp = temp->next;
    }
    return hasil;
}

void mutasi(Node*& head, int posisi, char nukleotidaBaru) {
    Node* temp = head;
    int indeks = 1;
    while (temp != nullptr && indeks < posisi) {
        temp = temp->next;
        indeks++;
    }
    if (temp != nullptr) {
        temp->data = nukleotidaBaru;
        cout << "Mutasi berhasil dilakukan pada posisi " << posisi << "!" << endl;
    } else {
        cout << "Posisi tidak ditemukan!" << endl;
    }
}

int main() {
    Node* rantaiDNA = nullptr;
    vector<string> histori;
    string input;
    int pilihan;

    cout << "Masukkan rantai DNA awal (contoh: ATCG): ";
    cin >> input;

    for (char nukleotida : input) {
        tambah_nukleotida(rantaiDNA, nukleotida);
    }
    histori.push_back(rantaiKeString(rantaiDNA));

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tampilkan rantai DNA\n";
        cout << "2. Mutasi DNA\n";
        cout << "3. Tampilkan histori perubahan\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Rantai DNA saat ini: ";
            tampilkan_rantai(rantaiDNA);
        } else if (pilihan == 2) {
            int pos;
            char baru;
            cout << "Masukkan posisi yang ingin diubah: ";
            cin >> pos;
            cout << "Masukkan nukleotida baru: ";
            cin >> baru;
            mutasi(rantaiDNA, pos, baru);
            histori.push_back(rantaiKeString(rantaiDNA)); // Simpan ke histori
        } else if (pilihan == 3) {
            cout << "\nHistori perubahan rantai:\n";
            for (int i = 0; i < histori.size(); ++i) {
                cout << "Versi " << i+1 << ": ";
                for (int j = 0; j < histori[i].length(); ++j) {
                    cout << histori[i][j];
                    if (j != histori[i].length() - 1) cout << " -> ";
                }
                cout << endl;
            }
        } else if (pilihan == 4) {
            cout << "Program selesai.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
