#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char z1,z2;
    cin>>z1>>z2;
    cin.ignore();
    char a[100];
    while (cin.getline(a,100)) {
        if (a[0]=='#') {
            break;
        }
        int q=0;
        int w=0;
        for (int i=0;i<strlen(a);i++) {
            if (a[i]==z1) {
                q=i;
            }
            if (a[i]==z2) {
                w=i;
            }
        }
        for (int j=q+1;j<w;j++) {
            cout<<a[j];

        }
        cout<<endl;


    }
}