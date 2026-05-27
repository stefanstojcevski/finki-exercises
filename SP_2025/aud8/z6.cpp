#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int m;
    cin>>m;
    m=m%n;
    int b[n];
    for (int i=0;i<n;i++) {
        b[(i+m)%n]=a[i];


    }
    for (int i=0;i<n;i++) {
        cout<<b[i]<<" ";
    }
    return 0;
}