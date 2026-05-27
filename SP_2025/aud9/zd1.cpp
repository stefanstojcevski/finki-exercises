#include <iostream>
using namespace std;
int main() {
    int m,n;
    cin >> m>>n;
    int a[m][n];
    int zbirKol=0;
    int zbirRed=0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j%2!=0) {
                zbirKol+=a[i][j];
            }
            if (i%2==0) {
                zbirRed+=a[i][j];

            }
        }
    }
    int razlika=zbirKol-zbirRed;
    cout << razlika << endl;

}
