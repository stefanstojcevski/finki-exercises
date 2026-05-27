#include <iostream>
using namespace std;
int main() {
    int n;
    int proizvod=0;
    cin>>n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>b[i];
    }
    for (int i = 0; i < n; i++) {
        proizvod += a[i] * b[i];

    }
    cout << proizvod;
    return 0;

}