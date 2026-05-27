#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    int brojLinii;
    cin >> brojLinii;
    cin.ignore();

    char recenica[300];

    for (int i = 0; i < brojLinii; i++) {
        cin.getline(recenica, 300);

        int brojPalindromi = 0;
        int pocetok = 0;
        int dolzina = strlen(recenica);

        for (int j = 0; j <= dolzina; j++) {
            if (recenica[j] == ' ' || recenica[j] == '\0') {

                int levo = pocetok;
                int desno = j - 1;
                bool ePalindrom = true;

                while (levo < desno) {
                    if (tolower(recenica[levo]) != tolower(recenica[desno])) {
                        ePalindrom = false;
                        break;
                    }
                    levo++;
                    desno--;
                }

                if (ePalindrom && pocetok <= j - 1) {
                    brojPalindromi++;
                }

                pocetok = j + 1;
            }
        }

        cout << brojPalindromi << endl;
    }

    return 0;
}
