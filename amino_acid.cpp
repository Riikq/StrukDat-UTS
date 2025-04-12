#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Fungsi untuk mengubah DNA ke RNA
string dnaToRna(const string& dna) {
    string rna = dna;
    for (char& base : rna) {
        if (base == 'T') base = 'U';
    }
    return rna;
}

// Fungsi untuk mendapatkan nama asam amino dari kodon RNA
string getAminoAcid(const string& codon) {
    unordered_map<string, string> codonTable = {
        {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"}, {"UUG", "Leucine"},
        {"CUU", "Leucine"}, {"CUC", "Leucine"}, {"CUA", "Leucine"}, {"CUG", "Leucine"},
        {"AUU", "Isoleucine"}, {"AUC", "Isoleucine"}, {"AUA", "Isoleucine"},
        {"AUG", "Methionine"}, // Start codon
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

    auto it = codonTable.find(codon);
    if (it != codonTable.end()) {
        return it->second;
    } else {
        return "Invalid codon";
    }
}

int main() {
    string dnaTriplet;
    cout << "Masukkan triplet DNA (contoh: ATG): ";
    cin >> dnaTriplet;

    // Ubah ke huruf kapital semua
    for (char& c : dnaTriplet) c = toupper(c);

    // Validasi input
    if (dnaTriplet.length() != 3) {
        cout << "Triplet harus terdiri dari 3 huruf." << endl;
        return 1;
    }

    string rnaCodon = dnaToRna(dnaTriplet);
    string aminoAcid = getAminoAcid(rnaCodon);

    cout << "RNA kodon: " << rnaCodon << endl;
    cout << "Asam amino: " << aminoAcid << endl;

    return 0;
}