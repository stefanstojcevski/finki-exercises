/*
[0.1] [0.2] [0.3] [0.4]
[1.1] [1.2] [1.3] [1,4]
[2.1] [2.2] [2.3] ][2.4]
*/

#include <iostream>
using namespace std;
int main() {
    int n,m;
    int q;
    int MAX=-9999;
    cin>>n>>m;
    int a[n][m];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for (int j=0;j<m;j++) {
        int max=a[0][j];
        int min=a[0][j];
        for (int i=0;i<n;i++) {
            if (a[i][j]>max) {
                max=a[i][j];

            }
            if (a[i][j]<min) {
                min=a[i][j];
            }

        }
        int razlika=max-min;
        cout<<razlika<<endl;

        if (max>MAX) {
            MAX=max;
            q=j;
        }

    }
    cout<<MAX<<endl;
    cout<<q;


}