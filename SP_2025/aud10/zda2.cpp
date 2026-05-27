#include <iostream>
using namespace std;
void brojac (int n) {
    if (n==0) {
        cout<<"0"<<"!";
       return;
    }
    cout<<n<<" ";
    brojac(n-1);
}
int main() {
    int n;
    cin>>n;
    brojac(n-1);
}