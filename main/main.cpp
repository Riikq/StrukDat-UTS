#include <iostream>
#include <unordered_map>
#include <vector>
#include "input_dna.h"
#include "validate_dna.h"
#include "dna_statistics.h"
#include "transcribe_rna.h"
#include "length_freq.h"
#include "amino_translate.h"

void printChain(Node* head) {
    while (head) {
        std::cout << head->base;
        head = head->next;
    }
    std::cout << std::endl;
}

Node* getAntisense(Node* head) {
    Node* antisense = nullptr;
    Node* current = nullptr;
    while (head) {
        char base;
        switch (head->base) {
            case 'A': base = 'T'; break;
            case 'T': base = 'A'; break;
            case 'C': base = 'G'; break;
            case 'G': base = 'C'; break;
            default: base = 'N';
        }
        Node* newNode = new Node(base);
        if (!antisense) {
            antisense = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
        head = head->next;
    }
    return antisense;
}

void showMenu() {
    std::cout << "\n==================== Menu ====================\n";
    std::cout << "1. Tampilkan rantai DNA\n";
    std::cout << "2. Ubah ke rantai antisense\n";
    std::cout << "3. Transkripsi ke mRNA\n";
    std::cout << "4. Hitung panjang rantai\n";
    std::cout << "5. Menerjemahkan menjadi susunan asam amino\n";
    std::cout << "6. Tampilkan riwayat user\n";
    std::cout << "7. Keluar\n";
    std::cout << "\nPilihan: ";
}

int main() {
    std::string input;
    Node* dnaChain = nullptr;

    while (true) {
        std::cout << "Masukkan rantai DNA (huruf A, T, C, G): ";
        std::cin >> input;
        if (isValidDNA(input)) {
            dnaChain = inputDNA(input);
            break;
        } else {
            std::cout << "Rantai DNA tidak valid. Coba lagi.\n";
        }
    }

    std::vector<std::string> history;
    int pilihan;
    char lanjut;

    while (true) {
        showMenu();
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "Rantai DNA: ";
                printChain(dnaChain);
                history.push_back("Tampilkan rantai DNA");
                break;
            case 2: {
                Node* antisense = getAntisense(dnaChain);
                std::cout << "Rantai Antisense: ";
                printChain(antisense);
                history.push_back("Ubah ke rantai antisense");
                break;
            }
            case 3: {
                Node* rnaChain = transcribeToRNA(dnaChain);
                std::cout << "Rantai RNA: ";
                printChain(rnaChain);
                history.push_back("Transkripsi ke mRNA");
                break;
            }
            case 4: {
                int length = 0;
                std::unordered_map<char, int> freq;
                lengthAndFrequency(dnaChain, length, freq);
                std::cout << "Panjang rantai DNA: " << length << std::endl;
                for (auto& pair : freq) {
                    std::cout << pair.first << ": " << pair.second << std::endl;
                }
                history.push_back("Hitung panjang rantai");
                break;
            }
            case 5: {
                Node* rnaChain = transcribeToRNA(dnaChain);
                std::cout << "Terjemahan triplet RNA ke asam amino:\n";
                translateToAminoAcids(rnaChain);
                history.push_back("Menerjemahkan menjadi susunan asam amino");
                break;
            }
            case 6:
                std::cout << "Riwayat aktivitas pengguna:\n";
                for (const auto& h : history) {
                    std::cout << "- " << h << std::endl;
                }
                break;
            case 7:
                std::cout << "Keluar dari program.\n";
                return 0;
            default:
                std::cout << "Pilihan tidak valid. Silakan pilih ulang.\n";
                continue;
        }

        std::cout << "\nKembali ke menu? (y/n): ";
        std::cin >> lanjut;
        if (lanjut != 'y' && lanjut != 'Y') {
            break;
        }
    }

    return 0;
}
