#include <iostream>
#include <cstring>
using namespace std;
class Invalid {
public:
    void pecati() {
        cout<<"Pogresno vnesena registracija!"<<endl;
    }
};
class ImaMasa {
public:
    virtual double vratiMasa()=0;
    virtual void pecati()=0;

};

class PaketPijalok: public ImaMasa {
protected:
    double volumenEden ;
     int kolicina ;
    static double ambalaza;
    static double gustina;
public:
    PaketPijalok() {
        this->volumenEden=0;
        this->kolicina=0;
    }

    PaketPijalok(double volumenEden ,int kolicina) {
        this->volumenEden=volumenEden;
        this->kolicina=kolicina;
    }

    PaketPijalok(const PaketPijalok &p) {
        this->volumenEden=p.volumenEden;
        this->kolicina=p.kolicina;
    }
    int getKolicina() {
        return kolicina;
    }
    double edenpijj() {
        return volumenEden*gustina+ambalaza;
    }
    double vratiMasa() {
        return edenpijj()*kolicina;
    }
void pecati() {

    }
};




class PaketSok:public PaketPijalok{
protected:
    bool daliGaziran ;
public:
    PaketSok() {
        this->daliGaziran=false;
    }
    PaketSok( double volumenEden ,int kolicina,bool daliGaziran): PaketPijalok(volumenEden , kolicina){
        this->daliGaziran=daliGaziran;
    }
    PaketSok(const PaketSok &j): PaketPijalok(j){
        this->daliGaziran=j.daliGaziran;
    }
    double edenpijj() {
        if (!daliGaziran) {
            return kolicina*gustina+ambalaza+0.1;
        }
        return (kolicina*gustina+ambalaza);

    }
    double vratiMasa() {
        return edenpijj()*kolicina;
    }
void pecati() {
        cout << "Paket sok" << endl;

        cout << "kolicina " << kolicina

             << ", so po " << volumenEden * gustina

             << " l(dm3)" << endl;
    }

};

class PaketVino:public PaketPijalok{
protected:
    double procentAlkohol ;
public:
    PaketVino() {
        this->procentAlkohol=0;
    }

    PaketVino(double volumenEden ,int kolicina,double procentAlkohol): PaketPijalok(volumenEden , kolicina) {
        this->procentAlkohol=procentAlkohol;
    }

    PaketVino(const PaketVino &a): PaketPijalok(a) {
        this->procentAlkohol=a.procentAlkohol;
    }
    double edenpijj() {
        return (volumenEden*gustina+ambalaza);
    }

    double vratiMasa() {
        return edenpijj()*kolicina*(    0.9+procentAlkohol);

    }
    double getProcentAlkohol() {
        return procentAlkohol;
    }

    void pecati() {
        cout << "Paket vino" << endl;

        cout << "kolicina " << kolicina

             << ", " << procentAlkohol * 100

             << "% alkohol od po " << volumenEden * gustina

             << " l(dm3)" << endl;
    }
};
double PaketPijalok::ambalaza=0.2;
double PaketPijalok::gustina=0.8;


class Kamion {
protected:
    char *registracija;
    char *vozacot;
    int brelementi;
    ImaMasa **imamasaa;
public:
    Kamion() {
        this->registracija=new char[0];
        this->vozacot=new char[0];
        this->brelementi=0;
        this->imamasaa=nullptr;

    }
    Kamion( char *registracija,char *vozacot) {
        this->registracija=new char[strlen(registracija)+1];
        strcpy(this->registracija,registracija);
        this->vozacot=new char[strlen(vozacot)+1];
        strcpy(this->vozacot,vozacot);
        this->brelementi=0;
        this->imamasaa=nullptr;



    }
    Kamion( const Kamion &k) {
        this->registracija=new char[strlen(k.registracija)+1];
        strcpy(this->registracija,k.registracija);
        this->vozacot=new char[strlen(k.vozacot)+1];
        strcpy(this->vozacot,k.vozacot);
        this->brelementi=0;
        this->imamasaa=nullptr;

    }

    void dodadiElement(ImaMasa *nov) {
        ImaMasa **temp=new ImaMasa *[brelementi + 1];
        for (int i=0;i<brelementi;i++) {
            temp[i]=imamasaa[i];
        }
        temp[brelementi]=nov;
        brelementi++;
        delete [] imamasaa;
        imamasaa=temp;
    }

    double vratiVkupnaMasa() {
        double zbir=0;
        for (int i=0;i<brelementi;i++) {
            zbir+=imamasaa[i]->vratiMasa() ;
        }
        return zbir;
    }

    void pecati() {
        cout << "Kamion so registracija " << registracija<< " i vozac " << vozacot<< " prenesuva: " << endl;
        for (int i = 0; i < brelementi; i++) {
            imamasaa[i]->pecati();
        }
    }

    void registriraj(char *novaRegistracija) {
        if (!isalpha(novaRegistracija[0]) || !isalpha(novaRegistracija[1] ) || !isalpha(novaRegistracija[6]) || !isalpha(novaRegistracija[7])) {
            throw Invalid();
        }
        delete [] registracija;
        this->registracija=new char[strlen(novaRegistracija+1)];
        strcpy(this->registracija,novaRegistracija);

    }

    Kamion pretovar(char *novaRegistracija, char *novVozac) {
        Kamion novKamion(novaRegistracija, novVozac);
        int indexNajgolem = 0;
        double najgolemaMasa = imamasaa[0]->vratiMasa();
        for (int i = 1; i < brelementi; i++) {
            if (imamasaa[i]->vratiMasa() > najgolemaMasa) {
                najgolemaMasa = imamasaa[i]->vratiMasa();
                indexNajgolem = i;
            }
        }
        for (int i = 0; i < brelementi; i++) {
            if (i != indexNajgolem) {
                novKamion.dodadiElement(imamasaa[i]);
            }
        }
        return novKamion;
    }



};
int main() {
    char ime[20], reg[9];
    double vol;
    int n;
    int kol;
    bool g;
    double proc;

        cin>>reg;
        cin>>ime;
        Kamion A(reg, ime);
        ImaMasa **d = new ImaMasa*[5];
        cin>>vol>>kol;
        cin>>g;
        d[0] = new PaketSok(vol, kol, g);
        cin>>vol>>kol;
        cin>>proc;
        d[1] = new PaketVino(vol, kol, proc);
        cin>>vol>>kol;
        cin>>proc;
        d[2] = new PaketVino(vol, kol, proc);
        cin>>vol>>kol;
        cin>>g;
        d[3] = new PaketSok(vol, kol, g);
        cin>>vol>>kol;
        cin>>proc;
        d[4] = new PaketVino(vol, kol, proc);
        A.dodadiElement(d[0]);
        A.dodadiElement(d[1]);
        A.dodadiElement(d[2]);
        A.dodadiElement(d[3]);
        A.dodadiElement(d[4]);
        A.pecati();
        cout<<"Vkupna masa: "<<A.vratiVkupnaMasa()<<endl;
        cin>>reg;
        cin>>ime;
        Kamion B = A.pretovar(reg, ime);
        B.pecati();
        cout<<"Vkupna masa: "<<B.vratiVkupnaMasa()<<endl;


    return 0;
}