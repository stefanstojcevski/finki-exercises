#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    double zbir=0;
    double brojac=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        zbir+=a[i];
        brojac++;

    }
    int min1=9999;
    int min2=9999;
    for (int i=0;i<n;i++) {
        if (a[i]<min1) {
            min2=min1;
            min1=a[i];

        }
        else if (a[i]<min2 && min1!=min2) {
            min2=a[i];
        }
    }
    int razlika=min2-min1;

    double arigmeticka=zbir/brojac;
    cout<<razlika<<endl;
    cout<<arigmeticka<<endl;
    cout<<min2<<endl;

}