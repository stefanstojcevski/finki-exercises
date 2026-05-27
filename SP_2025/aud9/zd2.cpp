#include <iostream>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    int max=a[0][0];
    int min=a[0][0];
;
for ( int i=0; i < m ;i++) {
    for (int j = 0 ; j< n ; j++) {
        cin>>a[i][j];
    }
}
    for (int i=0; i < m ; i++) {
        for (int j=0 ; j < n ; j++) {
            if (max<a[i][j]) {
                max=a[i][j];
            }
            if (min>a[i][j]) {
                min=a[i][j];
            }

        }
    }
    int razlika=max-min;
    for (int i=0; i < m ; i++) {
        for (int j=0 ; j < n ; j++) {
            if (i==j) {
                a[i][j]=razlika;
            }
        }
    }
        for (int i=0; i < m ; i++) {
            for (int j=0 ; j < n ; j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }




}