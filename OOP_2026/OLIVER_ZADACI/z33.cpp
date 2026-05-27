#include <iostream>
#include <cstring>
using namespace std;

class Pica {
private:
    char ime[20];
    int cena;
    char *sostojki;
    int popust;

public:
    Pica() {
        strcpy(this->ime, "");
        this->cena = 0;
        strcpy(this->sostojki, "");
        this->popust = 0;
    }

    Pica(char ime[20], int cena, char *sostojki, int popust) {
        strcpy(this->ime, ime);
        this->cena = cena;
        this->sostojki = new char[strlen(sostojki) + 1];
        strcpy(this->sostojki, sostojki);
        this->popust = popust;
    }

    Pica(const Pica &p) {
        strcpy(this->ime, p.ime);
        this->cena = p.cena;
        this->sostojki = new char[strlen(p.sostojki) + 1];
        strcpy(this->sostojki, p.sostojki);
        this->popust = p.popust;
    }

    Pica& operator=(const Pica &p) {
        if (this != &p) {
            delete [] sostojki;
            strcpy(this->ime, p.ime);
            this->cena = p.cena;
            this->sostojki = new char[strlen(p.sostojki) + 1];
            strcpy(this->sostojki, p.sostojki);
            this->popust = p.popust;
        }
        return *this;
    }

    ~Pica() {
        delete [] sostojki;
    }

    void print() {
        cout << ime << "-" << sostojki << "," << cena << "." << endl;
    }

    bool istiSe(Pica p) {
        return strcmp(this->sostojki, p.sostojki) == 0;
    }
    friend class Picerija;
};

class Picerija {
private:
    char ime[20];
    Pica *pici;
    int brojpici;

public:
    Picerija() {
        strcpy(this->ime, "");
        this->pici = 0;
        this->brojpici = 0;
    }

    Picerija(char ime[20]) {
        strcpy(this->ime, ime);
        this->pici = nullptr;
        this->brojpici = 0;
    }

    Picerija(const Picerija &i) {
        strcpy(this->ime, i.ime);
        this->brojpici = i.brojpici;
        if (i.brojpici > 0) {
            this->pici = new Pica[i.brojpici];
            for (int s = 0; s < i.brojpici; s++) {
                this->pici[s] = i.pici[s];
            }
        } else {
            this->pici = nullptr;
        }
    }


    Picerija& operator=(const Picerija &i) {
        if (this != &i) {
            delete [] pici;
            strcpy(this->ime, i.ime);
            this->brojpici = i.brojpici;
            if (i.brojpici > 0) {
                this->pici = new Pica[i.brojpici];
                for (int s = 0; s < i.brojpici; s++) {
                    this->pici[s] = i.pici[s];
                }
            } else {
                this->pici = nullptr;
            }
        }
        return *this;
    }

    ~Picerija() {
        delete [] pici;
    }

    void dodadi(Pica &P) {
    for (int i = 0; i < brojpici; i++) {
        if (pici[i].istiSe(P)) {
            return;
        }
    }

    // нова низа
    Pica *tmp = new Pica[brojpici + 1];

    // копирање
    for (int i = 0; i < brojpici; i++) {
        tmp[i] = pici[i];
    }

    // додавање
    tmp[brojpici] = P;

    // бришење стара
    delete [] pici;

    // ажурирање
    pici = tmp;
    brojpici++;
}
    void setIme(char ime[]) {
        strcpy(this->ime,ime);
    }
    char* getIme() {
        return ime;
    }

    void piciNaPromocija() {
        for (int i = 0; i < brojpici; i++) {
            if (pici[i].popust > 0) {

                int novaCena = pici[i].cena - (pici[i].cena * pici[i].popust / 100);

                cout << pici[i].ime << " - "
                     << pici[i].sostojki << ", "
                     << pici[i].cena << " "
                     << novaCena << endl;
            }
        }
    }
};

int main() {
    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++) {
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2.dodadi(p);

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}
