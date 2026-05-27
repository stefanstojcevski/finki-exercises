#include <iostream>
#include <cstring>

using namespace std;

class Employee{
protected:
    char ime[20];
    int godini;

public:
    Employee() {
        strcpy(this->ime,"");
        this->godini=0;

    }

    Employee(  char ime[20],int godini) {
        strcpy(this->ime,ime);
        this->godini=godini;

    }

    Employee(  const Employee &e) {
        strcpy(this->ime,e.ime);
        this->godini=e.godini;

    }

    Employee& operator  =(  const Employee &e) {
        if (this!=&e) {
            strcpy(this->ime,e.ime);
            this->godini=e.godini;
        }
        return *this;
    }

    virtual void displayinfo() {
        cout<<"Name: "<<ime<<endl;
        cout<<"Age: "<<godini<<endl;
    }
};

class Payable {
protected:
    double plata;
public:
    Payable() {
        this->plata=0;
    }
    Payable( double plata) {
        this->plata=plata;
    }

    Payable(const Payable &p) {
        this->plata=p.plata;
    }

    Payable& operator=(const Payable &p) {
        if (this!=&p) {
            this->plata=p.plata;

        }
        return *this;
    }

    virtual double calculateSalary()=0;

};

class Developer:public Employee,public Payable {
protected:
    char jazik[20];
public:
    Developer() {
        strcpy(this->jazik,"");
    }

    Developer(char ime[20],int godini,double plata,char jazik[20]):Employee(ime,godini),Payable( plata) {
        strcpy(this->jazik,jazik);
    }

    Developer(const Developer &d):Employee(d),Payable( d) {
        strcpy(this->jazik,d.jazik);
    }

    Developer& operator=(const Developer &d) {
        if (this!=&d) {
            strcpy(this->jazik,d.jazik);

            strcpy(this->ime,d.ime);
            this->godini=d.godini;

            this->plata=d.plata;

        }
        return *this;
    }

    double calculateSalary(){
        return plata-(plata*0.10);
    }
    void displayInfo(){
        cout<<"--Developer Information--"<<endl;
        Employee::displayinfo();
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Prorgamming language:"<<jazik<<endl;
    }
};

class Manager:public Employee,public Payable {
protected:
    int brodeli;
public:
    Manager() {
        this->brodeli=0;

    }
    Manager(char ime[20],int godini,double plata,int brodeli):Employee(ime,godini),Payable( plata) {
        this->brodeli=brodeli;
    }

    Manager(const Manager &m):Employee(m),Payable( m) {
        this->brodeli=m.brodeli;
    }

    Manager& operator =(const Manager &m) {
        if (this!=&m) {
            this->brodeli=m.brodeli;

            strcpy(this->ime,m.ime);
            this->godini=m.godini;

            this->plata=m.plata;

        }
        return *this;
    }


    double calculateSalary(){
        return plata+(plata*0.05*brodeli);
    }
    void displayInfo(){
        cout<<"--Manager Information--"<<endl;
        Employee::displayinfo();
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Number of Departments:"<<brodeli<<endl;
    }


};
double biggestSalary(Payable *payable[], int n){
    double max=0;
    for(int i=0; i<n; i++)
    {
        double salary=payable[i]->calculateSalary();
        if(salary>max){
            max=salary;
        }
    }
    return max;
}
int main(){
    Payable *payable[5];
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