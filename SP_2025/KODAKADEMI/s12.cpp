#include <iostream>
using namespace std;

double BrojPozitivni(int a[], int n, int i) {
    if (i == n - 1) {
        return a[i];
    }
    return a[i] + 1.0 / BrojPozitivni(a, n, i + 1);
}

int main() {
    int n;
    cin >> n;

    int niza[100];
    for (int i = 0; i < n; i++) {
        cin >> niza[i];
    }

    double rezultat = BrojPozitivni(niza, n, 0);
    cout << rezultat;

    return 0;
}
