#include <iostream>
using namespace std;

int cikCak(int broj,bool ePogolemODPRviot) {
    if (broj<10)
        return 1;
    int cifra1=broj%10;
    broj=broj/10;
    int cifra2=broj%10;
    if ( (ePogolemODPRviot && cifra1<=cifra2) || ( !ePogolemODPRviot && cifra1>=cifra2) ){
        return 0;
    }
    return cikCak(broj,!ePogolemODPRviot);
}

int main() {
    int broj;
    cin >> broj;
    if(cikCak(broj,false)){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}