#include "input_dna.h"

Node* inputDNA(const std::string& input) {
    if (input.empty()) return nullptr;
    Node* head = new Node(input[0]);
    Node* current = head;
    for (size_t i = 1; i < input.length(); ++i) {
        current->next = new Node(input[i]);
        current = current->next;
    }
    return head;
}