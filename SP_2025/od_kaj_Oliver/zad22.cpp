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
    for (int i=0;i<m;i++) {
        int max=a[0][0];
        int min=a[1][1];
        for (int j=0;j<m;j++) {
            if (max<a[i][j]) {
                max=a[i][j];
            }
            if (min>a[i][j]) {
                min=a[i][j];

            }

        }
        cout<<"max:"<<max<<" "<<"min:"<<min<<endl;
    }
    return 0;
}