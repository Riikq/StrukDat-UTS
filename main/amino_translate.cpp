#include "amino_translate.h"
#include <unordered_map>
#include <iostream>

void translateToAminoAcids(Node* rna) {
    std::unordered_map<std::string, std::string> codonTable = {
        {"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"}, {"UUG", "Leucine"}, {"UCU", "Serine"},
        {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
        {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"}, {"UGU", "Cysteine"},
        {"UGC", "Cysteine"}, {"UGG", "Tryptophan"}, {"UAA", "Stop"},
        {"UAG", "Stop"}, {"UGA", "Stop"}
    };

    while (rna && rna->next && rna->next->next) {
        std::string codon = "";
        codon += rna->base;
        codon += rna->next->base;
        codon += rna->next->next->base;

        if (codonTable.find(codon) != codonTable.end()) {
            std::string amino = codonTable[codon];
            if (amino == "Stop") break;
            std::cout << codon << " -> " << amino << std::endl;
        } else {
            std::cout << codon << " -> Unknown" << std::endl;
        }
        rna = rna->next->next->next;
    }
}