#include <iostream>
#include <climits>
using namespace std;
int REKURZIJA(int n) {
    if (n==0) {
        return 0;
    }
    int cifra=n%10;
    if (cifra==9) {
        cifra=7;
    }
    return  REKURZIJA(n/10)*10+cifra;
}
int main() {
    int n;
    int a;
    int br=0;
    int br2=0;
    int b[5];
    int min=INT_MAX;
    while (cin>>n) {
           a= REKURZIJA( n);
        if (a<min) {
            min=a;
            br2=br;
        }
        b[br]=a;
        br++;
    }
    cout<<b[br2]<<" ";
}