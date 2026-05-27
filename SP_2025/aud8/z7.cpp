#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int brojNN=0;
    int b[n];
    for (int i=0;i<n;i++) {
        bool duplikat=false;
        for (int j = 0; j < brojNN; j++) {
            if (a[i] == b[j]) {
                duplikat = true;
                break;
            }
        }
        if (!duplikat) {
            b[brojNN] = a[i];
            brojNN++;

        }
    }
    for (int i=0;i<brojNN;i++) {
        cout<<b[i]<<" ";
    }
    return 0;
}