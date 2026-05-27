#include <iostream>
#include<cstring>
using namespace std;
int NAJZNACAEN(int broj) {
    int najznacajna;
    while (broj!=0) {
        najznacajna=broj%10;
        broj/=10;
    }
    return najznacajna;
}
int main() {
    int n;
    int max=0;
    int m;
    int a[1000];
    while (true) {
        cin>>n;
        if (n==0) {
            break;
        }

        for (int i=0;i<n;i++) {
            cin>>a[i];
        }
        max=0;
        for (int i=0;i<n;i++){
            int broj=NAJZNACAEN(a[i]);
            if (broj>max) {
                max=broj;
                m=a[i];
            }

        }
    }
    cout<<m<<endl;
    }


