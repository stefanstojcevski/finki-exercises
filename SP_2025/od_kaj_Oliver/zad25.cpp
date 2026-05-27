#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    int m,n;
    cin>>m>>n;
    double a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int j=0;j<n;j++) {
        double max=a[0][j];
        double min=a[0][j];
        for (int i=0;i<m;i++) {
            if (a[i][j]>max) {
                max=a[i][j];

        }
            if (a[i][j]<min) {
                min=a[i][j];
            }
            }
            for (int i=0;i<m;i++) {
                a[i][j]=(a[i][j]-min)/(max-min);
            }
        }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cout<<fixed<<setprecision(2)<<a[i][j]<<" ";

        }
        cout<<endl;
    }
    return 0;

    }
