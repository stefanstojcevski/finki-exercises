#include<iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    int col;
    bool najde=false;
    cin>>n;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        int min=INT_MAX;
        int max=INT_MIN;
        for (int j=0;j<n;j++) {
            if (a[i][j]<min) {
                min=a[i][j];
                col=j;
            }
        }
        for (int k=0;k<n;k++) {
            if (a[k][col]>max) {
                max=a[k][col];
            }
        }
        if (min==max) {
            najde=true;
            cout<<min<<" ";
        }
    }
    if (!najde) {
        cout<<"nema takva tocka";
    }









}