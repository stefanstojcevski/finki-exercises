#include<iostream>
#include<iomanip>
using namespace std;
struct Item {
    char ime[50];
    int cena;

};
struct Shopingcard {
    int id;
    int brojproizvodi;
    Item items[100];
};
void prosecna_suma(Shopingcard a[],int n) {
    int zbir=0;
    float sredna;

    for (int i=0;i<n;i++) {
        int najmala=0;
        for (int j=0;j<a[i].brojproizvodi;j++) {
            if (a[i].items[j].cena<a[i].items[najmala].cena) {
                najmala=j;
            }
        }
        zbir+=a[i].items[najmala].cena;
    }
    sredna=(float)zbir/(float)n;
    cout<<sredna<<endl;


}
void najvisokacena(Shopingcard a[],int n) {
    for (int i=0;i<n;i++) {
        int najgolem=0;

        for (int j=0;j<a[i].brojproizvodi;j++) {
            if (a[i].items[j].cena>a[i].items[najgolem].cena) {
                najgolem=j;
            }
        }
        cout<<a[i].items[najgolem].ime<<"  "<<a[i].id<<endl;
    }

}
int main () {
    int n;
    cin>>n;
    Shopingcard a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i].id>>a[i].brojproizvodi;
        for (int j=0;j<a[i].brojproizvodi;j++) {
            cin>>a[i].items[j].ime>>a[i].items[j].cena;
        }
    }
    prosecna_suma(a,n);
    najvisokacena(a,n);


}