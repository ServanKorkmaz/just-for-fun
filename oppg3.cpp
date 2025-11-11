#include <iostream>
using namespace std;

// a)

struct Node {
    int ID;
    Node* left;
    Node* right;
    Node (int id) : ID(id), left(nullptr), right(nullptr) {}
};

    Node *gRoot = nullptr;
    const int MAX = 999;

int minimumHoyde(const Node* t) {
    







