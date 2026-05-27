#include<iostream>
#include <cstring>
using namespace std;

enum Tip { LINUX, UNIX, WINDOWS };

class OperativenSistem {
private:
    char *ime;
    float verzija;
    Tip type;
    float golemina;

public:
    OperativenSistem() {
        this->ime = new char[strlen(ime) + 1];
        strcpy(ime, "");
        this->verzija = 0;
        this->type = LINUX;
        this->golemina = 0;
    }

    OperativenSistem(char *ime, float verzija, Tip type, float golemina) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->type = type;
        this->golemina = golemina;
    }


    OperativenSistem(const OperativenSistem &o) {
        this->ime = new char[strlen(o.ime) + 1];
        strcpy(this->ime, o.ime);
        this->verzija = o.verzija;
        this->type = o.type;
        this->golemina = o.golemina;
    }

    OperativenSistem &operator=(const OperativenSistem &o) {
        if (this != &o) {
            delete [] ime;
            this->ime = new char[strlen(o.ime) + 1];
            strcpy(this->ime, o.ime);
            this->verzija = o.verzija;
            this->type = o.type;
            this->golemina = o.golemina;
        }
        return *this;
    }

    ~OperativenSistem() {
        delete [] ime;
    }


    void pecati() {
        cout << "Ime: " << ime << " Verzija: " << verzija << " Tip: " << type << "Golemina:" << golemina << "GB" <<
                endl;
    }

    bool ednakviSe(const OperativenSistem &os) {
        if (strcmp(ime, os.ime) == 0) {
            if (verzija == os.verzija) {
                if (golemina == os.golemina) {
                    if (type == os.type) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (verzija == os.verzija) {
            return 0;
        } else if (verzija < os.verzija) {
            return -1;
        } else {
            return 1;
        }
    }

    bool istaFamilija(const OperativenSistem &sporedba) {
        if (strcmp(ime, sporedba.ime) == 0) {
            if (type == sporedba.type) {
                return true;
            }
        }
        return false;
    }

    friend class Repozitorium;
};


class Repozitorium {
private:
    char ime[20];
    OperativenSistem *operativenSistems;
    int broj;

public:
    Repozitorium() {
        strcpy(this->ime, "");
        this->operativenSistems = nullptr;
        this->broj = 0;
    }

    Repozitorium(char ime[20]) {
        strcpy(this->ime, ime);
        this->broj = broj;
        this->operativenSistems = nullptr;
    }

    Repozitorium(const Repozitorium &r) {
        strcpy(this->ime, r.ime);
        this->broj = r.broj;
        this->operativenSistems = new OperativenSistem[r.broj + 1];
        for (int i = 0; i < r.broj; i++) {
            this->operativenSistems[i] = r.operativenSistems[i];
        }
    }

    Repozitorium &operator=(const Repozitorium &r) {
        if (this != &r) {
            delete [] operativenSistems;
            strcpy(this->ime, r.ime);
            this->broj = r.broj;
            this->operativenSistems = new OperativenSistem[r.broj + 1];
            for (int i = 0; i < r.broj; i++) {
                operativenSistems[i] = r.operativenSistems[i];
            }
        }
        return *this;
    }

    ~Repozitorium() {
        delete [] operativenSistems;
    }

    void pecatiOperativniSistemi() {
        for (int i = 0; i < broj; i++) {
            operativenSistems[i].pecati();
        }
    }

    void dodadi(const OperativenSistem &nov) {
        for (int i = 0; i < broj; i++) {
            if (operativenSistems[i].istaFamilija(nov)) {
                if (operativenSistems[i].sporediVerzija(nov) == -1) {
                    operativenSistems[i] = nov;
                    return;
                }
            }
        }

        OperativenSistem *tmp = new OperativenSistem[broj + 1];
        for (int i = 0; i < broj; i++) {
            tmp[i] = operativenSistems[i];
        }
        tmp[broj] = nov;

        delete [] operativenSistems;
        operativenSistems = tmp;
        broj++;
    }

    void izbrishi(const OperativenSistem &operativenSistem) {
        for (int i = 0; i < broj; i++) {
            if (operativenSistems[i].ednakviSe(operativenSistem)) {
                for (int j = i; j < broj - 1; j++) {
                    operativenSistems[j] = operativenSistems[j + 1];
                }
                broj--;
                return;
            }
        }
    }
};

int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
