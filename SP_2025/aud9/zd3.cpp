#include <iostream>
using namespace std;
int main() {
    int n;
    bool flag=true;
    cin>>n;
    int a[n][n];
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (a[i][j] != a[j][i]) {
                flag = false;
                break;
            }
        }

        }
        if (flag==true) {
            cout<<"SIMETRICNA"<<endl;
        }
        else {
            cout<<"NESIMETRICNA"<<endl;
        }

    return 0;
}