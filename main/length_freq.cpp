#include "length_freq.h"

void lengthAndFrequency(Node* head, int& length, std::unordered_map<char, int>& freq) {
    while (head) {
        length++;
        freq[head->base]++;
        head = head->next;
    }
}