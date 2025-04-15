#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "amino_acid.h"
using namespace std;

// Struct untuk satu triplet DNA
struct DNATriplet {
    string triplet;

    // Konversi ke RNA
    string toRNA() const {
        string rna = triplet;
        for (char& base : rna) {
            if (base == 'T') base = 'U';
        }
        return rna;
    }

    // Dapatkan asam amino dari kodon RNA
    string getAminoAcid() const {
        static unordered_map<string, string> codonTable = {
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

        string rna = toRNA();
        auto it = codonTable.find(rna);
        if (it != codonTable.end()) {
            return it->second;
        } else {
            return "Invalid";
        }
    }
};

int main() {
    string dnaStrand;
    cout << "Masukkan rantai DNA (panjang kelipatan 3, contoh: ATGCGTACG): ";
    cin >> dnaStrand;

    // Ubah semua huruf jadi kapital
    for (char& c : dnaStrand) c = toupper(c);

    if (dnaStrand.length() % 3 != 0) {
        cout << "Rantai DNA harus kelipatan 3!" << endl;
        return 1;
    }

    vector<DNATriplet> triplets;
    for (size_t i = 0; i < dnaStrand.length(); i += 3) {
        string codon = dnaStrand.substr(i, 3);
        triplets.push_back({codon});
    }

    cout << "\nHasil terjemahan DNA ke asam amino:\n";
    for (const auto& triplet : triplets) {
        string rna = triplet.toRNA();
        string amino = triplet.getAminoAcid();

        cout << triplet.triplet << " (RNA: " << rna << ") → " << amino << endl;

        // Hentikan jika asam amino = Stop
        if (amino == "Stop") break;
    }

    return 0;
}
