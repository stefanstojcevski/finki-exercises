#include<iostream>
using namespace std;
int brojac(int a) {
    if(a==0){
        return 0;
    }
    if ((a%10)%2==0) {
        return 1+brojac(a/10);
    }
    return brojac(a/10);
}



int main() {
        int a;
        cin>>a;
    cout<<brojac(a)<<endl;
    }