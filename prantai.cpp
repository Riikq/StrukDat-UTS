#include <iostream>
using namespace std;

struct Node {
    char data;     
    Node* next;   
};

void tambahNukleotida(Node*& head, char nukleotida) {
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

int hitungPanjang(Node* head) {
    int panjang = 0;
    Node* temp = head;
    while (temp != nullptr) {
        panjang++;
        temp = temp->next;
    }
    return panjang;
}

void tampilkanRantai(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* rantaiDNA = nullptr;
    string input;

    cout << "Masukkan rantai DNA (contoh: ATCGTA): ";
    cin >> input;

    for (char nukleotida : input) {
        tambahNukleotida(rantaiDNA, nukleotida);
    }

    cout << "Rantai DNA: ";
    tampilkanRantai(rantaiDNA);

    int panjang = hitungPanjang(rantaiDNA);
    cout << "Panjang rantai: " << panjang << endl;

    return 0;
}
