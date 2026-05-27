#include <iostream>
#include <iomanip>
using namespace std;
struct proizvod {
    string ime;
    float cena;
    int kolicina;
};
int main() {
    int n;
    cin>>n;
    proizvod a[n];
    float total=0;
    for (int i=0;i<n;i++) {
        cin>>a[i].ime;
        cin>>a[i].cena;
        cin>>a[i].kolicina;
    }
    for (int i=0;i<n;i++) {
        cout<<i<<"."<<a[i].ime<<"\t"<<fixed<<setprecision(2)<<a[i].cena<<" x "<<a[i].kolicina<<" = "<<a[i].cena*a[i].kolicina<<endl;
        total=total+a[i].cena*a[i].kolicina;
    }
    cout<<"Total: "<<fixed<<setprecision(2)<<total<<endl;


}