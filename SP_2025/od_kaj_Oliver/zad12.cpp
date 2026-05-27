#include <iostream>
using namespace std;
int main() {
    int n,k;
    cin>>n;
    int a[100];
    int b[100],j=0;
    int c[100],q=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cin>>k;
    for(int i=0;i<n;i++) {
        if (a[i]<k) {
            b[j]=a[i];
            j++;
        }
        else {
            c[q]=a[i];
            q++;
        }
    }
    for(int i=0;i<j;i++) {
        cout<<b[i]<<" ";
    }
    for(int i=0;i<q;i++) {
        cout<<c[i]<<" ";
    }

}

