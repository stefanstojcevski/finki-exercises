/*   i j    i j    i j
 *  [1,1]  [1,2]  [1,3]
 *  [2,1]  [2,2]  [2,3]
 *  [3,1]  [3,2]  [3,3]
 *
 *
 **/


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ii, jj;
    cin >> ii >> jj;
    int k1 = 0;
    int k2 = 0;
    int k3 = 0;
    int k4 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < ii) {
                if (j < jj) {
                    k2 += a[i][j];
                } else {
                    k1 += a[i][j];
                }
            }
            else {
                if (j < jj) {
                    k3 += a[i][j];
                } else {
                    k4 += a[i][j];
                }
            }
        }
    }
    cout<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<endl;
}
