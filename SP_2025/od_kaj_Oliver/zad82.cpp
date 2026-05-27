#include<iostream>
using namespace std;
int main() {
    int m,n;
    int gorna=0,dolna=0,leva=0,desna=0;
    cin>>m>>n;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }


        for (int j=0;j<n;j++) {
            gorna+=a[0][j];
        }
    for (int j=0;j<n;j++) {
        dolna+=a[m-1][j];
    }
    for (int i=0;i<m;i++) {
        leva+=a[i][0];
    }
    for (int i=0;i<m;i++) {
        desna+=a[i][n-1];
    }
    int zbir=0;
    zbir=gorna+dolna+leva+desna;
    zbir=zbir-a[0][0]-a[m-1][0]-a[m-1][n-1]-a[0][n-1];
    int poslzbir=0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            poslzbir+=a[i][j];
        }
    }
    poslzbir=poslzbir-zbir;
    if (zbir>poslzbir) {
        cout<<"G"<<endl;
    }
    if (zbir<poslzbir) {
        cout<<"V"<<endl;
    }
    if (zbir==poslzbir) {
        cout<<"="<<endl;
    }






}
