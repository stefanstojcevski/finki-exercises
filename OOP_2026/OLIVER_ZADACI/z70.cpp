#include <iostream>
#include<cstring>
using namespace std;

class Vozilo {
protected:
    float masa;
    int shirina;
    int visina;

public:
    Vozilo() {
        this->masa = 0;
        this->shirina = 0;
        this->visina = 0;
    }

    Vozilo(float masa, int shirina, int visina) {
        this->masa = masa;
        this->shirina = shirina;
        this->visina = visina;
    }

    Vozilo(const Vozilo &v) {
        this->masa = v.masa;
        this->shirina = v.shirina;
        this->visina = v.visina;
    }
    virtual ~Vozilo() {}

    float masa1() {
        return masa;
    }

    int shirina1() {
        return shirina;
    }

    virtual int vratiDnevnaCena() = 0;
};


class Avtomobil : public Vozilo {
protected:
    int brvrati;

public:
    Avtomobil() {
        this->brvrati = 0;
    }

    Avtomobil(float masa, int shirina, int visina, int brvrati) : Vozilo(masa, shirina, visina) {
        this->brvrati = brvrati;
    }

    Avtomobil(const Avtomobil &a) : Vozilo(a) {
        this->brvrati = a.brvrati;
    }
    int vratiDnevnaCena() {
        if (brvrati<5) {
            return 100;
        }
        return 130;
    }
};


class Avtobus : public Vozilo {
protected:
    int brpatnici;

public:
    Avtobus() {
        this->brpatnici = 0;
    }

    Avtobus(float masa, int shirina, int visina,int brpatnici) : Vozilo(masa, shirina, visina) {
        this->brpatnici = brpatnici;
    }

    Avtobus(const Avtobus &s) : Vozilo(s) {
        this->brpatnici = s.brpatnici;
    }

    int vratiDnevnaCena() {
        return brpatnici*5;
    }
};


class Kamion : public Vozilo {
protected:
    double brtovar;

public:
    Kamion() {
        this->brtovar = 0;
    }

    Kamion(float masa, int shirina, int visina,int brpatnici) : Vozilo(masa, shirina, visina) {
        this->brtovar = brpatnici;
    }

    Kamion(const Kamion &k) : Vozilo(k) {
        this->brtovar = k.brtovar;
    }

     double brtovar1() {
        return brtovar;
    }

    int vratiDnevnaCena() {
        return  (masa+brtovar)*0.02;
    }
};

class ParkingPlac {
protected:
    Vozilo **vozila;
    int broj;

public:
    ParkingPlac() {
        this->vozila = nullptr;
        this->broj = 0;
    }

    ParkingPlac(const ParkingPlac &p) {
        this->broj = p.broj;
        this->vozila = new Vozilo *[p.broj];
        for (int i = 0; i < p.broj; i++) {
            this->vozila[i] = p.vozila[i];
        }
    }

    ParkingPlac &operator +=(Vozilo *p) {
        Vozilo **temp = new Vozilo *[broj + 1];
        for (int i = 0; i < broj; i++) {
            temp[i] = vozila[i];
        }
        temp[broj] = p;
        broj++;
        delete [] vozila;
        vozila = temp;
        return *this;
    }

    float presmetajVkupnaMasa() {
        float zbir = 0;
        for (int i = 0; i < broj; i++) {
            zbir += vozila[i]->masa1();
        }
        return zbir;
    }

    int brojVozilaPoshirokiOd(int l) {
        int brojac = 0;
        for (int i = 0; i < broj; i++) {
            if (vozila[i]->shirina1() > l) {
                brojac++;
            }
        }
        return brojac;
    }

    void pecati() {
        int avtomobili = 0;
        int avtobusi = 0;
        int kamioni = 0;
        for (int i = 0; i < broj; i++) {
            if (dynamic_cast<Avtomobil *>(vozila[i]) != nullptr) {
                avtomobili++;
            } else if (dynamic_cast<Avtobus *>(vozila[i]) != nullptr) {
                avtobusi++;
            } else if (dynamic_cast<Kamion *>(vozila[i]) != nullptr) {
                kamioni++;
            }
        }


        cout << "Brojot na avtomobili e " << avtomobili << ", brojot na avtobusi e " << avtobusi <<
                " i brojot na kamioni e " << kamioni << "." << endl;
    }

    int pogolemaNosivostOd(Vozilo& v) {
        int tovar=0;
        for (int i = 0; i < broj; i++) {
            Kamion*k=dynamic_cast<Kamion*>(vozila[i]);
            if (k) {
                if (k->brtovar1()>v.masa1()) {
                    tovar++;
                }

                }

            }
        return tovar;
        }

    int vratiDnevnaZarabotka() {
        int zbir=0;
        for (int i = 0; i < broj; i++) {
            zbir+=vozila[i]->vratiDnevnaCena();
        }
        return zbir;
    }

};

int main() {
    ParkingPlac p;

    int n;
    cin >> n;
    int shirina, visina, broj;
    float masa, nosivost;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> masa >> shirina >> visina >> broj;
            Avtomobil *a = new Avtomobil(masa, shirina, visina, broj);
            p += a;
        }
        if (type == 2) {
            cin >> masa >> shirina >> visina >> broj;
            p += new Avtobus(masa, shirina, visina, broj);
        }
        if (type == 3) {
            cin >> masa >> shirina >> visina >> nosivost;
            p += new Kamion(masa, shirina, visina, nosivost);
        }
    }

    p.pecati();

    cout << "\nZarabotkata e " << p.vratiDnevnaZarabotka() << endl;
    cout << "Vkupnata masa e " << p.presmetajVkupnaMasa() << endl;
    cout << "Brojot poshiroki od 5 e " << p.brojVozilaPoshirokiOd(5) << endl;
    Avtomobil a(1200, 4, 3, 5);
    cout << "Brojot na kamioni so nosivost pogolema od avtomobilot e " << p.pogolemaNosivostOd(a) << endl;
}
