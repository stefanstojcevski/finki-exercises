#include <iostream>
#include <cstring>
using namespace std;
class Masa {
private:
    int sirina;
    int dolzina;

public:
    Masa() {
        this->sirina=0;
        this->dolzina=0;


    }

    Masa( int sirina,int dolzina) {
        this->sirina=sirina;
        this->dolzina=dolzina;


    }
    Masa(const Masa &m) {
        this->sirina=m.sirina;
        this->dolzina=m.dolzina;


    }

    Masa& operator=(const Masa &m) {
        if (this!=&m) {
            this->sirina=m.sirina;
            this->dolzina=m.dolzina;

        }
        return *this;

    }

    ~Masa() {

    }


    void pecati() {
        cout<<sirina<<" "<<dolzina<<endl;
    }
};

class Soba {
private:
    int sirina;
    int dolzina;
    Masa masa;
public:
    Soba() {
        this->sirina=0;
        this->dolzina=0;
        this->masa=Masa();


    }

    Soba(int sirina,int dolzina,Masa masa) {
        this->sirina=sirina;
        this->dolzina=dolzina;
        this->masa=masa;

    }
    Soba(const Soba &s) {
        this->sirina=s.sirina;
        this->dolzina=s.dolzina;
        this->masa=s.masa;

    }

    Soba& operator=(const Soba &s) {
        if (this!=&s) {
            this->sirina=s.sirina;
            this->dolzina=s.dolzina;
            this->masa=s.masa;
        }
        return *this;

    }
    void pecati() {
        cout<<"SOBA: "<<sirina<<" "<<dolzina<<endl;
        cout<<"MASA:"<<endl;
        masa.pecati();
    }
};
class Kukja {
private:
    Soba soba;
    char adresa[50];
public:
    Kukja() {
        this->soba=Soba();
        strcpy(adresa,"");

    }
    Kukja( Soba soba,char adresa[50]) {
        this->soba=soba;
        strcpy(this->adresa,adresa);

    }

    Kukja( const Kukja &k) {
        this->soba=k.soba;
        strcpy(this->adresa,k.adresa);

    }

    Kukja& operator=( const Kukja &k) {
        if (this!=&k) {
            this->soba=k.soba;
            strcpy(this->adresa,k.adresa);
        }
        return *this;
    }

    void pecati() {
        soba.pecati();
    }

};

using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
        Masa m(masaSirina,masaDolzina);
        int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
        Soba s(sobaSirina,sobaDolzina,m);
        char adresa[30];
        cin>>adresa;
        Kukja k(s,adresa);
        k.pecati();
    }

    return 0;
}