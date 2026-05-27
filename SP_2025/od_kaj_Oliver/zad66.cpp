#include<iostream>
using namespace std;
int main() {
    int brojac=0;
    char a[1000];
    cin.getline(a,1000);
    for (int i=0;a[i]!='\0';i++) {
        if (a[i]== 'a' || a[i]=='A' ||a[i]== 'e' || a[i]=='E' ||a[i]== 'O' || a[i]=='o' || a[i]=='I' || a[i]=='i' ||a[i]=='U'||a[i]=='u')
        brojac++;
    }
    cout<<brojac;

}

