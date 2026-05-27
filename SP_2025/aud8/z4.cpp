#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
   bool raste=true;
    bool opagjacka=true;
    for (int i = 0; i < n-1; i++) {
        if (a[i]>=a[i+1]) {
            raste=false;
        }
        if (a[i]<=a[i+1]) {
            opagjacka=false;
        }
    }
    if (raste==true) {
        cout<<"STROGO RASTECKA"<<endl;
    }
    else if (opagjacka==true) {
        cout<<"STROGO OPAGJACKA"<<endl;
    }
    else {
        cout<<"NITU RASTECKA NITU OPAGJACKA"<<endl;
    }
    return 0;
}