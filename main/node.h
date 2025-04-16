#ifndef NODE_H
#define NODE_H

struct Node {
    char base;
    Node* next;
    Node(char b) : base(b), next(nullptr) {}
};

#endif