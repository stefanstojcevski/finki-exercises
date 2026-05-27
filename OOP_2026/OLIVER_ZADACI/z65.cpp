#include <iostream>
#include<cstring>
using namespace std;
class Sneakers {
    protected:
    char model[50];
    int golemina;
    float cena;
public:
    Sneakers() {
        strcpy(this->model,"");
        this->golemina=0;
        this->cena=0;
    }
    Sneakers(char model[50],int golemina,float cena) {
        strcpy(this->model,model);
        this->golemina=golemina;
        this->cena=cena;
    }
    Sneakers(const Sneakers &s) {
        strcpy(this->model,s.model);
        this->golemina=s.golemina;
        this->cena=s.cena;
    }
    Sneakers& operator=(const Sneakers &s) {
        if (this!=&s) {
            strcpy(this->model,s.model);
            this->golemina=s.golemina;
            this->cena=s.cena;
        }
        return *this;
    }
    char *getModel() {
        return model;
    }
    int getGolemina() {
        return golemina;
    }
    float getCena() {
        return cena;
    }
    friend istream& operator>>(istream& vnesi, Sneakers& r) {
        vnesi >> r.model >> r.golemina >> r.cena;
        return vnesi;
    }

    friend ostream& operator<<(ostream& pecati, const Sneakers& r) {
        pecati << r.model << " "
               << r.golemina << " "
               << r.cena << endl;

        return pecati;
    }


friend class SneakersShop;
};
class SneakersShop {
protected:
    char ime[50];
    Sneakers *sneakerss;
    int vkupen;
    int poskapuvajne;
public:
    SneakersShop() {
        strcpy(this->ime,"");
        this->sneakerss=nullptr;
        this->vkupen=0;
        this->poskapuvajne=0;
    }

    SneakersShop( char ime[50],Sneakers *sneakerss,int vkupen,int poskapuvajne) {
        strcpy(this->ime,ime);
        this->vkupen=vkupen;
        this->poskapuvajne=poskapuvajne;
        this->sneakerss = new Sneakers[this->vkupen];
        for (int i=0;i<this->vkupen;i++) {
            this->sneakerss[i]=sneakerss[i];
        }
    }

    SneakersShop( char ime[50]) {
        strcpy(this->ime,ime);
        this->sneakerss=nullptr;
        this->vkupen=0;
        this->poskapuvajne=0;
    }

    SneakersShop( const SneakersShop &n) {
        strcpy(this->ime,n.ime);
        this->vkupen=n.vkupen;
        this->poskapuvajne=n.poskapuvajne;
        this->sneakerss = new Sneakers[this->vkupen];
        for (int i=0;i<this->vkupen;i++) {
            this->sneakerss[i]=n.sneakerss[i];
        }
    }

    SneakersShop& operator=( const SneakersShop &n) {
        if (this!=&n) {
            delete [] sneakerss;
            strcpy(this->ime,n.ime);
            this->vkupen=n.vkupen;
            this->poskapuvajne=n.poskapuvajne;
            for (int i=0;i<this->vkupen;i++) {
                this->sneakerss[i]=n.sneakerss[i];
            }
        }
        return *this;
    }
    ~SneakersShop() {
        delete [] sneakerss;

    }

    SneakersShop& operator+=(const Sneakers &s) {
        Sneakers *temp = new Sneakers[this->vkupen + 1];

        for (int i = 0; i < this->vkupen; i++) {
            temp[i] = this->sneakerss[i];
        }

        temp[this->vkupen] = s;

        delete[] this->sneakerss;

        this->sneakerss = temp;
        this->vkupen++;

        return *this;
    }
    SneakersShop& operator++() {
        for(int i = 0; i < vkupen; i++) {
            sneakerss[i].cena += sneakerss[i].cena * poskapuvajne / 100.0;
        }

        return *this;
    }
    friend class OnlineSneakersShop;

    friend ostream& operator<<(ostream& pecati, const SneakersShop& r) {

        pecati << r.ime << endl;

        for (int i = 0; i < r.vkupen; i++) {
            pecati << r.sneakerss[i];
        }

        return pecati;
    }
};

class OnlineSneakersShop:public SneakersShop {
protected:
    char url[100];
public:
    OnlineSneakersShop() {
       strcpy(this->url,"");
    }

    OnlineSneakersShop(char ime[50],Sneakers *sneakerss,int vkupen,int poskapuvajne,char url[100]):SneakersShop(ime,sneakerss,vkupen,poskapuvajne) {
        strcpy(this->url,url);
    }

    OnlineSneakersShop(char ime[50],char url[100]):SneakersShop(ime) {
        strcpy(this->url,url);
    }

    OnlineSneakersShop(const OnlineSneakersShop &r):SneakersShop(r) {
        strcpy(this->url,r.url);
    }

    OnlineSneakersShop& operator=(const OnlineSneakersShop &r) {
        if (this!=&r) {
            strcpy(this->url,r.url);

            delete [] sneakerss;
            strcpy(this->ime,r.ime);
            this->vkupen=r.vkupen;
            this->poskapuvajne=r.poskapuvajne;
            for (int i=0;i<this->vkupen;i++) {
                this->sneakerss[i]=r.sneakerss[i];
            }




        }
        return *this;
    }
    float checkItemAvailability(char* model, int size) {
        for (int i=0;i<vkupen;i++) {
           if ( strcmp(sneakerss[i].getModel(), model) == 0 ){
                if (sneakerss[i].getGolemina()==size) {
                    float cena = sneakerss[i].getCena();
                    return cena - cena * 10 / 100;
                }
            }
        }
        return 0;
    }

    friend ostream& operator<<(ostream& pecati , const OnlineSneakersShop &r) {
         pecati << r.ime << endl;
        pecati << r.url << endl;

        for (int i = 0; i < r.vkupen; i++) {
            pecati << r.sneakerss[i];
        }

        return pecati;
    }



};























int main() {
      int testCase;
    cin >> testCase;
    char name[100];
    char url[100];

    if (testCase == 1) {
        cout << "TESTING CLASS SneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
    } else if (testCase == 2) {
        cout << "TESTING CLASS OnlineSneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
    } else if (testCase == 3) {
        cout << "TESTING CLASS SneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 4) {
        cout << "TESTING CLASS OnlineSneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 5) {
        cout << "TESTING METHOD checkItemAvailability" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        char model[100];
        int size;
        cin >> model >> size;
        cout << "Price for model " << model << " with size: " << size << " is: "
             << shop->checkItemAvailability(model, size) << endl;
    } else if (testCase == 6) {
        cout << "TESTING OPERATOR ++" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);
    } else if (testCase == 7) {
        cout << "TESTING OPERATOR ++ AND CHANGE OF STATIC MEMBER" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

        cout <<"CHANGING INCREASE PERCENTAGE IN SneakersShop" << endl;
        SneakersShop::setIncreasePercentage(17);

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

    }
}