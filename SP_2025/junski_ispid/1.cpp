#include <iostream>
using namespace std;
int sum_pos(int broj[],int ind,int n) {
    int zbir=0;
    if (ind>n) {
        zbir=0;
        return zbir;

    }
    for (int i=ind;i<n;i++) {
        zbir+=broj[i];
    }
    return zbir;


}
int main() {
    int n;
    int ind;
    cin>>n;
    int broj[n];
    for (int i=0;i<n;i++) {
        cin>>broj[i];
    }
    cin>>ind;
    int kraj=sum_pos(broj,ind,n);
    cout<<kraj;
}