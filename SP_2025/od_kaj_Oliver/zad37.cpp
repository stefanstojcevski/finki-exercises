#include <iostream>
using namespace std;
int main() {
    int m,n;
    int maxzbir=0;
    int maxkolona=0;
    cin>>m>>n;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for (int j=0;j<n;j++) {
        int zbir=0;
        for (int i=0;i<m;i++){
            zbir+=a[i][j];
        }
        if (zbir>maxzbir) {
            maxzbir=zbir;
            maxkolona=j;
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++){
            a[i][maxkolona]=maxzbir;
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}