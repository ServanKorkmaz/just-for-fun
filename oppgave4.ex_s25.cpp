#include <iostream>
#include <string>
#include <cctype>   // for islower, isupper, tolower, toupper

using namespace std;

int main() {
    // startteksten du skal jobbe med:
    string txt = "dabAcCaCBAcCcaDA";

    // vi bruker en while-løække: fortsetter helt til vi ikke får gjort en fjerning
    bool endring = true;

    while (endring) {
        endring = false;    // antar ingen endring denne runden

        // vi må alltid starte fra starten av strenger
        for (int i = 0; i < (int)txt.length() - 1; i++) {

            char a = txt[i];    // første bokstav
            char b = txt[i + 1];    // neste bokstav


            // sjekk om a og b er samme bokstav men ulik strl
            // tolower(a) == tolower(b) sjekker "A == a"
            // a !=b sikrer at de ikke er begge store eller begge små
            if (tolower(a) == tolower(b) && a != b) {

                // FJERN begge tegnene
                txt.erase(i, 2);

                // marker at vi gjorde en endring
                endring = true;

                // bryt for-løkken fordi vi skal starte helt på nytt
                break;
            }

        }
    }

    // skriv sluttresultatet
    cout << "Sluttekst; " << txt << endl;

    return 0;
 }
