/*
Da se najde brojot na zborovi vo edna recenica?
Zdravo jas sum Oliver
izlez:
4
*/
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[1000];
    cin.getline(a,1000);
    int brojac=0;
    for(int i=0;a[i]!='\0';i++){
        if((i==0 && a[i]!=' ') || (a[i]!=' ' && a[i-1]==' ')){
            brojac++;
        }
    }

    cout<<"Brojot na zborovi vo recenicata e: "<<brojac<<endl;


}