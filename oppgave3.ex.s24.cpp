#include <iostream>
using namespace std;

struct Node {
    char ID;
    int pos;
    Node *left, *right;

    bool nesteIPreorder;   


    Node (char id, Node* l, Node* r)

    {   ID = id;    left = l, right = r; }  

};

Node* gRoot = nullptr;      // rot peker
Node* gForrige = nullptr;

// a)

Node* neste(Node* node) {
    if (node == nullptr) return nullptr;

    // 1: Preorder går alltid først til venstre barn
    if (node->left != nullptr)      // Hvis nodens venstre barn eksisterer, returner venstre barn
        return node->left;

    // 2: Hvis det finnes et ekte høyrebarn
    if (!node->nesteIPreorder && node->right != nullptr)        // Hvis noden har et ekte høyrebarn, returner det
        return node->right;

        return node->right;

}

// preorder logikk: Node-> Venstre-> Høyre



