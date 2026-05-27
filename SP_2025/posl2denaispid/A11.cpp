#include <iostream>
using namespace std;
void REKURZIJA(int i,int k) {
    if (k==i+1) {
        return;
    }
    cout<<k;
    REKURZIJA(i,k+1);
    if (k != i) cout<<k;
}
int main() {
    int n;
    int k=1;
    cin>>n;
    for (int i=n; i>=1;i--) {
        REKURZIJA(i,1);
        cout<<endl;
    }
}
