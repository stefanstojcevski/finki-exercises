#include<iostream>
#include<cstring>
using namespace std;
void promena(char* a, char *b, char *c,int pozicija){
    int i,j=0, n=strlen(a),m=strlen(b);
    for(int i=0;i<pozicija;i++){
        *(c+j)=*(a+i);
        j++;
    }
    for(int i=0;i<m;i++){
        *(c+j)=*(b+i);
        j++;
    }

    for(int i=pozicija;i<n;i++){
        *(c+j)=*(a+i);
        j++;
    }
    *(c+j)='\0';
}
int main(){
    char a[1000];
    cin.getline(a,1000);
    char b[1000];
    cin.getline(b,1000);
    int pozicija;
    cin>>pozicija;
    char c[1000];
    promena(a,b, c,pozicija);
    cout<<c<<endl;
}