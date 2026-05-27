#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Employee {
private:
    char ime[100];
    char prezime[100];
    int plata;

public:
    Employee() {
        strcpy(this->ime, "");
        strcpy(this->prezime, "");
        this->plata = 0;
    }

    Employee(char ime[100], char prezime[100], int plata) {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->plata = plata;
    }

    Employee(const Employee &e) {
        strcpy(this->ime, e.ime);
        strcpy(this->prezime, e.prezime);
        this->plata = e.plata;
    }

    ~Employee() {
    }

    void printEmployee() {
        cout << "Employee name: " << ime << endl;
        cout << "Employee surname: " << prezime << endl;
        cout << "Employee salary: " << plata << endl;
    }

    int getPlata() {
        return plata;
    }
};

class TechCompany {
private:
    char imeF[100];
    Employee employees[100];
    int numbEmployees;

public:
    TechCompany() {
        strcpy(this->imeF, "");
        this->numbEmployees = 0;
    }

    TechCompany(char imeF[100]) {
        strcpy(this->imeF, imeF);
        this->numbEmployees = 0;
    }

    TechCompany(const TechCompany &t) {
        strcpy(this->imeF, t.imeF);
        this->numbEmployees = t.numbEmployees;
        for (int i = 0; i < t.numbEmployees; i++) {
            this->employees[i] = t.employees[i];
        }
    }

    ~TechCompany() {
    }

    void print() {
        cout << "Tech company name: " << imeF << endl;
        cout << "NumberofEmployees: " << numbEmployees << endl;
    }

    double getAvarageofEmployeesSalary() {
        double zbir = 0;
        double prosek;
        if (numbEmployees == 0) {
            return 0;
        } else {
            for (int i = 0; i < numbEmployees; i++) {
                zbir += employees[i].getPlata();
            }
            prosek = zbir / double(numbEmployees);
        }

        return prosek;
    }

    void addEmployee(Employee e) {
        if (numbEmployees >= 100) {
            return;
        }
        employees[numbEmployees] = e;
        numbEmployees++;
    }
    Employee getEmployee(int index) {
        return employees[index];
    }

    char *getName() {
        return imeF;
    }

    void setName(char imeF[100]) {
        strcpy(this->imeF, imeF);
    }

    int getnumbEmployees() {
        return numbEmployees;
    }

    int setnumbEmployees(int getnumbEmployees) {
        this->numbEmployees = getnumbEmployees;
    }
};


TechCompany printCompanyWithHighestAverageSalary(TechCompany companies[], int numCompanies) {

    double maxAvg = companies[0].getAvarageofEmployeesSalary();
    int index = 0;

    for(int i = 1; i < numCompanies; i++) {

        double avg = companies[i].getAvarageofEmployeesSalary();

        if(avg > maxAvg) {
            maxAvg = avg;
            index = i;
        }
    }

    return companies[index];
}

bool isSameCompany(TechCompany c1, TechCompany c2) {

    if(strcmp(c1.getName(), c2.getName()) == 0)
        return true;

    return false;
}

TechCompany printCompanyWithHighestStdSalary(TechCompany companies[], int numCompanies) {

    double maxStd = -1;
    int index = 0;

    for(int i = 0; i < numCompanies; i++) {

        int n = companies[i].getnumbEmployees();

        if(n <= 1) continue;

        double avg = companies[i].getAvarageofEmployeesSalary();
        double var = 0;

        for(int j = 0; j < n; j++) {

            double diff = companies[i].getEmployee(j).getPlata() - avg;
            var += diff * diff;
        }

        var = var / (n - 1);

        double std = sqrt(var);

        if(std > maxStd) {
            maxStd = std;
            index = i;
        }
    }

    return companies[index];
}

int main() {
    const int MAX_COMPANIES = 10;
    const int MAX_EMPLOYEES = 20;

    TechCompany companies[MAX_COMPANIES];

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char name[100];
        std::cin >> name;

        TechCompany company(name);

        int m;
        std::cin >> m;

        for (int j = 0; j < m; j++) {
            char name[100];
            char surname[100];
            int salary;

            std::cin >> name;

            std::cin >> surname;

            std::cin >> salary;

            Employee employee(name, surname, salary);

            company.addEmployee(employee);
        }

        companies[i] = company;
    }

    TechCompany copy = companies[0];

    std::cout << "-->Testing get and set methods for one object and copy constructor" << std::endl;
    copy.setName("copy");
    std::cout << copy.getName() << std::endl;


    std::cout << "-->Testing addEmployee function" << std::endl;
    Employee newEmployee("John", "Doe", 5000);
    copy.addEmployee(newEmployee);
    std::cout << "Number of employees in copy: " << copy.getnumbEmployees() << std::endl;


    std::cout << "-->Testing copy of first employee" << std::endl;
    Employee firstEmployee = copy.getEmployee(0);
    firstEmployee.printEmployee();


    std::cout << "-->Testing methods" << std::endl;
    TechCompany t = printCompanyWithHighestAverageSalary(companies, n);
    TechCompany t1 = printCompanyWithHighestStdSalary(companies, n);

    std::cout << "Tech company with the highest average salary: " << t.getName() << std::endl;
    std::cout << "Tech company with the highest standard deviation for salaries: " << t1.getName() << std::endl;

    if (isSameCompany(t, t1)) {
        std::cout << "The tech company: " << t.getName() <<
                " has the highest standard deviation and highest average salary" << std::endl;
    }
    return 0;
}


