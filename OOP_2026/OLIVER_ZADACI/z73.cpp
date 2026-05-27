#include <iostream>
#include <cstring>
using namespace std;

class Employee {
protected:
    char ime[50];
    int godini;

public:
    Employee() {
        strcpy(this->ime, "");
        this->godini = 0;
    }

    Employee(char ime[50], int godini) {
        strcpy(this->ime, ime);
        this->godini = godini;
    }

    Employee(const Employee &e) {
        strcpy(this->ime, e.ime);
        this->godini = e.godini;
    }

    virtual void displayInfo() {
        cout << ime << " " << godini << endl;
    }

    ~Employee() {
    }
};

class Payable {
protected:
    double salary;

public:
    Payable() {
        this->salary=0;
    }
    Payable( double salary) {
        this->salary=salary;
    }
    Payable( const Payable &p) {
        this->salary=p.salary;
    }
virtual double calculateSalary()=0;
};
class Developer:public Employee,public Payable{
protected:
    char jazik[50];
public:
    Developer() {
        strcpy(this->jazik,"");
    }
    Developer(char ime[50],int godini,double salary,char jazik[50]):Employee(ime,godini),Payable(salary) {
        strcpy(this->jazik,jazik);
    }
    Developer(const Developer &d):Employee(d),Payable(d) {
        strcpy(this->jazik,d.jazik);
    }
    void displayInfo() {
        cout << ime << " " << godini <<calculateSalary()<<jazik<< endl;
    }

    double calculateSalary() {
        return salary*0.9;
    }
};
class Manager:public Employee,public Payable {
protected:
    int brodeli;
public:
    Manager() {
        this->brodeli=0;
    }
    Manager(char ime[50],int godini,double salary,int brodeli):Employee(ime,godini),Payable(salary) {
        this->brodeli=brodeli;
    }

    Manager(const Manager &m):Employee(m),Payable(m) {
        this->brodeli=m.brodeli;
    }
    void displayInfo() {
        cout << ime << " " << godini <<calculateSalary()<<brodeli<< endl;
    }
    double calculateSalary() {
        return salary+((salary*0.05)*brodeli);
    }
};
double biggestSalary(Payable *payable[], int n) {
    int max=0;
    for (int i=0;i<n;i++) {
        if (payable[i]->calculateSalary()>payable[max]->calculateSalary()) {
            max=i;
        }
    }
    return payable[max]->calculateSalary();
}
int main() {
    Payable* payable[5];
    Developer developers[5];
    Manager managers[5];
    int j=0, k=0;
    for(int i=0; i<5; i++)
    {
        char name[50];
        int age;
        double salary;
        cin>>name>>age>>salary;
        if(i%2==0)
        {
            char programmingLanguage[50];
            cin>>programmingLanguage;
            developers[j]=Developer(name, age, salary, programmingLanguage);
            developers[j].displayInfo();
            payable[i]=&developers[j];
            j++;
        }
        else {
            int numberOfDepartments;
            cin>>numberOfDepartments;
            managers[k]=Manager(name, age, salary, numberOfDepartments);
            managers[k].displayInfo();
            payable[i]=&managers[k];
            k++;
        }
    }
    cout<<endl<<"Biggest Salary: "<<biggestSalary(payable, 5);
    return 0;
}