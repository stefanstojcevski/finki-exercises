#include <iostream>
using namespace std;
int najgolemaNAjznacajna(int broj) {
    int najznacajna;
    while (broj!=0) {
        najznacajna=broj%10;
        broj/=10;
    }
    return najznacajna;

}
int main() {
    int n;
    int a[1000],max=0,m;

    while (true) {
        cin>>n;
        if (n==0) {
            break;
        }
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
        max=0;
        for (int i=0;i<n;i++) {
           int broj=najgolemaNAjznacajna(a[i]);
            if (broj>max) {
                max=broj;
                m=a[i];
            }
        }
        cout<<m<<endl;
    }
}