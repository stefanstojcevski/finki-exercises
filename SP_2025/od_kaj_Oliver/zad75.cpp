/*
 *2. Se vnesuva N i N recenici. Da se napravi funkcija koja ke ja transformira nizata taka sto ke nema soglaski i brojki.
 *Samoglaskite ostanuvaat bez razlika dali se golemi bukvi ili mali bukvi.
 **/

#include<iostream>
using namespace std;

bool eSamoglaska(char a) {
    a=tolower(a);
    if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u' ) {
        return true;
    }
    return false;
}

char transformacija(char recenica[]) {
    int j = 0;
    for (int i = 0; recenica[i] != '\0'; i++) {
        if (eSamoglaska(recenica[i]) || recenica[i] == ' ') {
            recenica[j] = recenica[i];
            j++;

        }
    }
    recenica[j]='\0';
}

int main() {
    int n;
    cin>>n;
    cin.ignore();
    char recenica[1000];
    for (int i=0;i<n;i++) {
        cin.getline(recenica,1000);
        transformacija(recenica);
        cout << recenica << endl;
    }
}
