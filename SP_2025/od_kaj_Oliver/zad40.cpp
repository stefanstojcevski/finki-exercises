#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int matrix[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int magicSum = 0;
    for (int j = 0; j < n; j++) {
        magicSum += matrix[0][j];
    }

    bool isMagic = true;

    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != magicSum) {
            isMagic = false;
        }
    }


    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != magicSum) {
            isMagic = false;
        }
    }


    if (!isMagic) {
        cout << "false";
        return 0;
    }


    cout << "True" << endl;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                matrix[i][j] = magicSum;
            }
        }
    }

    // Печатење на новата матрица
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}