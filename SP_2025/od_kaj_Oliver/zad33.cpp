#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100][100];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bool realen= true;


    for (int i = 0; i < n; i++) {
        int zbir = 0;


        for (int j = i + 1; j < n; j++) {
            zbir += a[i][j];
        }


        if (a[i][i] != zbir) {
            realen = false;
            break;
        }
    }


    if (realen) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
