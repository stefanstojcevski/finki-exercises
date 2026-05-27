#include <iostream>
using namespace std;
void REKURZIJA(int a[],int n,int *max) {
    if (n==0) {
        return;

    }

    if (a[n-1]>*max) {
        *max=a[n-1];
    }
    cout<<a[n-1]<<" ";

    REKURZIJA(a,n-1,max);


}
int main () {
    int n;
    int brojac=0;
    cin>>n;
    int a[n];
    int max=-999999;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        if (a[i]==-1) {
            break;
        }
            brojac++;
    }
    if (brojac>0) {
            REKURZIJA(a,brojac,&max);
            cout<<endl;
            cout<<brojac-1<<endl;;
            cout<<0<<endl;
            cout<<max;
        }
    else {
        cout<<"None"<<endl;
    }

    }


