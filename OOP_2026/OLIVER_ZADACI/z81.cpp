#include <iostream>
#include<fstream>
using namespace std;
class NoProductFoundException {
protected:
    string category;
public:
    NoProductFoundException(){

    }
    NoProductFoundException(string &category){
        this->category=category;
    }
    string message(){
        return "No products from category "+category+" were found in the store";
    }
};
class Product {
protected:
    string ime;
    string kategorija;
    int cena;
    int kolicina;

public:
    Product() {
        this->ime = "";
        this->kategorija = "";
        this->cena = 0;
        this->kolicina = 0;
    }

    Product(string ime, string kategorija, int cena, int kolicina) {
        this->ime = ime;
        this->kategorija = kategorija;
        this->cena = cena;
        this->kolicina = kolicina;
    }

    Product(const Product &p) {
        this->ime = p.ime;
        this->kategorija = p.kategorija;
        this->cena = p.cena;
        this->kolicina = p.kolicina;
    }

    friend ostream &operator <<(ostream &pecati, const Product &p) {
        pecati << p.ime << " " << p.kategorija << " " << p.cena << " " << p.kolicina << endl;
        return pecati;
    }

    int vkupna() {
        return cena * kolicina;
    }
    string getCategory() {
        return kategorija;
    }
};

class Store {
protected:
    int golemina;
    Product *products;

public:
    Store() {
        this->golemina = 0;
        this->products = nullptr;
    }

    Store(int golemina, Product *products) {
        this->golemina = golemina;
        this->products = new Product[golemina];
        for (int i = 0; i < golemina; i++) {
            this->products[i] = products[i];
        }
    }

    Store(const Store &s) {
        this->golemina = s.golemina;
        this->products = new Product[s.golemina];
        for (int i = 0; i < s.golemina; i++) {
            this->products[i] = s.products[i];
        }
    }

    Store &operator==(const Store &s) {
        if (this != &s) {
            delete [] products;
            this->golemina = s.golemina;
            this->products = new Product[s.golemina];
            for (int i = 0; i < s.golemina; i++) {
                this->products[i] = s.products[i];
            }
        }
        return *this;
    }

    ~Store() {
        delete [] products;
    }

    Store operator +=(const Product &p) {
        Product *temp = new Product[golemina + 1];
        for (int i = 0; i < golemina; i++) {
            temp[i] = products[i];
        }
        temp[golemina] = p;
        golemina++;
        delete [] products;
        products = temp;
        return *this;
    }

    friend ostream &operator <<(ostream &pecati, const Store &s) {
        for (int i = 0; i < s.golemina; i++) {
            pecati << s.products[i];
        }
        return pecati;
    }

    Store fromCategory(string &category) {
        Store nov;
        for (int i = 0; i < golemina; i++) {
            if (products[i].getCategory() ==category) {
                nov+=products[i];
            }
        }
        if(nov.golemina==0){
            throw NoProductFoundException(category);
        }
    }
};

int main() {
    ifstream dat1("input.txt");
    if(!dat1){
        cout<<"Ne postoi datoteka input.txt"<<endl;
        return -1;
    }
    ofstream dat2("output1.txt");
    ofstream dat3("output2.txt");
    string ime;
    string kategorija;
    int cena;
    int kolicina;
    string novakategorija;
    Store store;
    while(true){
        if(!getline(dat1,ime)){
            break;
        }
        if(!getline(dat1,kategorija)){
            break;
        }
        if(!(dat1>>cena)){
            break;
        }
        if(!(dat1>>kolicina)){
            break;
        }
        dat1.ignore();
        store+=Product(ime,kategorija,cena,kolicina);
    }
    dat1.clear();
    dat1.seekg(0,ios::beg);//zaradi znakot sto se cita od datotekata ----
    while(getline(dat1,ime)){
        novakategorija=ime;
    }
    dat2<<"Site Produkti:"<<endl;
    dat2<<store;
    try{
        Store kategorijaStore=store.fromCategory(novakategorija);
        dat3<<"Produkti od kategorija "<<novakategorija<<" :"<<endl;
        dat3<<kategorijaStore;
    }catch(NoProductFoundException &e){
        dat3<<e.message()<<endl;
    }
    dat1.close();
    dat2.close();
    dat3.close();
}
