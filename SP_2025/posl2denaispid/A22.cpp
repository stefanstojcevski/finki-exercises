#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int SVRZNICI(char a[]) {
    int brojac = 0;
    int dolzina = 0;
    int n = strlen(a);

    for (int i = 0; i <= n; i++) {
        if (isalpha(a[i])) {
            dolzina++;
        } else {

            if (dolzina >= 1 && dolzina <= 3) {
                brojac++;
            }
            dolzina = 0;
        }
    }

    return brojac;
}
int main() {
    char a[100];
    int max=-1;
    char b[100];
    int br;
    while (cin.getline(a,100)) {
        br=SVRZNICI(a);
        if (br>max) {
            max=br;
            strcpy(b,a);

        }
    }
    cout<<max<<":"<<b;



}