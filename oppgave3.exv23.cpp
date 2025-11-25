#include <iostream>
using namespace std;

struct Node {
    char ID;
    int pos;
    Node *left, *right;
    Node (char id,  int p)

    {   ID = id;    pos = p;    left = right = nullptr; }   // roten har ingen barn. Høyre og venstre er null

};

 Node* gRoot = nullptr;

 