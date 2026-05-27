#include <iostream>
using namespace std;
bool REKURZIJA(int b) {
    if (b==0) {
        return true;
    }
    int cifra=b%10;
    if (cifra%2!=0) {
        return false;
    }
    return REKURZIJA(b/10);
}
int main() {
    int n;
    int w=0;
    int a[100];
    int t[100];
    int b;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>b;
        a[i]=b;
        if (REKURZIJA(b)==true) {
            t[w]=a[i];
            w++;
        }
    }
    for (int i=w-1;i>=0;i--) {
        cout<<t[i]<<" ";
    }
}