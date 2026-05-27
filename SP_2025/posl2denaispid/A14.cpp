#include <iostream>
#include<cstring>
using namespace std;
int eSamoglaska(char bukva) {
    if (tolower(bukva)=='a' || tolower(bukva)=='e'  || tolower(bukva)=='i' || tolower(bukva)=='o' || tolower(bukva)=='u') {
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    char a[1000];
    int brojac=0;
    while (cin.getline(a,1000) && a[0]!='#') {
        for (int i=0; a[i]!='\0';i++){
            if (eSamoglaska(a[i]) && eSamoglaska(a[i-1])) {
                cout<<(char)tolower(a[i-1])<<(char)tolower(a[i])<<endl;
            brojac++;
            }
        }
    }
    cout<<brojac<<endl;
}