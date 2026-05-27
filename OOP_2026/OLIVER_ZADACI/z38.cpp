#include<iostream>
using namespace std;
class Person {
private:
    char ime[20];
    char prezime[20];
public:
    Person() {
        strcpy(this->ime,"not specified");
        strcpy(this->prezime,"not specified");
    }

    Person(char ime[20],char prezime[20]) {
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
    }

    Person(const Person &p) {
        strcpy(this->ime,p.ime);
        strcpy(this->prezime,p.prezime);
    }
    void print() {
        cout<<ime<<" "<<prezime<<endl;
    }
    friend class Car;

};
class Date {
private:
    int den;
    int mesec;
    int godina;
public:
    Date() {
        this->den=0;
        this->mesec=0;
        this->godina=0;

    }

    Date(int den,int mesec,int godina) {
        this->den=den;
        this->mesec=mesec;
        this->godina=godina;

    }

    Date(const Date &d) {
        this->den=d.den;
        this->mesec=d.mesec;
        this->godina=d.godina;

    }
    void print() {
        cout<<den<<" "<<mesec<<" "<<godina<<endl;
    }
friend class Car;
};
class Car {
private:
    Person sopstvenik;
    Date data;
    float cena;
public:
    Car() {
        this->sopstvenik=Person();
        this->data=Date();
        this->cena=0;

    }

    Car( Person sopstvenik ,Date data,float cena) {
        this->sopstvenik=sopstvenik;
        this->data=data;
        this->cena=cena;

    }

    Car(const Car &c) {
        this->sopstvenik=c.sopstvenik;
        this->data=c.data;
        this->cena=c.cena;

    }
   void print() {
        cout<<"SOPSTVENIK "<<endl;
        sopstvenik.print();
        cout<<"DATA "<<endl;

        data.print();
        cout<<"CENA "<<endl;
        cout<<cena<<endl;



    }
    void cheaperThan(Car* cars, int numCars, float price) {


    }
};
int main() {
    char name[20];
    char lastName[20];
    int year;
    int month;
    int day;
    float price;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);
        cin >> year;
        cin >> month;
        cin >> day;
        Date date(year, month, day);
        cin >> price;
        Car car(lik, date,  price);
        car.print();
    }
    else if (testCase == 2) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);
        cin >> year;
        cin >> month;
        cin >> day;
        Date date(Date(year, month, day));
        cin >> price;
        Car car(lik, date,  price);
        car.print();
    }
    else {
        int numCars;
        cin >> numCars;
        Car cars[10];
        for (int i = 0; i < numCars; i++) {
            cin >> name;
            cin >> lastName;
            Person lik(name, lastName);
            cin >> year;
            cin >> month;
            cin >> day;
            Date date(year, month, day);
            cin >> price;
            cars[i] = Car(lik, date,  price);
        }
        float priceLimit;
        cin >> priceLimit;
        cheaperThan(cars, numCars, priceLimit);
    }
    return 0;
}