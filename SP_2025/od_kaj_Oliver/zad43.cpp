#include <iostream>
using namespace std;
int zbir(int n) {
    if (n==0) {
        return 0;
    }
    return n+zbir(n-1);



}
int main() {
    int broj;
    cin>>broj;
    cout<<zbir(broj)<<endl;

}
