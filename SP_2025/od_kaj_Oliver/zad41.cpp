#include<iostream>
using namespace std;
int zbir(int n) {
    if (n==0) {
        return 0;
    }
    return (n%10)+zbir(n/10);
}

int main(){
    int broj;
    cin>>broj;
    cout<<zbir(broj)<<  endl;


}