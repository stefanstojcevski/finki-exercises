#include <iostream>
using namespace std;
int main() {
    int m,n;
    int zbir1=0;
    int flag=0;
    int zbir2=0;
    cin>>m>>n;
    int a[100][100];
    for (int i=0 ; i<m ; i++ ) {
        for (int j=0 ; j<n ; j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0 ; i<m/2 ; i++ ) {
        for (int j=0 ; j<n ; j++) {
            zbir1+=a[i][j];
        }

    }
    for (int i=0 ; i<m/2 ; i++ ) {
        for (int j=0 ; j<n ; j++) {
            zbir2+=a[m-i-1][j];
        }

    }
    if (zbir2>zbir1) {
        flag=1;
    }

    if (flag==1) {
        for (int i=0 ; i<m ; i++ ) {
            for (int j=0 ; j<n ; j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
        else {
            for (int i=0 ; i<m/2 ; i++ ) {
                for (int j=0 ; j<n ; j++) {
                    int temp= a[i][j];
                    a[i][j]=a[m-i-1][j];
                    a[m-i-1][j]=temp;

                }
            }
            for (int i=0 ; i<m ; i++ ) {
                for (int j=0 ; j<n ; j++) {
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }


        }
    }







