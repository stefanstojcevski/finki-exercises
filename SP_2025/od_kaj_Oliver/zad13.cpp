/*
Koriniskot vnesuva niza da se otstranata site prosti proevi od nizata
(bez koristenje na pomosna niza)

*/
#include<iostream>
using namespace std;

int prostElement(int broj){
    int brojac=0;
    for(int i=1;i<=broj;i++){
        if(broj%i==0){
            brojac++;
        }
    }
    if(brojac<=2){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        if(prostElement(a[i])){
            for(int j=i;j<n-1;j++){
                a[j]=a[j+1];
            }
            n--;
            //i--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}