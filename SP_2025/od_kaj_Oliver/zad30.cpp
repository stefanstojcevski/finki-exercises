#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[100][100];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n/2;j++) {
            int zamena=a[i][j];
            a[i][j]=a[i][j+(n+1)/2];
            a[i][j+(n+1)/2]=zamena;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}