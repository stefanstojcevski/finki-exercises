#include <iostream>
#include <cstring>
using namespace std;
bool nePALINDROM(char a[]) {
    int n = strlen(a);
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) {
            return true;
        }
    }
    return false;
}


int main() {
    int n;
    char b[80];
    int min=1000000;
    cin>>n;
    char a[80];
    for (int i=0;i<n;i++) {
        cin>>a[80];
        if (nePALINDROM) {
            int n=strlen(a);
            if (n<min) {
                min=n;
                b[n]=a[n];
            }
        }

    }
    cout<<b[n]<<" ";


}