#include <iostream>
using namespace std;
struct Engine {
    int horsepower;
    int torque;
};
struct Car {
    char array[100];
    int godina;
    Engine engines;
};
void printCars(Car a[],int n) {
    int najmala=0;
    int vtoranajmala=1;
    for (int i=0;i<n;i++) {

            if (a[i].engines.horsepower<a[najmala].engines.horsepower) {
                int temp=najmala;
                najmala=i;
                vtoranajmala=temp;

            }
            else if (a[i].engines.horsepower<a[vtoranajmala].engines.horsepower && a[i].engines.horsepower != a[najmala].engines.horsepower) {
                vtoranajmala=i;


        }
    }




            if (a[najmala].engines.torque>a[vtoranajmala].engines.torque) {
                cout<<"Manufacturer:"<<a[najmala].array<<endl;
                cout<<"Horsepower:"<<a[najmala].engines.horsepower<<endl;
                cout<<"Torque:"<<a[najmala].engines.torque<<endl;

            }
    else {
        cout<<"Manufacturer:"<<a[vtoranajmala].array<<endl;
        cout<<"Horsepower:"<<a[vtoranajmala].engines.horsepower<<endl;
        cout<<"Torque:"<<a[vtoranajmala].engines.torque<<endl;

    }
    }





int main() {
    int n;
    cin>>n;
    Car a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i].array>>a[i].godina>>a[i].engines.horsepower>>a[i].engines.torque;
    }
    printCars(a, n);

}