#include <iostream>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if (i % 2 == 0) {
                for (int k = 1; k < n; k+=2) {
                    a[i][k] = 0;
                }
            }
            else {
                for (int k = 0; k < n; k+=2) {
                    a[i][k] = 0;
                }
            }
        }
    }

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}