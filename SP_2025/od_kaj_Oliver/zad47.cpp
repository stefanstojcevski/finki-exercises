#include<iostream>
using namespace std;
int zbir(int a){
    if(a==0){
        return 0;
    }
    if ((a%10)%2!=0) {
        return a%10+zbir(a/10);
    }
    return zbir(a/10);
}


int main(){
    int a;
    cin>>a;
    cout<<zbir(a);

}