#include <iostream>
using namespace std;

struct Node {
    char ID;
    int pos;
    Node *left, *right;
    Node (char id, Node* l, Node* r)

    {   ID = id;    left = l, right = r; }  

};

Node* gRoot = nullptr;      // rot peker

// b)
// rekursiv funksjon 
// Funksjonen skal (som i oppg. a1) sørge for at treet traverseres på en inorder måte, og at hver node får hver sin linje med utskrift på formen ”(X, k)”.

void skriv(Node* node, int nr) {
    if (node == nullptr) return;

    // 1. Venstre subtre, med nr*2
    skriv(node->left, nr * 2);

    // 2. Skriv denne noden
    cout << "(" << node->ID << ", " << nr << ")" << endl;

    // 3. Høyre subtre, med nr*2+1
    skriv(node->right, nr * 2 + 1);

}

// c)
// Funksjonen(e) skal returnere true/false til om minst en node i treet har ID lik id. NB: Husk at treet ikke er et binært søketre - det er totalt usortert.


bool finn(Node* node, char id) {
    if (node == nullptr) return;

    // treffer vi noden?
    if (node->ID == id) return true;

    // søk i venstre eller høyre subtre
    return finn(node->left, id) || finn(node->right, id);

}




