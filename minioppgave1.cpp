#include <iostream>
using namespace std;

struct Node {
    char ID;
    int post;
    Node *left, *right;

    Node (char id, int p)
    { ID = id; post = p; left = right = nullptr; };


    int main() {
    Node* node = new Node ('A', 1); //  Lager en rot node med ID 'A' og posisjon 1
    Node* left = new Node ('B', 2);
    Node* right = new Node ('C', 3); 

    // koble barna til node    
    node->left = left;
    node->right = right;

    // skriv ut info om alle tre noder
    cout << "Root:  "   << node->ID << ", pos:  " << node->post << endl;
    cout << "Left:  "   << node->left->ID << ", pos: " << node->left->post << endl;
    cout << "Right: "   << node->right->ID << ", pos " << node->right->post << endl;

    return 0;

    }

};

