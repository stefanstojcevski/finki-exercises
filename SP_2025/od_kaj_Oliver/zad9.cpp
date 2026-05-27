#include <iostream>
using namespace std;
void zamena(int n,int a[],int k) {
    int zam=a[k-1];
    a[k-1]=a[k-2];
    a[k-2]=zam;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int k;
    cin>>k;
    zamena(n,a,k);
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
}





