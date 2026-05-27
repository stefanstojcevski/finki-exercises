#include <iostream>
using namespace std;
int main() {
    int m,n;
    int max1;
    int q=0;
    int max2=-10000;
    int min;
    int razlika;
    cin>>m>>n;
    int a[100][100];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        max1=-100000;
        min=100000;
        for (int j=0;j<n;j++) {
            if (a[i][j]>max1) {
                max1=a[i][j];
            }
            if (a[i][j]<min) {
                min=a[i][j];
            }
        }
        razlika=max1-min;
        cout<<razlika<<endl;;
        if (razlika>max2) {
            max2=razlika;
            q=i;
        }

    }
    cout<<q;
}