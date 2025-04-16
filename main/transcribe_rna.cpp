#include "transcribe_rna.h"

Node* transcribeToRNA(Node* dna) {
    Node* rnaHead = nullptr;
    Node* currentRNA = nullptr;
    while (dna) {
        char base;
        switch (dna->base) {
            case 'A': base = 'U'; break;
            case 'T': base = 'A'; break;
            case 'C': base = 'G'; break;
            case 'G': base = 'C'; break;
            default: base = 'N';
        }
        Node* newNode = new Node(base);
        if (!rnaHead) {
            rnaHead = newNode;
            currentRNA = newNode;
        } else {
            currentRNA->next = newNode;
            currentRNA = newNode;
        }
        dna = dna->next;
    }
    return rnaHead;
}