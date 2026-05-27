#include <iostream>
int sobirajne(int a,int b) {
    if (a==b) {
        return a;
    }
    if (a%2==0) {
        return a+sobirajne(a+1,b);
    }
    return  sobirajne(a+1,b);
}
using namespace std;
int main() {
    int broj1,broj2;
    cin>>broj1>>broj2;
    cout<<sobirajne(broj1,broj2);
}
