#include <iostream>
#include<cstring>
using namespace std;
/*///////////////////////////////////////////////////VTORAAAAAAAA KOLOKVIUMSKAAAAAAAAAA///////////////////////////////////////////////////////////*/

class Employee{
    protected:
    char *ime;
    int plata;
    int bonus;
    int rabisk;

public:
    Employee() {
        this->ime = new char[0];
        this->plata=0;
        this->bonus=0;
        this->rabisk=0;

    }

    Employee(char *ime,int plata, int bonus,int rabisk) {
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->plata=plata;
        this->bonus=bonus;
        this->rabisk=rabisk;

    }

    Employee(const Employee &e) {
        this->ime = new char[strlen(e.ime)+1];
        strcpy(this->ime,e.ime);
        this->plata=e.plata;
        this->bonus=e.bonus;
        this->rabisk=e.rabisk;

    }

    Employee& operator=(const Employee &e) {
        if (this!=&e) {
            delete [] ime;
            this->ime = new char[strlen(e.ime)+1];
            strcpy(this->ime,e.ime);
            this->plata=e.plata;
            this->bonus=e.bonus;
            this->rabisk=e.rabisk;
        }
        return *this;
    }

    ~Employee() {
        delete [] ime;

    }

    int getTotalPlata() {
        return plata +(bonus*rabisk);
    }

    void print() {
        cout<<"Employee name: "<<ime<<endl;
        cout<<"Salary: "<<getTotalPlata()<<endl;
        cout<<"Experiance: "<<rabisk<<endl;

    }
    int getBonus(){
        return bonus;
    }
    int getPLata(){
        return plata;
    }

};

class Manager: public Employee{
private:
    char *department;
    int managerBonus;
public:
    Manager() {
        this->department=new char[0];
        this->managerBonus=0;
    }
    Manager(Employee &employees,char *department,int managerBonus):Employee(employees) {
        this->department=new char[strlen(department)+1];
        strcpy(this->department,department);
        this->managerBonus=managerBonus;
    }

    Manager(char *name,int salary,int bonus,int experience, char *department, int managerBonus):Employee(name,salary,bonus,experience) {
        this->department=new char[strlen(department)+1];
        strcpy(this->department,department);
        this->managerBonus=managerBonus;
    }


    Manager(const Manager &m):Employee(m){
        this->department=new char[strlen(m.department)+1];
        strcpy(this->department,m.department);
        this->managerBonus=m.managerBonus;
    }

    Manager& operator=(const Manager &m){
        if (this!=&m) {
            delete [] department;
            this->department=new char[strlen(m.department)+1];
            strcpy(this->department,m.department);
            this->managerBonus=m.managerBonus;
            delete [] ime;
            this->ime=new char[strlen(m.ime)+1];
            strcpy(this->ime,m.ime);
            this->plata=m.plata;
            this->bonus=m.bonus;
            this->rabisk=m.rabisk;
        }
        return *this;
    }

    ~Manager(){
        delete [] department;
    }


    int getTotalManagerBonus(){
        return bonus+managerBonus;
    }
    int getTotalSalary(){
        return plata + (getTotalManagerBonus() * plata);
    }
    void print(){
        cout<<"Manager name: "<<ime<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Salary: "<<getTotalSalary()<<endl;
        cout<<"Experience: "<<rabisk<<endl;
    }
};



int main() {

    char name[20];
    int salary;
    int bonus;
    int experience;
    char department[50];
    int managerBonus;

    Employee * employees = new Employee[5];
    Manager * managers = new Manager[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "EMPLOYEES:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> salary >> bonus >> experience;
            employees[i] = Employee(name, salary, bonus, experience);
            employees[i].print();
            cout<<endl;
        }
    }
    else if (n == 2) {

        for (int i=0; i < 5; ++i){
            cin >> name >> salary >> bonus >> experience;
            cin >> department >> managerBonus;
            employees[i] = Employee(name, salary, bonus, experience);
            managers[i] = Manager(employees[i], department, managerBonus);
        }

        cout << "EMPLOYEES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            employees[i].print();
            cout<<endl;
        }


        cout << "MANAGERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            managers[i].print();
            cout<<endl;
        }

    }
    else if (n == 3) {

        for (int i=0; i < 5; ++i){
            cin >> name >> salary >> bonus >> experience;
            cin >> department >> managerBonus;
            managers[i] = Manager(name, salary, bonus, experience, department, managerBonus);
        }
        cout << "MANAGERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            managers[i].print();
            cout<<endl;
        }

    }

    delete [] employees;
    delete [] managers;
}