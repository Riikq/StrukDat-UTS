#include "amino_translate.h"
#include <unordered_map>
#include <iostream>

void translateToAminoAcids(Node* rna) {
    std::unordered_map<std::string, std::string> codonTable = {
        {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"}, {"UUG", "Leucine"},
        {"CUU", "Leucine"}, {"CUC", "Leucine"}, {"CUA", "Leucine"}, {"CUG", "Leucine"},
        {"AUU", "Isoleucine"}, {"AUC", "Isoleucine"}, {"AUA", "Isoleucine"},
        {"AUG", "Methionine"},
        {"GUU", "Valine"}, {"GUC", "Valine"}, {"GUA", "Valine"}, {"GUG", "Valine"},
        {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
        {"CCU", "Proline"}, {"CCC", "Proline"}, {"CCA", "Proline"}, {"CCG", "Proline"},
        {"ACU", "Threonine"}, {"ACC", "Threonine"}, {"ACA", "Threonine"}, {"ACG", "Threonine"},
        {"GCU", "Alanine"}, {"GCC", "Alanine"}, {"GCA", "Alanine"}, {"GCG", "Alanine"},
        {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
        {"UAA", "Stop"}, {"UAG", "Stop"}, {"UGA", "Stop"},
        {"CAU", "Histidine"}, {"CAC", "Histidine"},
        {"CAA", "Glutamine"}, {"CAG", "Glutamine"},
        {"AAU", "Asparagine"}, {"AAC", "Asparagine"},
        {"AAA", "Lysine"}, {"AAG", "Lysine"},
        {"GAU", "Aspartic acid"}, {"GAC", "Aspartic acid"},
        {"GAA", "Glutamic acid"}, {"GAG", "Glutamic acid"},
        {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"CGU", "Arginine"}, {"CGC", "Arginine"}, {"CGA", "Arginine"}, {"CGG", "Arginine"},
        {"AGU", "Serine"}, {"AGC", "Serine"},
        {"AGA", "Arginine"}, {"AGG", "Arginine"},
        {"GGU", "Glycine"}, {"GGC", "Glycine"}, {"GGA", "Glycine"}, {"GGG", "Glycine"}
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