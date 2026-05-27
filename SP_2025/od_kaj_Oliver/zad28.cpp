#include<iostream>
#include<iomanip>

using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    int brojac=0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            brojac=0;
            for(int k=0;k<m;k++) {
                for(int l=0;l<n;l++) {
                    if (a[i][j]==a[k][l]) {
                        brojac++;
                    }
                }
            }
            if(brojac>1) {
                cout<<"  ";
            }
            else {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}