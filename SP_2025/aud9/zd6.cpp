#include<iostream>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int brojac=0;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<m-1;i++) {
        for (int j=0;j<n-1;j++) {
            if (a[i][j]==1) {
                if (a[i-1][j]==1 && a[i][j-1]==1 && a[i+1][j]==1 && a[i][j+1]==1) {
                    brojac++;
                    a[i][j]=0;
                    a[i-1][j]=0;
                    a[i][j-1]=0;
                    a[i+1][j]=0;
                    a[i][j+1]=0;

                }
            }
        }
    }
    cout<<brojac;
    return 0;
}