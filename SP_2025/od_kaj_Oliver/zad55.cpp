/*
 *LAB 3 Да се имплементира рекурзивна функција void printAlphabet
 *(char c, bool backwards) која ке спроведува печатење на латиничната азбука почнувајќи од буквата c.
 *Доколку backwards е true во таа ситуација печатењето оди кон почетокот, а доколку е false, печатењето оди кон крајот.
 *
 *
 *
 **/

#include<iostream>
using namespace std;
void azbuka(int c,bool nanazad){
    cout<<c<<" ";
    if (nanazad) {
        if (c=='a') {
            return;
        }
        azbuka(c-1,nanazad);

    }
    if (!nanazad) {
        if (c=='z') {
            return;
        }
        azbuka(c+1,nanazad);
    }

}

int main() {
    char c;
    bool nanazad;
    cin>>c>>nanazad;
    azbuka(c,nanazad);
}