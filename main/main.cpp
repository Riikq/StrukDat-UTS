#include <iostream>
#include <unordered_map>
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

int main() {
    std::string input;
    std::cout << "Masukkan rantai DNA (huruf A, T, C, G): ";
    std::cin >> input;

    if (!isValidDNA(input)) {
        std::cout << "Rantai DNA tidak valid.\n";
        return 1;
    }

    Node* dnaChain = inputDNA(input);
    std::cout << "Rantai DNA: ";
    printChain(dnaChain);

    int count[4] = {0};
    dnaStatistics(dnaChain, count);
    std::cout << "Jumlah A: " << count[0] << ", T: " << count[1]
              << ", C: " << count[2] << ", G: " << count[3] << std::endl;

    Node* rnaChain = transcribeToRNA(dnaChain);
    std::cout << "Rantai RNA: ";
    printChain(rnaChain);

    int length = 0;
    std::unordered_map<char, int> freq;
    lengthAndFrequency(dnaChain, length, freq);
    std::cout << "Panjang rantai DNA: " << length << std::endl;
    for (auto& pair : freq) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Terjemahan triplet RNA ke asam amino:\n";
    translateToAminoAcids(rnaChain);

    return 0;
}