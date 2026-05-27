#include <iostream>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m/2;i++) {
        for(int j=0;j<n;j++) {
            int zamena=a[i][j];
            a[i][j]=a[i+(m+1)/2][j];
            a[i+(m+1)/2][j]=zamena;

        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}

/*
*#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    int m,n,brojac=0;
    cin>>m>>n;
    int a[10][10];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        cin>>a[i][j];
        }
    }

    for(int i=0;i<m/2;i++){
        for(int j=0;j<n;j++){
        int temp=a[i][j];
        a[i][j]=a[i+(m+1)/2][j];
        a[i+(m+1)/2][j]=temp;
        }
    }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
    }
    cout<<endl;
}

}
 *
 *
 **/