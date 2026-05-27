#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int brojac=0;
    int zbir=0;
    int cifra=0;

    int broj;
    for (int i=0;i<n;i++) {
        cin>>broj;
        brojac++;
        if (brojac%2==0) {
            cifra=broj%10;
        }
        if (brojac%2!=0) {
            cifra=(broj/10)%10;
        }
        zbir+=cifra;

    }
    cout<<zbir;


    }


