#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    int n, m;
    int q;
    int MAX=-9999;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int max = a[i][0];
        int min = a[i][0];
        for (int j=0;j<m;j++) {
            if (a[i][j]>max) {
                max=a[i][j];
            }
            if (a[i][j]<min) {
                min=a[i][j];
            }
        }
        int razlika=max-min;
        cout<<razlika<<endl;
        if (max>MAX) {
            MAX=max;
            q=i;

        }

    }
    cout<<MAX;
}
