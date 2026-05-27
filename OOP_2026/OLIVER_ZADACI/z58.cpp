#include <iostream>
#include<cstring>
using namespace std;

class Ekipa {
protected:
    char ime[15];
    int brojporazi;
    int brojpobedi;

public:
    Ekipa() {
        strcpy(this->ime, "");
        this->brojporazi = 0;
        this->brojpobedi = 0;
    }

    Ekipa(char ime[15], int brojporazi, int brojpobedi) {
        strcpy(this->ime, ime);
        this->brojporazi = brojporazi;
        this->brojpobedi = brojpobedi;
    }

    Ekipa(const Ekipa &e) {
        strcpy(this->ime, e.ime);
        this->brojporazi = e.brojporazi;
        this->brojpobedi = e.brojpobedi;
    }

    Ekipa &operator=(const Ekipa &e) {
        if (this != &e) {
            strcpy(this->ime, e.ime);
            this->brojporazi = e.brojporazi;
            this->brojpobedi = e.brojpobedi;
        }
        return *this;
    }

    void pecati() {
        cout << ime << " " << brojporazi << " " << brojpobedi << endl;
    }
};


class FudbalskaEkipa : public Ekipa {
protected:
    int vkupenbrcrveni;
    int vkupenbrzolti;
    int brojnereseni;


public:
    FudbalskaEkipa() {
        this->vkupenbrcrveni = 0;
        this->vkupenbrzolti = 0;
        this-> brojnereseni=0;

    }

    FudbalskaEkipa(char ime[15], int brojpobedi, int brojporazi, int vkupenbrcrveni, int vkupenbrzolti,int brojnereseni) : Ekipa(
        ime, brojporazi, brojpobedi) {
        this->vkupenbrcrveni = vkupenbrcrveni;
        this->vkupenbrzolti = vkupenbrzolti;
        this->brojnereseni = brojnereseni;

    }

    FudbalskaEkipa(const FudbalskaEkipa &f) : Ekipa(f) {
        this->vkupenbrcrveni = f.vkupenbrcrveni;
        this->vkupenbrzolti = f.vkupenbrzolti;
        this-> brojnereseni=f.brojnereseni;

    }

    FudbalskaEkipa &operator=(const FudbalskaEkipa &f) {
        if (this != &f) {
            this->vkupenbrcrveni = f.vkupenbrcrveni;
            this->vkupenbrzolti = f.vkupenbrzolti;
            this-> brojnereseni=f.brojnereseni;


            strcpy(this->ime, f.ime);
            this->brojporazi = f.brojporazi;
            this->brojpobedi = f.brojpobedi;
        }
        return *this;
    }

    void pecati() {
        Ekipa::pecati();
        cout<<brojnereseni<<endl;
        cout<<brojpobedi*3+brojnereseni*1<<endl;



    }

};

int main() {
    char ime[15];
    int pob,por,ck,zk,ner;
    cin>>ime>>pob>>por>>ck>>zk>>ner;
    FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
    f1.pecati();
    return 0;
}
