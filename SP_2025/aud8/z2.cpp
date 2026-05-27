#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    int zbir1=0;
    int zbir2=0;
    int brojac1=0;
    float odnos;
    int brojac2=0;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        if (a[i]%2 == 0) {
            zbir1+=a[i];
            brojac1++;


        }
        else {
            brojac2++;
            zbir2+=a[i];
        }

    }
    if (brojac2==0) {
        cout<<"NEMOZAT DA SE PRESMETAT ODNOS"<<endl;
        cout <<"PARNI "<< zbir1 << endl;
        cout <<"NEPARNI "<< zbir2 << endl;
    }
    else {
        odnos=float (brojac1)/float (brojac2);

        cout <<"PARNI "<< zbir1 << endl;
        cout <<"NEPARNI "<< zbir2 << endl;
        cout<<odnos<<endl;
    }

    return 0;

}