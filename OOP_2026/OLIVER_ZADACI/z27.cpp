/*
 *(1) Да се дефинира класа FoodProduct во која ќе се чуваат информации за:

Име на продуктот (низа од карактери со максимална должина 50)
Количина на продуктот (int)
Цена на продуктот (int)
Класата треба да ги има следните методи:
конструктор (default, copy и со параметри)
set и get методи за количина и цена
print() метод
Печатењето да е според следниот формат:
Name: [Name of product]
Amount available: [Amount]
Price: [Price of product]
При што вредностите во [] треба да се заменат со вредностите во класата!
(2) Следно треба да се имплементира класата Menu која ќе ги чува следните информации:
Име на ресторанот (низа од карактери со максимална должина 50)
Број на продукти (int)
Низа од продукти (низа од FoodProduct со максимална должина 50)
За класата да се имплементираат следните методи:
Конструктор (default, copy и конструктор со еден параметар за име)
Set и get методи (за името на ресторанот и бројот на продукти)
void addProduct(FoodProduct p) - додава продукт во низата, при што не може да се додат повеќе од 50 продукти во низата
print() метод
Печатењето да е според следниот формат:
Name: [Name of restaurant]
Products:
[Product 1]
[Product 2]
 …[Product N]
При што вредностите во [] треба да се заменат со вредностите во класата!
int totalIncome() - која ќе го враќа збирот на заработувачката на секој продукт, така што заработувачката на продуктот е производ од неговата количина и цена (income = amount * price)
(3) Надвор од класата треба да се напише следната функција:
void printWorstMenu(Menu * menus, int n) - од дадените n менија го печати менито со најмала вкупна заработувачка

!!! ДА НЕ СЕ ПРАВАТ ПРОМЕНИ ВО MAIN() ФУНКЦИЈАТА !!!

For example:
Input
2
Los_Pollos_Hermanos 2
Fried_Chicken 10 5
Sugar 10 5000
Madzo3.0 1
Burger 10 350

Result
-- Testing add product & getNumberOfProducts() --

Number of products before adding: 0
Number of products after adding: 1
Name: test
Products:
Name: test
Amount available: 0
Price: 0

-- Testing copy constructor & setName() --
-------------
Source:
-------------
Name: Los_Pollos_Hermanos
Products:
Name: Fried_Chicken
Amount available: 10
Price: 5
Name: Sugar
Amount available: 10
Price: 5000

-------------
Copied and edited:
-------------
Name: Tester Name
Products:
Name: Fried_Chicken
Amount available: 10
Price: 5
Name: Sugar
Amount available: 10
Price: 5000

-- Testing printWorstMenu() --
Name: Madzo3.0
Products:
Name: Burger
Amount available: 10
Price: 350

//DO NOT CHANGE main() FUNCTION

int main() {
    int n;
    cin >> n;

    /// BASIC INPUT & ADD PRODUCT
    Menu menus[n];

    for(int i = 0; i < n; i++) {
        int m;
        char name[50];

        cin >> name >> m;
        menus[i] = Menu(name);

        for(int j = 0; j < m; j++) {
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

    cout << "Number of products before adding: " << temp.getNumberOfProducts() << '\n';

    temp.addProduct(FoodProduct(tempName, 0, 0));

    cout << "Number of products after adding: " << temp.getNumberOfProducts() << '\n';
    temp.print();

    /// TESTING COPY CONSTRUCTOR

    Menu tester(menus[0]);
    std::strcpy(tempName, "Tester Name");
    tester.setName(tempName);

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






*(1) Да се дефинира класа FoodProduct во која ќе се чуваат информации за:

Име на продуктот (низа од карактери со максимална должина 50)
Количина на продуктот (int)
Цена на продуктот (int)
Класата треба да ги има следните методи:
конструктор (default, copy и со параметри)
set и get методи за количина и цена
print() метод
Печатењето да е според следниот формат:
Name: [Name of product]
Amount available: [Amount]
Price: [Price of product]
При што вредностите во [] треба да се заменат со вредностите во класата!
(2) Следно треба да се имплементира класата Menu која ќе ги чува следните информации:
Име на ресторанот (низа од карактери со максимална должина 50)
Број на продукти (int)
Низа од продукти (низа од FoodProduct со максимална должина 50)
За класата да се имплементираат следните методи:
Конструктор (default, copy и конструктор со еден параметар за име)
Set и get методи (за името на ресторанот и бројот на продукти)
void addProduct(FoodProduct p) - додава продукт во низата, при што не може да се додат повеќе од 50 продукти во низата
print() метод
Печатењето да е според следниот формат:
Name: [Name of restaurant]
Products:
[Product 1]
[Product 2]
 …[Product N]
При што вредностите во [] треба да се заменат со вредностите во класата!
int totalIncome() - која ќе го враќа збирот на заработувачката на секој продукт, така што заработувачката на продуктот е производ од неговата количина и цена (income = amount * price)
(3) Надвор од класата треба да се напише следната функција:
void printWorstMenu(Menu * menus, int n) - од дадените n менија го печати менито со најмала вкупна заработувачка
}

 **/
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
        strcpy(ime, " ");
        this->kolicina = 0;
        this->cena = 0;
    }

    FoodProduct(char ime[50], int kolicina, int cena) {
        strcpy(this->ime, ime);
        this->kolicina = kolicina;
        this->cena = cena;
    }

    FoodProduct(const FoodProduct &p) {
        strcpy(this->ime, p.ime);
        this->kolicina = p.kolicina;
        this->cena = p.cena;
    }

    ~FoodProduct() {
    }

    int getKolicina() {
        return kolicina;
    }

    int getCena() {
        return cena;
    }

    void print() {
        cout << "Name: " << ime << endl;
        cout << "Amount available: " << kolicina << endl;
        cout << "Price: " << cena << endl;
    }
};

class Menu {
private:
    char ime[50];
    int brojprodukti;
    FoodProduct foodProducts[50];

public:
    Menu() {
        strcpy(this->ime, " ");
        this->brojprodukti = 0;
    }

    Menu(char ime[50]) {
        strcpy(this->ime, ime);
        this->brojprodukti = 0;
    }

    Menu(const Menu &m) {
        strcpy(this->ime, m.ime);
        this->brojprodukti = m.brojprodukti;
        for (int i = 0; i < m.brojprodukti; i++) {
            this->foodProducts[i] = m.foodProducts[i];
        }
    }

    void addProduct(FoodProduct p) {
        if (brojprodukti < 50) {
            foodProducts[brojprodukti] = p;
            brojprodukti++;
        }
    }

int totalIncome() {
        int zbir=0;
        for(int i = 0; i < brojprodukti; i++) {
            zbir += foodProducts[i].getCena() * foodProducts[i].getKolicina();
        }

        return zbir;
}


char *getIme() {
    return ime;
}

int getNumberOfProducts() {
    return brojprodukti;
}
    void setName(char name[50]) {
        strcpy(this->ime, name);
    }

    void print() {
        cout << "Name: " << ime << endl;
        cout << "Products:" << endl;

        for(int i = 0; i < brojprodukti; i++) {
            foodProducts[i].print();
        }
    }

};

void printWorstMenu(Menu *menus, int n) {

    int index = 0;
    int minIncome = menus[0].totalIncome();

    for(int i = 1; i < n; i++) {

        if(menus[i].totalIncome() < minIncome) {
            minIncome = menus[i].totalIncome();
            index = i;
        }
    }

    menus[index].print();
}

using namespace std;

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

    cout << "Number of products before adding: " << temp.getNumberOfProducts() << '\n';

    temp.addProduct(FoodProduct(tempName, 0, 0));

    cout << "Number of products after adding: " << temp.getNumberOfProducts() << '\n';
    temp.print();

    /// TESTING COPY CONSTRUCTOR

    Menu tester(menus[0]);
    std::strcpy(tempName, "Tester Name");
    tester.setName(tempName);

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
