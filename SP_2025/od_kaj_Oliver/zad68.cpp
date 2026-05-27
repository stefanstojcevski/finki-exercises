#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[1000];
    cin.getline(a,1000);
    int n=strlen(a);//ja vrakja goleminata na tekstot
    bool palindrom=true;
    for(int i=0;i<n/2;i++){
        if(a[i]!=a[n-i-1]){
            palindrom=false;
            break;
        }
    }
    if(palindrom==true){
        cout<<"Palindrom!"<<endl;
    }
    else{
        cout<<"Ne e Palindrom!"<<endl;
    }

}