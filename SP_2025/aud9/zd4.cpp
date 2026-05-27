#include <iostream>
using namespace std;


int main() {
    int a[100][100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int brojach=0;
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (a[i][j] == 1) {
                if (a[i-1][j-1] == 1 && a[i-1][j+1]==1 && a[i+1][j-1]==1 && a[i+1][j+1]==1) {
                    brojach++;
                    a[i][j] = 0;
                    a[i-1][j-1] = 0;;
                    a[i-1][j+1] = 0;
                    a[i+1][j-1] = 0;
                    a[i+1][j+1] = 0;
                    }
            }
        }

    }
    cout<<brojach;
    return 0;
}