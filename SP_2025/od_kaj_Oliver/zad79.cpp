#include<iostream>
using namespace std;
int main() {
    int m,n,x;
    int zbir=0;
    cin>>x;
    cin>>m>>n;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }

    for (int i=0;i<m;i++) {
        zbir=0;
        for (int j=0;j<n;j++) {
            zbir+=a[i][j];
        }
        for (int j=0;j<n;j++) {
            if (zbir>x) {
                a[i][j]=1;
            }
            else if (zbir<x) {
                a[i][j]=-1;
            }
            else if (zbir==x) {
                a[i][j]=0;
            }
        }
    }

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }



}