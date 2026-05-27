#include <iostream>
using namespace std;
struct Item {
    char ime[100];
    int cena;
};
struct Shopingcart {
    int id;
    int brojItems;
    Item items[100];
};
void printAvaragePriceOfLowestItems(Shopingcart a[],int n) {
    int zbir=0;
    int sreden;

    for (int i=0;i<n;i++) {
        int najmal=0;
        for (int j=0;j<a[i].brojItems;j++) {
            if (a[i].items[najmal].cena>a[i].items[j].cena) {
                najmal=j;
            }
        }
        zbir+=a[i].items[najmal].cena;

    }
    sreden=zbir/n;
    cout<<sreden<<endl;



}
void printHighestItems(Shopingcart a[],int n) {
    for (int i=0;i<n;i++) {
        int najgolem=0;
        for (int j=0;j<a[i].brojItems;j++) {
            if (a[i].items[najgolem].cena<a[i].items[j].cena) {
                najgolem=j;
            }
        }
        cout << a[i].items[najgolem].ime << " " << a[i].id << endl;
    }


}
int main() {
    int n;
    int zbir=0;
    cin>>n;
    Shopingcart a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i].id>>a[i].brojItems;
        for (int j=0;j<a[i].brojItems;j++) {
            cin >> a[i].items[j].ime >> a[i].items[j].cena;
        }
    }

    printAvaragePriceOfLowestItems(a,n);
    printHighestItems(a,n);



}