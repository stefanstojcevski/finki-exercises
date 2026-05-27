#include <iostream>
using namespace std;
int main() {
    int n,m,brojac;
    cin>>n;
    float procenti;
    int a[100];
    for(int i=0;i<n;i++) {
        cin>>m;
        procenti=0;
        brojac=0;
        for(int j=0;j<m;j++) {
            cin>>a[j];
        }
        for(int j=0;j<m/2;j++) {
            if (a[j]==a[m-1-j]) {
                brojac+=2;
            }
        }
        if (m%2!=0) {
            brojac++;
        }
        procenti=brojac/m*100;
        cout<<procenti<<"%"<<endl;
    }

}








/*
*#include<iostream>
using namespace std;


int main(){
    int n,m,brojac=0;
    cin>>n;
    int a[100];
    float procenti;
    for(int i=0;i<n;i++){
        cin>>m;
        procenti=0;
        brojac=0;
        for(int j=0;j<m;j++){
            cin>>a[j];
        }
        for(int j=0;j<m/2;j++){
        if(a[j]==a[m-1-j]){
            brojac+=2;
        }
    }
    if(m%2!=0){
        brojac++;
    }

    procenti=(float)brojac/m*100;
    cout<<procenti<<"%"<<endl;
    }
}
 *
 *
 **/