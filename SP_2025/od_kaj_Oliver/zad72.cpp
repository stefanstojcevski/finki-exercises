#include <iostream>
#include<cstring>
using namespace std;
int main() {
    char a[1000];
    bool palindrom=true;
    cin.getline(a,1000);
    int n=strlen(a);
    for (int i=0;i<n/2;i++) {
        if (tolower(a[i])!=tolower(a[n-i-1])) {
            palindrom=false;

        }
    }
    if (!palindrom) {
        cout<<"ne e palindrom"<<endl;
    }
    else {
        cout<<"palindrom"<<endl;

    }
}