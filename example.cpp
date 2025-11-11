#include <iostream>
using namespace std;

struct Node {
    int ID;
    Node *left;
    Node *right;
    node(int ID) { ID = id; left = right = nullptr; }
}

int main() {
    Node* r = new Node(10);     // ny node i minnet med id 10
    r->left = new Node(5);      // ny bladnode for venstre med id 5
    r->right = new Node(20);    // ny bladnode for høyre med id 20
    r->right->left = new node(15)

    cout << "min-høyde = " << minimumHoyde(r) << endl;

}