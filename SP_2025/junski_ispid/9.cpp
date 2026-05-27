/*   i  j    i  j    i  j
 *  [0][0]  [0][1]  [0][2]
 *  [1][0]  [1][1]  [1][2]
 *  [2][0]  [2][1]  [2][2]
 *
 **/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    bool magicen=false;
    int standart=0;
    int standart2=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        standart+=a[0][j];
    }

    for (int i = 0; i < n; i++) {
        standart2+=a[i][0];
    }

    for (int i = 0; i < n; i++) {

        int zbir = 0;
        for (int j = 0; j < n; j++) {
            zbir += a[i][j];
        }
        if (standart!=zbir) {
            return 0;
        }
    }

    for (int j = 0; j < n; j++) {

        int zbir2=0;
        for (int i = 0; i < n; i++) {
            zbir2 += a[i][j];
        }
        if (standart2!=zbir2) {
            return 0;
        }
    }

    if (standart==standart2) {
        magicen=true;
    }

    if (magicen) {
        cout<<"True"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i==j || i+j==n-1) {
                    a[i][j]=standart;
                }
            }
            cout << endl;
        }




        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }









}
