#include <iostream>
using namespace std;
int REKURZIJA(int n) {
    if (n==0) {
        return 0;
    }
    return n%10+REKURZIJA(n/100);
}
int main() {
    int n;
    cin>>n;
    cout<<REKURZIJA(n/10);
}