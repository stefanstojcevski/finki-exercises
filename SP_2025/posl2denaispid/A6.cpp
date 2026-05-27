#include <iostream>
using namespace std;
int REKURZIJA(int n) {
    if (n==0) {
        return 0;
    }
    int cifra=n%10;
    return REKURZIJA(n/100)*10+cifra;
}
int main() {
    int n;
    cin>>n;
    cout<<REKURZIJA(n/10);
}