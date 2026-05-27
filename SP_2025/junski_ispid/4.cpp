#include <iostream>
#include <iomanip>
using namespace std;




int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }

    for (int i=0;i<m;i++) {
        int zbir=0;
        for (int j=0;j<n;j++) {
            zbir+=a[i][j];
        }
        cout<<zbir<<endl;

    }
}
