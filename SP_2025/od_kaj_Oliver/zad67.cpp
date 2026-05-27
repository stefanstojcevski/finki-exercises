#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[1000];
    cin.getline(a,1000);
    int n=strlen(a);//ja vrakja goleminata na tekstot
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }

}