#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int SVRZNICI(char a[]) {
    int brojac = 0, dolzina = 0;
    int n = strlen(a);

    for (int i = 0; i <= n; i++) {
        if (!isspace((unsigned char)a[i]) && !ispunct((unsigned char)a[i])) {
            dolzina++;
        } else {
            if (dolzina >= 1 && dolzina <= 3)
                brojac++;
            dolzina = 0;
        }
    }
    return brojac;
}

int main() {
    char a[101], b[101];
    b[0] = '\0';

    int max = -1, br;

    while (cin.getline(a, 101)) {
        br = SVRZNICI(a);
        if (br > max) {
            max = br;
            strcpy(b, a);
        }
    }

    cout << max << ": " << b;
    return 0;
}