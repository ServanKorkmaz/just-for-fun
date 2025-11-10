#include <iostream>
#include <string>
using namespace std;

struct Node {
    int ID;
    Node* left;
    Node* right;
    Node(int id) : ID(id), left(nullptr), right(nullptr) {}
};

const int MAX = 999;

// ----- printTree (must match the call exactly) -----
void printTree(const Node* t, int level = 0) {
    if (!t) return;
    printTree(t->right, level + 1);
    cout << string(level * 4, ' ') << t->ID << "\n";
    printTree(t->left, level + 1);
}

// ----- Oppgave 3b -----
int slettNoderPaaStiMedMinSum(Node*& t, const int sum, const int min) {
    if (t == nullptr)
        return sum;

    const int cur = sum + t->ID;

    const int leftMax  = slettNoderPaaStiMedMinSum(t->left,  cur, min);
    const int rightMax = slettNoderPaaStiMedMinSum(t->right, cur, min);

    int best = cur;
    if (leftMax  > best) best = leftMax;
    if (rightMax > best) best = rightMax;

    if (best < min) {
        delete t;
        t = nullptr;
    }
    return best;
}

// ----- main (for testing) -----
int main() {
    Node* r = new Node(4);
    r->left = new Node(3);
    r->right = new Node(6);

    r->left->left = new Node(1);
    r->left->right = new Node(2);

    r->left->left->left = new Node(11);
    r->left->right->left = new Node(5);
    r->left->right->right = new Node(8);

    r->right->left = new Node(10);
    r->right->right = new Node(9);
    r->right->right->left = new Node(7);

    cout << "TREE BEFORE DELETION:\n";
    printTree(r);

    int best = slettNoderPaaStiMedMinSum(r, 0, 18);
    cout << "\nLongest path sum = " << best << "\n";

    cout << "\nTREE AFTER DELETION:\n";
    printTree(r);
}
