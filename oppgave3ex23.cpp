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

// oppgave a)

 void speilvend(Node* n) {
    if (n == nullptr) return;  // sjekker om noden finnes. nullptr betyr at vi har nådd bunnen av treet (ingen flere barn)
    
    Node* temp = n->left;   // lagrer peker til venstre barn midlertidig i temp
    n->left = n->right;     // setter venstre barn til å peke på det som tidligere var høyre barn
    n->right = temp;        // setter høyre barn til å peke på det som var venstre barn før byttet

    speilvend(n->left);     // speilvender venstre under-tre (som opprinnelig var høyre)
    speilvend(n->right);    // speilvender høyre under-tre (som opprinnelig var venstre)


 }

 void settPosisjoner(Node* n, int p) {
    if (n == nullptr) return;     // stopper hvis noden ikke finnes. Base-tilfellet i en rekursjon. Når vi har nådd en tom gren, skal vi ikke gjøre mer

    n->pos = p;     // setter noden pos-verdi til p. For rot vil det være 1. For barn blir det 2*p eller 2*p+1
    settPosisjoner(n->left, 2 * p);       // går videre til venstre barn. Sender 2*p fordi i en binærstruktur, har venstre barn dobbel posisjon
    settPosisjoner(n->right, 2 * p + 1);    // går videre til høyre barn. Høyre barn får posisjon 2 * p + 1
 }

 // oppgave b)

 void speilvend(Node* n, int p) {
    if (n == nullptr) return;

    n->pos = p;     //oppdaterer nodens posisjon

    Node* temp = n->left;

    // fortsett rekursivt med nye venstre og høyre (som allerede er byttet)
    speilvend(n->left, 2 * p);          // venstrebarn får posisjon 2*p
    speilvend(n->right, 2 * p + 1);     // høyre barn får posisjon 2*p + 1
 }

// oppgave c)

Node* finnNode(int p) {
    if (gRoot == nullptr || p < 1) return nullptr;

    Node* curr = gRoot;

    // vi hopper over det første 1-bitet (som representerer rota)
    // finn bitlengden
    int mask = 1 << 30;
    while ((mask & p) == 0) mask >>= 1;     // finn første 1-bitet
    mask >>= 1;     // hopp over første bit (rota)

    while (curr != nullptr && mask > 0) {
        if ((p & mask) == 0) {
            curr = curr->left;      // 0 betyr venstre
        } else {
            curr = curr->right;     // 1 betyr høyre      
          }
          mask >>=1;

    }

    // sikkerhetssjekk
    if (curr != nullptr && curr->pos == p)
        return curr;

    return nullptr;
}
