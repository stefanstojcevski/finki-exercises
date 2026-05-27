#include <iostream>
#include <cstring>
using namespace std;

class ZicanInstrument {
protected:
    char ime[20];
    int brzici;
    float cena;
public:
    ZicanInstrument() {
        strcpy(this->ime,"");
        this->brzici=0;
        this->cena=0;
    }

    ZicanInstrument(char ime[20],int brzici,float cena) {
        strcpy(this->ime,ime);
        this->brzici=brzici;
        this->cena=cena;
    }
    ZicanInstrument(const ZicanInstrument &z) {
        strcpy(this->ime,z.ime);
        this->brzici=z.brzici;
        this->cena=z.cena;
    }
    virtual float pari()=0;
    bool operator==(const ZicanInstrument &z) {
        if (brzici==z.brzici) {
            return true;
        }
        return false;

    }
    friend ostream& operator <<(ostream& pecati,const ZicanInstrument &z) {
        pecati << z.ime << " " << z.brzici << " " << z.cena;
        const Mandolina *m=dynamic_cast<const Mandolina *>(&z);
return pecati;
    }


};

class Mandolina : public ZicanInstrument {
protected:
    char forma[20];
public:
    Mandolina() {
        strcpy(this->forma,"");
    }
    Mandolina( char ime[20],int brzici,float cena, char forma[20]):ZicanInstrument(ime,brzici,cena) {
        strcpy(this->forma,forma);
    }

    Mandolina( const Mandolina &m):ZicanInstrument(m) {
        strcpy(this->forma,m.forma);
    }
    float pari() {
        if (strcmp(forma,"Neapolitan")==0) {
            return cena*1.15;
        }
        return cena;

    }

    char* getForma() {

        return forma;

    }

};


class Violina : public ZicanInstrument {
protected:
    float golemina;
public:
    Violina() {
        this->golemina=0;
    }

    Violina(char ime[20],int brzici,float cena,double golemina):ZicanInstrument(ime,brzici,cena) {
        this->golemina=golemina;
    }
    Violina(const Violina &v):ZicanInstrument(v) {
        this->golemina=v.golemina;
    }
    float pari() {
        if (golemina==0.25) {
            return cena*1.10;
        }
        else if (golemina==1.0) {
            return cena*1.20;
        }
        return cena;

    }
    float getGolemina() {

        return golemina;

    }
};

int main() {
    char ime[20];
    int brojZici;
    float cena;
    char forma[20];
    cin >> ime >> brojZici >> cena >> forma;
    Mandolina m(ime, brojZici, cena, forma);
    int n;
    cin >> n;
ZicanInstrument **zi = new ZicanInstrument*[2 * n];    for(int i = 0; i < n; ++i) {
        cin >> ime >> brojZici >> cena >> forma;
        zi[i] = new Mandolina(ime, brojZici, cena, forma);
    }
    for(int i = 0; i < n; ++i) {
        float golemina;
        cin >> ime >> brojZici >> cena >> golemina;
        zi[n + i] = new Violina(ime, brojZici, cena, golemina);
    }
    pecatiInstrumenti(m, zi, 2 * n);
    for(int i = 0; i < 2 * n; ++i) {
        delete zi[i];
    }
    delete [] zi;
    return 0;
}
