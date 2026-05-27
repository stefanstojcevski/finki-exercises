/*
 *(1) Да се дефинира класа FoodProduct во која ќе се чуваат информации за:

Име на продуктот (низа од карактери со максимална должина 50)
Количина на продуктот (int)
Цена на продуктот (int)
Класата треба да ги има следните методи:
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////////////////////////
конструктор (default, copy и со параметри)
set и get методи за количина и цена
print() метод
Печатењето да е според следниот формат:
Name: [Name of product]
Amount available: [Amount]
Price: [Price of product]
///////////////////////////////////////////////
При што вредностите во [] треба да се заменат со вредностите во класата!

(2) Следно треба да се имплементира класата Menu која ќе ги чува следните информации:

Име на ресторанот (низа од карактери со максимална должина 50)
Број на продукти (int)
Низа од продукти (низа од FoodProduct со максимална должина 50)
///////////////////////////////////////////////////
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
 …
[Product N]

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

 *
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
        strcpy(this->ime,"");
        this->kolicina=0;
       this->cena=0;
    }
    FoodProduct( char ime[50],int kolicina,int cena ) {
        strcpy(this->ime,ime);
        this->kolicina=kolicina;
        this->cena=cena;
    }
    ~FoodProduct() {

    }
    int getKolicina(){
    return kolicina;
    }
    int getCena(){
        return cena;
    }


    void print() {
        cout<<"Name: "<<ime<<endl;
        cout<<"Amount available: "<<kolicina<<endl;
        cout<<"Price: "<<cena<<endl;
    }

};
class  Menu {
private:
    char imeR[50];
    int produkt;
    FoodProduct foodproducts[50];
public:
    Menu() {
        strcpy(this->imeR,"");
        this->produkt=0;

    }
    Menu(char imeR[50],int produkt){
    FoodProduct foodproducts[50];
        strcpy(this->imeR,imeR);
        this->produkt=produkt;
        }
    ~Menu() {

    }
    char* getIme() {
        return imeR;
    }

    int getbroj() {
        return produkt;
    }

    void addProduct(FoodProduct p) {

    }
    void print() {

    }
};
    int main() {
        int n;
        cin >> n;

        /// BASIC INPUT & ADD PRODUCT
        Menu menus[n];

        for(int i = 0; i < n; i++) {
            int m;
            char name[50];

            cin >> name >> m;
            menus[i] = Menu(imeR);

            for(int j = 0; j < m; j++) {
                char itemName[50];
                int amount, price;

                cin >> itemName >> amount >> price;

                FoodProduct product(itemName, amount, price);
                menus[i].addProduct(product);
            }
        }
    }