#include<iostream>
using namespace std;
int brojac(int a,int b){
    if(a==b){
        return 0;
    }

    if(a%2!=0){
        return 1+brojac(a+1,b);
    }
    return brojac(a+1,b);
}


int main(){
    int a,b;
    cin>>a>>b;
    cout<<brojac(a,b)<<endl;
}