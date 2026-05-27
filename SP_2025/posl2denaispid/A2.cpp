#include<iostream>
#include<cstring>
using namespace std;
int Faktoriel(char broj){
    if(broj==1){
        return 1;
    }
    return broj*Faktoriel(broj-1);
}

int brojKombinacii(int a[],int n){
    int b[10]={0};
    for(int i=0;i<n;i++){
        b[a[i]];
    }
    int f=Faktoriel(n);
    for(int i=0;i<10;i){
        if(b[i]>1){
            f=f/Faktoriel(b[i]);
        }
    }
    return f;
}



int main(){
    int n;
    cin>>n;
    int a[8];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<brojKombinacii(a,n)<<endl;
}