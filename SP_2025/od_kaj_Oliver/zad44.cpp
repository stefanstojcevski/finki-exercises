#include<iostream>
using namespace std;
int zbir(int a,int b){
    if(a==b){
        return a;
    }
    return a+zbir(a+1,b);

}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<zbir(a,b)<<endl;
}