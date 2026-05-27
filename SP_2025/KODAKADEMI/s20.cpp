/*
[0.1] [0.2] [0.3] [0.4]
[1.1] [1.2] [1.3] [1,4]
[2.1] [2.2] [2.3] ][2.4]
*/

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int a[m][n];
    int brojac = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < n; j++) {
        bool ok = true;
        for (int i = 0; i < m - 2; i++) {
            if (!((a[i][j] > a[i + 1][j]) && (a[i + 1][j] < a[i + 2][j]) || (a[i][j] < a[i + 1][j]) && (
                      a[i + 1][j] > a[i + 2][j]))) {
                ok = false;
                break;
            }
        }
        if (ok) {
            brojac++;
        }
    }
    cout << brojac;
}
