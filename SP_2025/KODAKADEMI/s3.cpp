
/*
[0.1] [0.2] [0.3] [0.4]
[1.1] [1.2] [1.3] [1,4]
[2.1] [2.2] [2.3] ][2.4]
*/


#include <iostream>
using namespace std;
int main() {
    int m,n;
    int brojac1=0;
    int brojac2=0;
    cin>>m>>n;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        bool flag=false;
        for (int j=0;j<n-2;j++) {
            if (a[i][j]==1 && a[i][j+1]==1 && a[i][j+2]==1) {
                flag=true;
            }
        }
        if (flag) {
            brojac1++;
        }
    }
    for (int i=0;i<n;i++) {
        bool flag=false;
        for (int j=0;j<m-2;j++) {
            cout<<a[j][i];
            cout<<a[j+1][i];
            cout<<a[j+2][i]<<endl;
            if (a[j][i]==1 && a[j+1][i]==1 && a[j+2][i]==1) {
                flag=true;
            }
        }
        if (flag) {
            brojac2++;
        }
    }


    cout<<brojac1+brojac2<<endl;

    }



