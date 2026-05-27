/*
#include <iostream>
#include <cstring>
using namespace std;

class Film {
private:
    char ime[100];
    char reziser[50];
    char zanr[50];
    int godina;

public:
    Film() {
        strcpy(this->ime, " ");
        strcpy(this->reziser, " ");
        strcpy(this->zanr, " ");
        this->godina = 0;
    }

    Film(char ime[100], char reziser[50], char zanr[50], int godina) {
        strcpy(this->ime, ime);
        strcpy(this->reziser, reziser);
        strcpy(this->zanr, zanr);
        this->godina = godina;
    }

    ~Film() {
    }

    int getgodina() {
        return godina;
    }

    void print() {
        cout << "Ime: " << ime << endl;
        cout << "Reziser: " << reziser << endl;
        cout << "Zanr: " << zanr << endl;
        cout << "Godina: " << godina << endl;
    }
};

void pecati_po_godina(Film f[], int n, int godina) {
    for (int i = 0; i < n; i++) {
        if (f[i].getgodina() == godina) {
            f[i].print();
        }
    }
}

int main() {
    int n;
    cin >> n;
    Film film[n];
    for (int i=0;i<n;i++) {
        char ime[100];
        char reziser[50];
        char zanr[50];
        int godina;
        cin>>ime;
        cin>>reziser;
        cin>>zanr;
        cin>>godina;
        film[i]=Film (ime,reziser,zanr,godina);




    }
    int godina;
    cin >> godina;
    pecati_po_godina(film, n, godina);
}
*/
/*
#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char ime[100];
    char prezime[50];
    int index;
    int ocenki[5];

public:
    Student() {
        strcpy(this->ime, "");
        strcpy(this->prezime, "");
        this->index = 0;
        for (int i = 0; i < 5; i++) {
            this->ocenki[i] = 0;
        }
    }

    Student(char ime[100],char prezime[50],int index,int ocenki[5]) {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->index = index;
        for (int i = 0; i < 5; i++) {
            this->ocenki[i] = ocenki[i];
        }
    }

    ~Student() {

    }

    void print() {
        cout << "Student: " << ime << " " << prezime
      << " with index " << index
      << " has average grade: " << prosek() << endl;
    }

    float prosek() {
        float zbir=0;
        for (int i=0;i<5;i++) {
            zbir+=ocenki[i];
        }
        return zbir/5.0;
    }

};
void bestStudents(Student students[],int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].prosek()>students[j+1].prosek()) {
                Student temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;



            }
        }
    }
    for (int i=0;i<n;i++) {
        students[i].print();
    }

}
int main() {
    int  n;
    cin>>n;
    Student s[n];
    for (int i=0;i<n;i++) {
        char ime[100];
        char prezime[50];
        int index;
        int ocenki[5];

        cin>>ime;
        cin>>prezime;
        cin>>index;
        for (int j=0;j<5;j++) {
            cin>>ocenki[j];
        }
        s[i]=Student (ime,prezime,index,ocenki);



    }

    bestStudents(s, n);

}
*/

/*
#include <iostream>
#include <cstring>
using namespace std;

class Film {
private:
    char ime[100];
    float rejting;
    float zarabotka;
public:
    Film() {
        strcpy(this->ime,"");
        this->rejting=0;
        this->zarabotka=0;
    }

    Film(char ime[100],float rejting,float zarabotka) {
        strcpy(this->ime,ime);
        this->rejting=rejting;
        this->zarabotka=zarabotka;
    }
    ~Film() {

    }
    void print() {
        cout<<ime<<endl;
        cout<<rejting<<endl;
        cout<<zarabotka<<endl;

    }
    float getzarabotka() {
        return zarabotka;

    }
};
void mostPopular(Film filmovi[],int n) {
    int max=0;
    int index;
    for (int i=0;i<n;i++) {
        if (filmovi[i].getzarabotka()>max) {
            max=filmovi[i].getzarabotka();
            index=i;
        }
    }
    filmovi[index].print();

}
int main() {
    int n;
    cin>>n;
    Film filmovi[n];
    for (int i=0;i<n;i++) {
        char ime[100];
        float rejting;
        float zarabotka;
        cin>>ime;
        cin>>rejting;
        cin>>zarabotka;
        filmovi[i]=Film(ime,rejting,zarabotka);


    }
    mostPopular(filmovi,n);

}
*/
/*
#include <iostream>
#include <cstring>
using namespace std;

class Country {
private:
    char name[100];
    char capital[100];
    float area;
    float population;

public:
    // default constructor
    Country() {
        strcpy(name, "");
        strcpy(capital, "");
        area = 0;
        population = 0;
    }

    // constructor so parametri
    Country(char name[], char capital[], float area, float population) {
        strcpy(this->name, name);
        strcpy(this->capital, capital);
        this->area = area;
        this->population = population;
    }

    // destructor
    ~Country() {}

    // set metodi
    void setName(char name[]) {
        strcpy(this->name, name);
    }

    void setCapital(char capital[]) {
        strcpy(this->capital, capital);
    }

    void setArea(float area) {
        this->area = area;
    }

    void setPopulation(float population) {
        this->population = population;
    }

    // get metodi
    char* getName() {
        return name;
    }

    char* getCapital() {
        return capital;
    }

    float getArea() {
        return area;
    }

    float getPopulation() {
        return population;
    }

    // display
    void display() {
        cout << "Country: " << name << endl;
        cout << "Capital: " << capital << endl;
        cout << "Area: " << area << endl;
        cout << "Population: " << population << endl;
    }
};

// ❗ ОВАА ФУНКЦИЈА ТИ ЈА ОСТАВАМ ПРАЗНА
void sortCountries(Country *countries, int n) {
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1-i;j++) {
            if (countries[j].getArea()>countries[j+1].getArea()) {
                Country temp=countries[j];
                countries[j]=countries[j+1];
                countries[j+1]=temp;

            }
        }
    }

}
*/
/*
#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char name[100];
    char surname[100];
    int salary;
public:
    Employee(){
        strcpy(this->name,"");
        strcpy(this->surname,"");
        this->salary=0;
    }
    Employee(char name[100],char surname[100],int salary){
        strcpy(this->name,name);
        strcpy(this->surname,surname);
        this->salary=salary;
    }
    Employee(const Employee &e){//copy constructor
        strcpy(this->name,e.name);
        strcpy(this->surname,e.surname);
        this->salary=e.salary;
    }
    ~Employee(){
    }

    void printEmployee(){
        cout<<"Employee name:"<<name<<endl;
        cout<<"Employee surname:"<<surname<<endl;
        cout<<"Employee salary:"<<salary<<endl;
    }
    int getSalary(){
        return salary;
    }

    float getPlata() {
        return salary;
    }
};


class TechCompany {
private:
    char name[100];
    Employee employees[100];
    int numOfEmployee;
public:
    TechCompany(){
        strcpy(this->name,"");
        this->numOfEmployee=0;
        for(int i=0;i<numOfEmployee;i++){
            this->employees[i]=employees[i];
        }
    }

    TechCompany( char name[100]){
        strcpy(this->name,name);
        this->numOfEmployee=0;
        for(int i=0;i<numOfEmployee;i++){
            this->employees[i]=employees[i];
        }
    }

    TechCompany( const TechCompany &t){
        strcpy(this->name,t.name);
        this->numOfEmployee=t.numOfEmployee;
        for(int i=0;i<t.numOfEmployee;i++){
            this->employees[i]=t.employees[i];
        }
    }
    ~TechCompany() {

    }
    void print(){
        cout<<"Teach company name: "<<name<<endl;
        cout<<"Number of employees: "<<numOfEmployee<<endl;
    }
    double getAverageOfEmployeesSalary() {
        int zbir=0;
        for (int i=0;i<numOfEmployee;i++) {
            zbir+=employees[i].getPlata();

        }
        return zbir/numOfEmployee;
    }
    void addEmployee(Employee e) {
        employees[numOfEmployee]=e;
            numOfEmployee++;

    }
    int getNumEmployees(){
        return numOfEmployee;
    }
    Employee getEmployee(int i){
        return employees[i];
    }
    void setName(char name[100]){
        strcpy(this->name,name);
    }
    char *getName(){
        return name;
    }
};

TechCompany printCompanyWithHighestStdSalary(TechCompany companies[],int numCompany){
    double max=0;
    int index=0;
    for(int i=0;i<numCompany;i++){
        double avgSalary=companies[i].getAverageOfEmployeesSalary();
        double zbir=0;
        for(int j=0;j<companies[i].getNumEmployees();j++){
            int salary=	companies[i].getEmployee(j).getSalary();
            zbir+=pow(salary-avgSalary,2);
        }
        double var=zbir/companies[i].getNumEmployees();
        double std=sqrt(var);
        if(std>max){
            max=std;
            index=i;
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

    std::cout<<"-->Testing get and set methods for one object and copy constructor"<<std::endl;
    copy.setName("copy");
    std::cout << copy.getName() << std::endl;


    std::cout<<"-->Testing addEmployee function"<<std::endl;
    Employee newEmployee("John", "Doe", 5000);
    copy.addEmployee(newEmployee);
    std::cout << "Number of employees in copy: " << copy.getNumEmployees() << std::endl;


    std::cout<<"-->Testing copy of first employee"<<std::endl;
    Employee firstEmployee = copy.getEmployee(0);
    firstEmployee.printEmployee();


    std::cout<<"-->Testing methods"<<std::endl;
    TechCompany t = printCompanyWithHighestAverageSalary(companies, n);
    TechCompany t1 = printCompanyWithHighestStdSalary(companies, n);

    std::cout << "Tech company with the highest average salary: " << t.getName() << std::endl;
    std::cout << "Tech company with the highest standard deviation for salaries: " <<t1.getName() << std::endl;

    if (isSameCompany(t, t1)){
        std::cout<<"The tech company: "<<t.getName()<<" has the highest standard deviation and highest average salary"<<std::endl;
    }
    return 0;
}

*/
/*
#include <iostream>
#include <cstring>
using namespace std;

class SpaceObject {
private:
    char name[100];
    char type[100];
    int distanceFromEarth;
public:
    SpaceObject() {
        strcpy(this->name, "");
        strcpy(this->type, "");
        this->distanceFromEarth = 0;
    }

    SpaceObject(char name[100], char type[100], int distanceFromEarth) {
        strcpy(this->name, name);
        strcpy(this->type, type);
        this->distanceFromEarth = distanceFromEarth;
    }

    SpaceObject(const SpaceObject &s) {
        strcpy(this->name, s.name);
        strcpy(this->type, s.type);
        this->distanceFromEarth = s.distanceFromEarth;
    }

    void print() {
        cout << name << " ( " << type << " ) - distance: " << distanceFromEarth << " light years away from Earth." <<
                endl;
    }
    int getDistanceFromEarth() {
        return distanceFromEarth;
    }
};

class Alien {
private:
    char name[100];
    int age;
    char homePlanet[100];
    int numObj;
    SpaceObject spaceObjects[100];

public:
    Alien() {
        strcpy(this->name, "");
        this->age = 0;
        strcpy(this->homePlanet, "");
        this->numObj = 0;
        for (int i=0;i<numObj;i++) {
            this->spaceObjects[i]=spaceObjects[i];
        }
    }

    Alien(char name[100],int age,char homePlanet[100],int numObj,SpaceObject spaceObjects[]) {
        strcpy(this->name, name);
        this->age = age;
        strcpy(this->homePlanet, homePlanet);
        this->numObj = numObj;
        for (int i=0;i<numObj;i++) {
            this->spaceObjects[i]=spaceObjects[i];
        }
    }

    Alien(const Alien &a) {
        strcpy(this->name, a.name);
        this->age = a.age;
        strcpy(this->homePlanet, a.homePlanet);
        this->numObj = a.numObj;
        for (int i=0;i<a.numObj;i++) {
            this->spaceObjects[i]=a.spaceObjects[i];
        }
    }

    SpaceObject getObjectClosestToEarth() {
        int min=spaceObjects[0].getDistanceFromEarth();
        int index=0;
        for (int i=0;i<numObj;i++) {
            if (spaceObjects[i].getDistanceFromEarth()<min) {
                min=spaceObjects[i].getDistanceFromEarth();
                index=i;
            }
        }
        return spaceObjects[index];


    }

    void print() {
        cout<<"Alien name: "<<name<<endl;

        cout<<"Alien age: "<<age<<endl;

        cout<<"Alien homePlanet: "<<homePlanet<<endl;

        cout<<"Favourite space object closest to earth: "<<endl;
        getObjectClosestToEarth().print();
    }
};

int main() {
    char name[100], homePlanet[100];
    int age, numObj;
    cin >> name >> age >> homePlanet >> numObj;
    //Testing default constructor for SpaceObject
    SpaceObject spaceObjects[numObj];
    for (int i = 0; i < numObj; i++) {
        char spaceObjectName[100], spaceObjectType[100];
        int distanceFromEarth;
        cin >> spaceObjectName >> spaceObjectType >> distanceFromEarth;
        //Testing constructor with arguments for SpaceObject
        spaceObjects[i] = SpaceObject(spaceObjectName, spaceObjectType, distanceFromEarth);
    }
    //Testing default constructor for Alien
    Alien alien;
    //Testing constructor with arguments for Alien and copy constructor for Alien
    alien = Alien(name, age, homePlanet, numObj, spaceObjects);
    Alien alien2 = Alien(alien);

    alien2.print();
    return 0;
}
*/
/*
#include <iostream>
#include <cstring>
using namespace std;
class LibraryMember;
class Library;
class Book {
private:
    char ime[100];
    char avtor[100];
    bool dostapna=false;
public:
    Book() {
        strcpy(this->ime,"");
        strcpy(this->avtor,"");
        this->dostapna=false;


    }

    Book( char ime[100],char avtor[100],bool dostapna=false) {
        strcpy(this->ime,ime);
        strcpy(this->avtor,avtor);
        this->dostapna=dostapna;
    }

    Book( const Book &b) {
        strcpy(this->ime,b.ime);
        strcpy(this->avtor,b.avtor);
        this->dostapna=b.dostapna;
    }
    ~Book() {

    }
friend class Library;
    friend void checkOutBook(LibraryMember m, Library &l, int index);

};
class Library {
private:
    char ime[100];
    int brknigi;
    Book books[100];
public:
    Library() {
        strcpy(this->ime,"BrakaMiladinovci");
        this->brknigi=0;
        for (int i=0;i<brknigi;i++) {
            this->books[i]=books[i];
        }

    }
    Library( char ime[100],int brknigi,Book books[100]) {
        strcpy(this->ime,ime);
        this->brknigi=brknigi;
        for (int i=0;i<brknigi;i++) {
            this->books[i]=books[i];
        }

    }

    Library( const Library &l) {
        strcpy(this->ime,l.ime);
        this->brknigi=l.brknigi;
        for (int i=0;i<l.brknigi;i++) {
            this->books[i]=l.books[i];
        }

    }
    ~Library() {
    }
        void addBook(Book b) {
            books[brknigi] = b;
            brknigi++;
        }
    friend class LibraryMember;
    friend void checkOutBook(LibraryMember m, Library &l, int index);

    void print() {
        cout << "Library: " << ime << endl;
        cout << "Books: " << brknigi << endl;

        for (int i = 0; i < brknigi; i++) {
            cout << i << ". " << books[i].ime << " - "
                 << books[i].avtor << " ("
                 << (books[i].dostapna ? "Available" : "Not available")
                 << ")" << endl;
        }
    }
};
class LibraryMember {
private:
    char ime[100];
    int id;
public:
    LibraryMember() {
        strcpy(this->ime,"");
        this->id=0;
    }

    LibraryMember(char ime[100],int id) {
        strcpy(this->ime,ime);
        this->id=id;
    }
    LibraryMember(const LibraryMember &m) {
        strcpy(this->ime,m.ime);
        this->id=m.id;
    }

    friend void checkOutBook(LibraryMember m, Library &l, int index);
};
void checkOutBook(LibraryMember m, Library &l, int index) {
    if (index < 0 || index >= l.brknigi) {
        cout << "Invalid index!" << endl;
        return;
    }

    if (l.books[index].dostapna) {
        l.books[index].dostapna = false;
        cout << "Book borrowed successfully!" << endl;
    } else {
        cout << "Book is not available!" << endl;
    }
}
int main() {
    Library lib;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ime[100], avtor[100];
        cin >> ime >> avtor;

        Book b(ime, avtor, true);
        lib.addBook(b);
    }

    lib.print();

    char memberName[100];
    int id;
    cin >> memberName >> id;

    LibraryMember m(memberName, id);

    int index;
    cin >> index;

    checkOutBook(m, lib, index);

    return 0;
}
*/

/*
#include <iostream>
#include <cstring>
using namespace std;

class FoodProduct {
private:
    char ime[50];
    int kolicina;
    int cena;

public:
    FoodProduct() {
        strcpy(this->ime, "");
        this->kolicina = 0;
        this->cena = 0;
    }

    FoodProduct(char ime[50], int kolicina, int cena) {
        strcpy(this->ime, ime);
        this->kolicina = kolicina;
        this->cena = cena;
    }

    FoodProduct(const FoodProduct &f) {
        strcpy(this->ime, f.ime);
        this->kolicina = f.kolicina;
        this->cena = f.cena;
    }

    ~FoodProduct() {
    }

    void print() {
        cout << "Name: " << ime << endl;
        cout << "Amount available: " << kolicina << endl;
        cout << "Price: " << cena << endl;
    }

    friend class Menu;
};

class Menu {
private:
    char ime[50];
    int brprodukti;
    FoodProduct foodproducts[50];

public:
    Menu() {
        strcpy(ime, "");
        this->brprodukti = 0;
        for (int i = 0; i < brprodukti; i++) {
            foodproducts[i] = foodproducts[i];
        }
    }

    Menu(char ime[50]) {
        strcpy(this->ime, ime);
        this->brprodukti = 0;
        for (int i = 0; i < brprodukti; i++) {
            this->foodproducts[i] = foodproducts[i];
        }
    }

    Menu(const Menu &m) {
        strcpy(this->ime, m.ime);
        this->brprodukti = m.brprodukti;
        for (int i = 0; i < brprodukti; i++) {
            this->foodproducts[i] = m.foodproducts[i];
        }
    }

    ~Menu() {
    }

    int getBrprodukti() {
        return brprodukti;
    }

    void setBrprodukti(int brprodukti) {
        this->brprodukti = brprodukti;
    }

    char *getIme() {
        return ime;
    }

    void setIme(char ime[50]) {
        strcpy(this->ime, ime);
    }

    void addProduct(FoodProduct p) {
        if (brprodukti > 50) {
            return;
        }
        foodproducts[brprodukti] = p;
        brprodukti++;
    }

    void print() {
        cout << "Name: " << ime << endl;
        cout << "Products: " << endl;
        for (int i = 0; i < brprodukti; i++) {
            foodproducts[i].print();
        }
    }
    int totalIncome() {
        int total = 0;

        for(int i = 0; i < brprodukti; i++) {
            total += foodproducts[i].kolicina * foodproducts[i].cena;
        }

        return total;
    }
    friend void printWorstMenu(Menu * menus, int n);
};

void printWorstMenu(Menu * menus, int n) {
    int min=menus[0].totalIncome();
    int index=0;
    for (int i=0;i<n;i++) {
        if (menus[i].totalIncome()<min) {
            min=menus[i].totalIncome();
            index=i;
        }

    }
    menus[index].print();



}
int main() {
    int n;
    cin >> n;

    /// BASIC INPUT & ADD PRODUCT
    Menu menus[n];

    for (int i = 0; i < n; i++) {
        int m;
        char name[50];

        cin >> name >> m;
        menus[i] = Menu(name);

        for (int j = 0; j < m; j++) {
            char itemName[50];
            int amount, price;

            cin >> itemName >> amount >> price;

            FoodProduct product(itemName, amount, price);
            menus[i].addProduct(product);
        }
    }

    /// TESTING ADD PRODUCT

    cout << "-- Testing add product & getNumberOfProducts() --\n\n";

    char tempName[50] = "test";
    Menu temp(tempName);

    cout << "Number of products before adding: " << temp.getBrprodukti() << '\n';

    temp.addProduct(FoodProduct(tempName, 0, 0));

    cout << "Number of products after adding: " << temp.getBrprodukti() << '\n';
    temp.print();

    /// TESTING COPY CONSTRUCTOR

    Menu tester(menus[0]);
    std::strcpy(tempName, "Tester Name");
    tester.setIme(tempName);

    cout << "\n-- Testing copy constructor & setName() --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    menus[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    tester.print();

    /// TESTING WORST PRODUCT

    cout << "\n-- Testing printWorstMenu() --\n";
    printWorstMenu(menus, n);
    return 0;
}
*/


#include <iostream>
#include <cstring>
using namespace std;

class Achievement {
private:
    char name[100];
    char description[100];
    int static totalUserAchievements;

public:
    Achievement() {
        strcpy(this->name, "");
        strcpy(this->description, "");
    }

    Achievement(char name[100], char description[100]) {
        strcpy(this->name, name);
        strcpy(this->description, description);
    }

    Achievement(Achievement &a) {
        strcpy(this->name, a.name);
        strcpy(this->description, a.description);
        this->totalUserAchievements = a.totalUserAchievements;
    }

    ~Achievement() {
    }
    char* getDescription() {
        return description;

    }
    char* getName() {
        return name;

    }
    void print() {
        cout << name << endl;
        cout << totalUserAchievements << endl;
    }

    static void incrementTotalUserAchievements() {
        totalUserAchievements++;
    }
    friend class UserProfile;
};

class UserProfile {
private:
    char name[100];
    Achievement achievements[50];
    int n;

public:
    UserProfile() {
        strcpy(this->name, "");
        for (int i = 0; i < n; i++) {
            this->achievements[i] = Achievement();
        }
        this->n = 0;
    }


    UserProfile(char name[100]) {
        strcpy(this->name, name);
        for (int i = 0; i < n; i++) {
            this->achievements[i] = Achievement();
        }
        this->n = n;
    }

      UserProfile(const UserProfile &u) {
        strcpy(this->name, u.name);
        for (int i = 0; i < n; i++) {
            this->achievements[i] = u.achievements[i];
        }
        this->n = u.n;
    }

    ~UserProfile() {
    }

    void print() {
        cout << name << endl;
        for (int i = 0; i < n; i++) {
            achievements[i].print();
        }
    }

     void addAchievement(const Achievement &a) {
        achievements[n++] = a;
Achievement::incrementTotalUserAchievements();    }
    friend void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m);
};

void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m){
    int totalUserAchievements=0;
    for(int i=0;i<m;i++){
        int brojac=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<profiles[j].n;k++){
                if(strcmp(achievements[i].getName(),profiles[j].achievements[k].getName())==0){
                    brojac++;
                    break;
                }
            }
        }
        double procent=(brojac* 100.0) /n;
        cout<<achievements[i].getName()<<endl;
        cout<<achievements[i].getDescription()<<endl;
        cout<<"---Percentage of users who have this achievement: "<<procent<<"%"<<endl;
        totalUserAchievements+=brojac;
    }
    double average=totalUserAchievements * 100.0 / (n * m);
    cout<<"------Average completion rate of the game: "<<average<<"%"<<endl;
}
int Achievement::totalUserAchievements=0;
int main() {
    char testcase[100];
    cin.getline(testcase, 100);

    int n;
    cin >> n;
    cin.ignore();

    char ignore[100];
    cin.getline(ignore, 100);
    UserProfile users[100];
    for (int i = 0; i < n; ++i) {
        char name[100];
        cin >> name;
        users[i] = UserProfile(name);
    }

    int m;
    cin >> m;
    cin.ignore();

    cin.getline(ignore, 100);
    Achievement achievements[100];
    for (int i = 0; i < m; ++i) {
        char name[100], description[100];
        cin.getline(name, 100);
        cin.getline(description, 100);
        achievements[i] = Achievement(name, description);
    }

    int k;
    cin >> k;
    cin.ignore();

    cin.getline(ignore, 100);
    for (int i = 0; i < k; ++i) {
        int numUser, numAchievement;
        cin >> numUser >> numAchievement;
        numUser -= 1;
        numAchievement -= 1;
        users[numUser].addAchievement(achievements[numAchievement]);
    }

    if (testcase[8] == 'A') {
        // Testing Achievement methods.
        for (int i = 0; i < m; ++i) {
            achievements[i].print();
        }
        Achievement::incrementTotalUserAchievements();
    } else if (testcase[8] == 'U') {
        // Testing UserProfile methods.
        for (int i = 0; i < n; ++i) {
            users[i].print();
        }
    } else {
        // Testing showAchievementsProgress function.
        showAchievementsProgress(users, n, achievements, m);
    }

    return 0;
}
