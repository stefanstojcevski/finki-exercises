#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int m,n;
    int brojac=0;
    int brojac2=0;
    int a[120][120];
    cin>>n>>m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for (int j=0;j<m;j++) {
        brojac=0;
        brojac2=0;
        int q=j;
        while (q!=0) {
            brojac2++;
            q/=10;

        }
        if (j == 0) brojac2 = 1;

        for (int i=0;i<n;i++) {

            if (a[i][j]==(i*pow(10,brojac2))+j) {
                brojac++;
            }
        }
        cout<<brojac<<endl;

    }

}











