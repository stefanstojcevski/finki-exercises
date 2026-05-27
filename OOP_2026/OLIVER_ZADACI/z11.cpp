#include <iostream>
using namespace std;
struct Employee {
    char ime[20];
    char maticenbroj[20];
    char nizanaOdel[20];
    int plata;

};
struct Company {
    char ime[20];
    int brojvraboteni;
    Employee nizaodvraboteni[100];
};
void printEmployeesBellowAvarageSalary(Company a[],int n) {
    for (int i=0;i<n;i++) {
        int zbir=0;

        for (int j=0;j<a[i].brojvraboteni;j++) {
            zbir+=a[i].nizaodvraboteni[j].plata;
        }
        int prosek=zbir/a[i].brojvraboteni;
        for (int j=0;j<a[i].brojvraboteni;j++) {

            if (a[i].nizaodvraboteni[j].plata<prosek) {
                cout<<a[i].nizaodvraboteni[j].ime<<endl;
            }
        }
    }

}
void printHeighestSalaryEmployee(Company a[],int n) {
    for (int i=0;i<n;i++) {
        int max=0;
        int index=0;
        for (int j=0;j<a[i].brojvraboteni;j++) {
            if (a[i].nizaodvraboteni[j].plata>max) {
                max=a[i].nizaodvraboteni[j].plata;
                index=j;
            }

        }
        cout<<a[i].nizaodvraboteni[index].ime<<endl;

    }

}

int main() {
    int n;
    cin>>n;
    Company a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i].ime>>a[i].brojvraboteni;
        for (int j=0;j<a[i].brojvraboteni;j++) {
            cin>>a[i].nizaodvraboteni[j].ime>>a[i].nizaodvraboteni[j].maticenbroj>>a[i].nizaodvraboteni[j].nizanaOdel>>a[i].nizaodvraboteni[j].plata;
        }
    }
    printEmployeesBellowAvarageSalary(a,n) ;
    printHeighestSalaryEmployee( a, n);


}