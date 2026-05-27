/*
 *Da se najde vtoriot najgolem element na nizata (samo so edno izminuvanje na nizata)
 * i aritmetichkata sredina na nizata
 **/
#include <iostream>
using namespace std;
int main() {
    int n;
    int arigmeticka;
    int zbir=0;
    cin>>n;
    int a[n];


    for (int i=0; i < n; i ++) {
        cin >> a[i];
        zbir+=a[i];
    }


    int max1=a[0];
    int max2=a[0];


    for (int i=0; i < n; i ++) {
        if (a[i]>max1) {
            max2=max1;
            max1=a[i];
        }
        else if (a[i]>max2 && a[i]!=max1) {
            max2=a[i];
        }
    }


    arigmeticka=zbir/n;
    cout<<"ARIGMETICKA: "<<arigmeticka<<endl;
    cout<<"NAJGOLEM: "<<max1<<" "<<"VTORNAJGOLEM:"<<max2;


}