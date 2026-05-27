#include <iostream>
#include<cstring>
using namespace std;

class Employee {
protected:
    char ime[50];
    int godini;
    int rabisk;

public:
    Employee() {
        strcpy(this->ime, "");
        this->godini = 0;
        this->rabisk = 0;
    }

    Employee(char ime[50], int godini, int rabisk) {
        strcpy(this->ime, ime);
        this->godini = godini;
        this->rabisk = rabisk;
    }

    Employee(const Employee &e) {
        strcpy(this->ime, e.ime);
        this->godini = e.godini;
        this->rabisk = e.rabisk;
    }

    virtual double plata()const =0;

    virtual double bonus ()const =0;

     bool operator==(const Employee &e){
         if (godini==e.godini) {
             if (bonus() == e.bonus()) {
                 return true;
             }
         }
         return false;

    }
};

class SalaryEmployee : public Employee {
protected:
    int zarabotka;

public:
    SalaryEmployee() {
        this->zarabotka = 0;
    }

    SalaryEmployee(char ime[50], int godini, int rabisk, int zarabotka) : Employee(ime, godini, rabisk) {
        this->zarabotka = zarabotka;
    }

    SalaryEmployee(const SalaryEmployee &e) : Employee(e) {
        this->zarabotka = e.zarabotka;
    }

    double bonus()const {
        return zarabotka * rabisk / 100;
    }

    double plata()const {
        return zarabotka + bonus();
    }
};

class HourlyEmployee : public Employee {
protected:
    int vkupenbroj;
    int cena;

public:
    HourlyEmployee() {
        this->vkupenbroj = 0;
        this->cena = 0;
    }

    HourlyEmployee(char ime[50], int godini, int rabisk, int vkupenbroj, int cena) : Employee(ime, godini, rabisk) {
        this->vkupenbroj = vkupenbroj;
        this->cena = cena;
    }

    HourlyEmployee(const HourlyEmployee &h) : Employee(h) {
        this->vkupenbroj = h.vkupenbroj;
        this->cena = h.cena;
    }

    double bonus()const  {
        if (vkupenbroj > 320) {
            int ost = vkupenbroj - 320;
            return ost * (cena * 0.5);
        }
        return 0;
    }

    double plata()const  {
        return vkupenbroj * cena + bonus();
    }
};

class Freelancer : public Employee {
protected:
    int brojproekti;
    double proekti[10];

public:
    Freelancer() {
        this->brojproekti = 0;
        for (int i = 0; i < brojproekti; i++) {
            proekti[i] = 0;
        }
    }

    Freelancer(char ime[50], int godini, int rabisk, int brojproekti, double proekti[10]) : Employee(
        ime, godini, rabisk) {
        this->brojproekti = brojproekti;
        for (int i = 0; i < brojproekti; i++) {
            this->proekti[i] = proekti[i];
        }
    }

    Freelancer(const Freelancer &f) : Employee(f) {
        this->brojproekti = f.brojproekti;
        for (int i = 0; i < f.brojproekti; i++) {
            proekti[i] = f.proekti[i];
        }
    }

    double bonus()const  {
        if (brojproekti > 5) {
            return (brojproekti - 5) * 1000;
        }
        return 0;
    }

    double plata()const {
        double suma = 0;

        for (int i = 0; i < brojproekti; i++) {
            suma += proekti[i];
        }

        return suma + bonus();
    }
};
class Company {
protected:
    char ime[50];
    int brojj;
    Employee **employees;
public:
    Company() {
        strcpy(this->ime,"");
        this->brojj=0;
        this->employees=nullptr;
    }

    Company( char ime[50]) {
        strcpy(this->ime,ime);
        this->brojj=0;
        this->employees=nullptr;
    }
    Company & operator+=( Employee *e) {
        Employee **temp=new Employee*[brojj+1];
        for (int i=0;i<brojj;i++) {
            temp[i]=employees[i];
        }
        temp[brojj]=e;
        brojj++;
        delete [] employees;
        employees=temp;
        return *this;



    }

    double vkupnaPlata() {
        int zbir=0;
        for (int i=0;i<brojj;i++) {
            zbir+=employees[i]->plata();
        }
        return zbir;
    }

    double filtriranaPlata(Employee *emp) {
        double zbir = 0;

        for (int i = 0; i < brojj; i++) {
            if (*employees[i] == *emp) {
                zbir += employees[i]->plata();
            }
        }

        return zbir;
    }

    void pecatiRabotnici() {
        int salary = 0;
        int hourly = 0;
        int freelancers = 0;

        for (int i = 0; i < brojj; i++) {
            if (dynamic_cast<SalaryEmployee*>(employees[i]) != nullptr) {
                salary++;
            }
            else if (dynamic_cast<HourlyEmployee*>(employees[i]) != nullptr) {
                hourly++;
            }
            else if (dynamic_cast<Freelancer*>(employees[i]) != nullptr) {
                freelancers++;
            }
        }

        cout << "Vo kompanijata " << ime << " rabotat:" << endl;
        cout << "Salary employees: " << salary << endl;
        cout << "Hourly employees: " << hourly << endl;
        cout << "Freelancers: " << freelancers << endl;
    }




};



int main() {
    char name[50];
    cin >> name;
    Company c(name);

    int n;
    cin >> n;

    char employeeName[50];
    int age;
    int experience;
    int type;

    for (int i = 0; i < n; ++i) {
        cin >> type;
        cin >> employeeName >> age >> experience;

        if (type == 1) {
            int basicSalary;
            cin >> basicSalary;
            c += new SalaryEmployee(employeeName, age, experience, basicSalary);
        } else if (type == 2) {
            int hoursWorked;
            int hourlyPay;
            cin >> hoursWorked >> hourlyPay;
            c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
        } else {
            int numProjects;
            cin >> numProjects;
            double projects[10];
            for (int i = 0; i < numProjects; ++i) {
                cin >> projects[i];
            }
            c += new Freelancer(employeeName, age, experience, numProjects, projects);
        }
    }

    c.pecatiRabotnici();
    cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
    Employee *emp = new HourlyEmployee("Petre_Petrov", 31, 6, 340, 80);
    cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);
    delete emp;
}
