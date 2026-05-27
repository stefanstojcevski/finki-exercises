#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n][n];
    if (n%2 != 0) {
        cout<<"ERROR"<<endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];

            }
        }
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                a[i][j] = a[i][j]
                     + a[i][n-1-j]
                     + a[n-1-i][j]
                     + a[n-1-i][n-1-j];

            }
        }
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}