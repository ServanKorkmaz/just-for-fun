#include <iostream>
using namespace std;

// funksjonen du skal skrive
void flettToSorterteArrayer(int a[], const int b[], const int aLen, const int bLen) {
    int write = aLen - 1;
    for (int read = aLen - 1; read >=0; --read) {
        if (a[read] != 0) {         // 0 betyr "tom plass"
            a[write] = a[read];     // Flytt tallet bakerst
            --write;                // Flytt en plass til venstre
        }
    }

    // 2) Start fletting
    int i = write + 1;
    int j = 0;
    int k = 0;

    // 3) Flett sammen a[i..] og b[j..] inn i a[k]
    while (i <aLen && j < bLen) {
        if (a[i] <= b[j]) {
            a[k++] = a[i++];        // Ta fra a-delen
        } else {
            a[k++] = b[j++];        // Ta fra b-delen
        }
    }

    // 4) Kopier eventuelle rester
    while (i < aLen) a[k++] = a[i++];       // Rest fra a
    while (j < bLen) a[k++] = b[j++];       // Rest fra b

}

// Test (kan slettes på eksamen)
int main() {
    int a[15] = { -8, -4, 0, 0, -1, 3, 7, 0, 0, 9, 11, 0, 0, 15, 19 };
    int b[6]  = { -10, -3, -1, 4, 9, 24 };

    flettToSorterteArrayer(a, b, 15, 6);

    cout << "Etter fletting:\n";
    for (int i = 0; i < 15; ++i) cout << a[i] << " ";
    cout << endl;
}


