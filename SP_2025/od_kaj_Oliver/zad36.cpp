#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int col = 0; col < m; col++) {
        int i = 0;
        int j = col;

        while (i < n && j >= 0) {
            cout << a[i][j] << " ";
            i++;
            j--;
        }
        cout << endl;
    }

    for (int row = 1; row < n; row++) {
        int i = row;
        int j = m - 1;

        while (i < n && j >= 0) {
            cout << a[i][j] << " ";
            i++;
            j--;
        }
        cout << endl;
    }

    return 0;
}