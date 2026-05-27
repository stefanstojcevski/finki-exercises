#include <iostream>
using namespace std;
class Rabotnik {
private:
    char ime[30];
    char prezime[30];
    int plata;
public:
    Rabotnik() {
        strcpy(this->ime,"");
        strcpy(this->prezime,"");
        this->plata=0;

    }

    Rabotnik(char ime[30],char prezime[30],int plata) {
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        this->plata=plata;

    }

    Rabotnik(const Rabotnik &r) {
        strcpy(this->ime,r.ime);
        strcpy(this->prezime,r.prezime);
        this->plata=r.plata;

    }

    Rabotnik& operator=(const Rabotnik &r) {
        if (this!=&r) {
            strcpy(this->ime,r.ime);
            strcpy(this->prezime,r.prezime);
            this->plata=r.plata;
        }
        return *this;

    }

    int getPlata() {
        return plata;

    }
    void print() {
        cout<<ime<<" "<<prezime<<" "<<plata<<endl;

    }
    friend class Fabrika;
};
class Fabrika {
private:
    Rabotnik rabotnici[100];
    int brojvraboteni;
public:
    Fabrika() {
        this->brojvraboteni=0;
        for (int i=0;i<brojvraboteni;i++) {
            rabotnici[i]=Rabotnik();
        }
    }

    Fabrika(Rabotnik rabotnici[100],int brojvraboteni) {
        this->brojvraboteni=brojvraboteni;
        for (int i=0;i<brojvraboteni;i++) {
            this->rabotnici[i]=rabotnici[i];
        }
    }

    Fabrika(const Fabrika &f ) {
        this->brojvraboteni=f.brojvraboteni;
        for (int i=0;i<f.brojvraboteni;i++) {
            this->rabotnici[i]=f.rabotnici[i];
        }
    }

    Fabrika operator=(const Fabrika &f ) {
        if (this!=&f) {
            this->brojvraboteni=f.brojvraboteni;
            for (int i=0;i<f.brojvraboteni;i++) {
               this-> rabotnici[i]=f.rabotnici[i];
            }
        }
        return *this;
    }

    void pecatiVraboteni() {
        for (int i=0;i<brojvraboteni;i++) {
            rabotnici[i].print();
        }
    }
    void pecatiSoPlata(int plata) {
        for (int i=0;i<brojvraboteni;i++) {
            if (rabotnici[i].plata>=plata) {
                rabotnici[i].print();

            }
        }
    }




};




int main()
{
    char  ime[20], prezime[20];
    int plata, n;
    cin >> n;
    Rabotnik r[100];
    for(int i = 0; i < n; i++){
        cin  >> ime >> prezime >> plata;
        r[i] = Rabotnik(ime, prezime, plata);
    }
    Fabrika f(r, n);
    int minPlata;
    cin >> minPlata;
    f.pecatiVraboteni();
    f.pecatiSoPlata(minPlata);
    return 0;
}