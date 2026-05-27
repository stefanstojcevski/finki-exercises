#include <iostream>
using namespace std;
int MinBr(int a[],int n) {
    int min = a[0];
    int pozicijaM=0;
    for(int i=0;i<n;i++) {
        if(min>a[i]) {
            min = a[i];
            pozicijaM=i;
        }

    }
    return pozicijaM;
}
int MaxBr(int a[],int n) {
    int max = a[0];
    int pozicijaMx=0;
    for(int i=0;i<n;i++) {
        if(max<a[i]) {
            max = a[i];
            pozicijaMx=i;
        }

    }
    return pozicijaMx;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int PozMin=MinBr(a,n);
    int PozMax=MaxBr(a,n);
    int zam=a[PozMin];
    a[PozMin]=a[PozMax];
    a[PozMax]=zam;
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
