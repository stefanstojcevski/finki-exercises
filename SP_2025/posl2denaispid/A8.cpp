#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int m ,n;
    int zbir1=0;
    int sum=0;
    int zbir2=0;
    cin>>m>>n;
    int a[m][n];


    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin>>a[i][j];
        }
    }


    if (n%2!=0) {
        for (int i=0; i<m; i++) {
            int sreden=a[i][n/2];
            zbir1=0;
            zbir2=0;
            for (int j=0; j<n/2; j++) {
                zbir1+=a[i][j];
                zbir2+=a[i][n-j-1];
            }
            sum=abs(zbir1-zbir2);
            a[i][n/2]=sum;

        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    else {
        for (int i=0; i<m; i++) {
            int sreden=a[i][n/2];
            zbir1=0;
            zbir2=0;
            for (int j=0; j<n/2; j++) {
                zbir1+=a[i][j];
                zbir2+=a[i][n-j-1];
            }
            sum=abs(zbir1-zbir2);
            int sum1=sum;
            a[i][n/2]=sum;
            a[i][n/2-1]=sum1;

        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }



}