#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int pocetok=0;
    int zbir=0;
    int kraj=0;
    int max=0;
    for(int i=0;i<n;i++) {
        if(zbir<0) {
            zbir=a[i];
            pocetok=i;
        }
        else {
            zbir=zbir+a[i];


        }
        if (zbir>max) {
            max=zbir;
            kraj=i;

        }
    }
    cout<<"Maximum Sum:"<<max<<endl;
    cout<<"procent na elementi:"<<(float)(kraj-pocetok+1)/n*100<<"%"<<endl;
}


