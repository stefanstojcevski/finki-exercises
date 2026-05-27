/*
*Да се напише функција:
void zamena (char* niza, char znak1, char znak2)
Функцијата треба во низата секоја појава на знакот znak1 да го замени со знакот znak2.
Пример: niza: ova e primer za niza, znak1: a, znak: A
Излез: ovA e primer zA nizA.
 *
 **/

#include <iostream>
#include <cstring>
using namespace std;
void zamena (char *a, char znak1, char znak2) {
    int n=strlen(a);
    for (int i = 0;i < n; i++) {
        if (*(a+i)==znak1) {
            *(a+i)=znak2;
        }

    }
}
int main() {
    char a[1000];

    cin.getline(a,1000);
    char znak1;
    char znak2;
    cin>>znak1>>znak2;

    zamena (a, znak1, znak2);
    cout<<a<<endl;;
}
