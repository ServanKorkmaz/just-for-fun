#include <iostream>
using namespace::std;

struct Node {
 int ID;
 Node *left, *right; 
 Node(int id) { ID = id; left = right = nullptr; }
};

Node* gRoot = nullptr;
const int MAX = 999;


int minimumHoyde(const Node* t) {
    if (t == nullptr) return 0;

    if (t->left == nullptr && t->right == nullptr)
    return 1;

    // start på høyeste
    int venstre = MAX;
    int høyre = MAX;

    if (t->left !=nullptr)
        venstre = minimumHoyde(t->left);

    if (t->right != nullptr)
        høyre = minimumHoyde(t->right);

    return 1 + std::min(venstre, høyre);


}