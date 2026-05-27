#include<iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    int a,b,c,rez,min=9999,rez1=0;
    cin>>n;
    while (n>0) {
        cin>>a>>b>>c;
        if (a<b && a<c) {
            min=a;
        }
        else if (b<c && b<a) {
            min=b;
        }
        else if (c<a && c<b) {
            min=c;
        }
        rez=2*min-abs(min-a);
        if (rez>min) {
            cout<<rez+rez1<<endl;;
        }
        else {
            cout<<min<<endl;
        }

        rez1=rez;
        n--;
    }
}