#include "dna_statistics.h"

void dnaStatistics(Node* head, int count[4]) {
    while (head) {
        switch (head->base) {
            case 'A': count[0]++; break;
            case 'T': count[1]++; break;
            case 'C': count[2]++; break;
            case 'G': count[3]++; break;
        }
        head = head->next;
    }
}