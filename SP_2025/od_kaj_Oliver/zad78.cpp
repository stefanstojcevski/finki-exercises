#include<iostream>
using namespace std;
int main() {
    int m,n,pozicijaX,pozicijaY;
    cin>>n>>m;

    int a[n][m];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    cin>>pozicijaX>>pozicijaY;
    int k1=0,k2=0,k3=0,k4=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if(i<pozicijaX){

                if(j<pozicijaY) k2+=a[i][j];

                else k1+=a[i][j];

            }else{

                if(j<pozicijaY) k3+=a[i][j];

                else k4+=a[i][j];

            }
        }
    }
    cout<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<endl;


}