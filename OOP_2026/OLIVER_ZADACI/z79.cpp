#include<iostream>
#include<cstring>
using namespace std;
class InvalidSerialNumberException {
public:
    void pecati() {
        cout<<"Invalid Serial Number Exception"<<endl;
    }
};
class Car {
protected:
    char proizvoditel[50];
    char model[50];
    int godina;
    char seriskibroj[7];
    int cena;

public:
    Car() {
        strcpy(this->proizvoditel, "");
        strcpy(this->model, "");
        this->godina = 0;
        strcpy(this->seriskibroj, "");
        this->cena = 0;
    }

    Car(char proizvoditel[50], char model[50], int godina, char seriskibroj[7], int cena) {
        strcpy(this->proizvoditel, proizvoditel);
        strcpy(this->model, model);
        this->godina = godina;
        strcpy(this->seriskibroj, seriskibroj);
        this->cena = cena;
    }

    Car(const Car &c) {
        strcpy(this->proizvoditel, c.proizvoditel);
        strcpy(this->model, c.model);
        this->godina = c.godina;
        strcpy(this->seriskibroj, c.seriskibroj);
        this->cena = c.cena;
    }

    virtual int totalPrice() {
        return cena * 1.18;
    }

    virtual void displayInfo() {
        cout << " Manufacturer : " << proizvoditel << endl;
        cout << "Model : " << model << endl;
        cout << "Year : " << godina << endl;
        cout << "Serial number : " << seriskibroj << endl;
        cout << "Price : " << totalPrice() << endl;
    }
};

class ElectricCar : public Car {
protected:
    int baterija;
    static int ELE;

public:
    ElectricCar() {
        this->baterija = 0;
    }

    ElectricCar(char proizvoditel[50], char model[50], int godina, char seriskibroj[7], int cena, int baterija) : Car(
        proizvoditel, model, godina, seriskibroj, cena) {
        this->baterija = baterija;
    }

    ElectricCar(const ElectricCar &e) : Car(e) {
        this->baterija = e.baterija;
    }

    virtual int totalPrice() {
        if (seriskibroj[0]!='A' && seriskibroj[0]!='B' && seriskibroj[0]!='C') {
            throw InvalidSerialNumberException();
        }
        return cena+(cena*ELE*baterija)/100;
    }
    void displayInfo() {
        cout << "Model : " << model << endl;
        cout << "Battery : " << baterija << endl;
        cout << "Serial number : " << seriskibroj << endl;
        cout << "Price : " <<totalPrice()<<endl;
    }
};
int ElectricCar::ELE=5;
int main() {
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "--- Testing Car class ---" << endl;
        char manufacturer[50], model[50], serialNumber[7];
        int price, year;
        cin >> manufacturer >> model >> year >> serialNumber >> price;
        Car car(manufacturer, model, year, serialNumber, price);
        try {
            car.displayInfo();
        }
        catch (InvalidSerialNumberException e) {
            e.pecati();
        }
    } else if (choice == 2) {
        cout << "--- Testing ElectricCar class ---" << endl;
        char manufacturer[50], model[50], serialNumber[7];
        int price, year, battery;
        cin >> manufacturer >> model >> year >> serialNumber >> price >> battery;
        ElectricCar car(manufacturer, model, year, serialNumber, price, battery);
        try {
            car.displayInfo();
        }
        catch (InvalidSerialNumberException e) {
            e.pecati();
        }
    } else if (choice == 3) {
        cout << "--- Testing Exceptions ---" << endl;
        char manufacturer[50], model[50], serialNumber[7];
        int price, year, battery;
        cin >> manufacturer >> model >> year >> serialNumber >> price >> battery;
        ElectricCar car(manufacturer, model, year, serialNumber, price, battery);
        try {
            car.displayInfo();
        }
        catch (InvalidSerialNumberException e) {
            e.pecati();
        }
    }
    return 0;
}
