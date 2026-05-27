#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n,zbir=0;
    cin>>n;
    int a[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){

        int temp=a[i][i];
        a[i][i]=a[i][n-1-i];
        a[i][n-1-i]=temp;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}