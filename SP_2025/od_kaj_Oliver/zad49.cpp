#include <iostream>
using namespace std;
int brojach(int a,int b) {
    if (a==0) {
        return 0;
    }
    if (a%10==b) {
        return 1+brojach(a/10,b);
    }
    return brojach(a/10,b);
}
int main() {
    int a,b;
    cin>>a>>b;
    cout<<brojach(a,b);
}