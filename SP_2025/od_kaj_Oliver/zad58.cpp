#include <iostream>
using namespace std;
int najmalbroj(int a[],int n,int min) {
    if (n==0) {
        return min;
    }
    if (min>a[n-1]) {
        min= a[n-1];
    }
    return najmalbroj(a,n-1,min);

}
int main() {
    int n;
    cin>>n;
    int a[n];

    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int min=a[0];
    cout<<najmalbroj(a,n,min);
}

