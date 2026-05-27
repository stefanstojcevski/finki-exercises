#include<iostream>
using namespace std;
int main() {
    int m,n;
    int zbir1=0;
    int zbir2=0;
    cin>>m>>n;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (i==j) {
                zbir1+=a[i][j];

            }
            if (n-1 == i+j) {
                zbir2+=a[i][j];
            }
        }
    }
    if (zbir1 > zbir2) {
        cout<<"G"<<endl;
    }
    if (zbir1 < zbir2) {
        cout<<"S"<<endl;
    }
    if (zbir1 == zbir2) {
        cout<<"="<<endl;
    }
}