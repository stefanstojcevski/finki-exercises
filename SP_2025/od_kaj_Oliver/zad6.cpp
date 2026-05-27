#include <iostream>
using namespace std;
void sredena(int a[],int n) {
    for (int i=0;i<n;i++) {
        if (a[i]%2==0) {
            a[i]+=1;
        }
        else  {
            a[i]-=1;
        }

    }


}
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sredena(a,n);
    for (int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}