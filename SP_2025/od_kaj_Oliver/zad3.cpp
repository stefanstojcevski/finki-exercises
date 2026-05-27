#include <iostream>
using namespace std;
int main() {
    int n;
    int zbir=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if (a[i]%2!=0) {
            zbir+=a[i];

        }
    }
    cout<<zbir;
    return 0;
}