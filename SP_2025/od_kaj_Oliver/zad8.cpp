#include <iostream>
using namespace std;
int main() {
    int n,m,k;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++) {
        cin>>m;
        for(int j=0;j<m;j++) {
            cin>>a[j];
        }
        cin>>k;
        for (int j=k;j<=m;j+=k) {
            int zam=a[j-1];
            a[j-1]=a[j-2];
            a[j-2]=zam;
        }
        for (int j=0;j<m;j++) {
            cout<<a[j]<<" ";
        }
    }
}