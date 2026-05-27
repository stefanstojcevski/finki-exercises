#include <iostream>
#include<cstring>
using namespace std;


class Lekar {
protected:
    int faksimil;
    char ime[10];
    char prezime[10];
    float osnovnaplata;




public:
    Lekar() {
        this->faksimil = 0;
        strcpy(this->ime,"");
        strcpy(this->prezime,"");
        this->osnovnaplata = 0;
    }

    Lekar(int faksimil,char ime[10],char prezime[10],float plata) {
        this->faksimil = faksimil;
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        this->osnovnaplata = plata;
    }

    Lekar(const Lekar &l) {
        this->faksimil = l.faksimil;
        strcpy(this->ime,l.ime);
        strcpy(this->prezime,l.prezime);
        this->osnovnaplata = l.osnovnaplata;
    }

    Lekar& operator=(const Lekar &l) {
        if (this!=&l) {
            this->faksimil = l.faksimil;
            strcpy(this->ime,l.ime);
            strcpy(this->prezime,l.prezime);
            this->osnovnaplata = l.osnovnaplata;
        }
        return *this;
    }


    void pecati() {
        cout << "faksimil:" << faksimil << endl;
        cout << "ime:" << ime << endl;
        cout << "prezime:" << prezime << endl;
        cout << "plata:" << osnovnaplata << endl;
    }
    double plata() {

        return osnovnaplata;

    }
};

class MaticenLekar : public Lekar {
protected:
    int brojpacienti;
    double *kodizacii;


public:
    MaticenLekar() {
        this->brojpacienti = 0;
        this->kodizacii = new double[0];
    }

    MaticenLekar(    int faksimil,char ime[10],char prezime[10],float plata,     int brojpacienti,double *kodizacii):Lekar(   faksimil,ime, prezime,plata) {
        this->brojpacienti = brojpacienti;
        this->kodizacii = new double[brojpacienti];
        for (int i=0;i<brojpacienti;i++) {
            this->kodizacii[i] = kodizacii[i];
        }
    }

    MaticenLekar(Lekar lekari ,  int brojpacienti,double *kodizacii):Lekar(lekari) {
        this->brojpacienti = brojpacienti;
        this->kodizacii = new double[brojpacienti];
        for (int i=0;i<brojpacienti;i++) {
            this->kodizacii[i] = kodizacii[i];
        }
    }

    MaticenLekar(const MaticenLekar &m):Lekar(m) {
        this->brojpacienti = m.brojpacienti;
        this->kodizacii = new double[m.brojpacienti];
        for (int i=0;i<m.brojpacienti;i++) {
            this->kodizacii[i] = m.kodizacii[i];
        }
    }

    MaticenLekar& operator=(const MaticenLekar &m) {
        if (this!=&m) {
            delete [] kodizacii;
            this->brojpacienti = m.brojpacienti;
            this->kodizacii = new double[m.brojpacienti];
            for (int i=0;i<m.brojpacienti;i++) {
                this->kodizacii[i] = m.kodizacii[i];
            }

            this->faksimil = m.faksimil;
            strcpy(this->ime,m.ime);
            strcpy(this->prezime,m.prezime);
            this->osnovnaplata = m.osnovnaplata;
        }
        return *this;
    }

    ~MaticenLekar() {
        delete [] kodizacii;
    }

    double sredna() {
        double zbir=0;
        for (int i=0;i<brojpacienti;i++) {
            zbir+=kodizacii[i];
        }
        double sredna=zbir/brojpacienti;
        return sredna;
    }

    void pecati() {
        Lekar::pecati();

        cout<<sredna()<<endl;

    }

    double plata() {
        return sredna()*0.3+osnovnaplata;
    }









};

int main() {
    int n;
    cin>>n;
    int pacienti;
    double kotizacii[100];
    int faksimil;
    char ime [20];
    char prezime [20];
    double osnovnaPlata;

    Lekar * lekari = new Lekar [n];
    MaticenLekar * maticni = new MaticenLekar [n];

    for (int i=0;i<n;i++){
        cin >> faksimil >> ime >> prezime >> osnovnaPlata;
        lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);
    }

    for (int i=0;i<n;i++){
        cin >> pacienti;
        for (int j=0;j<pacienti;j++){
            cin >> kotizacii[j];
        }
        maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii);
    }

    int testCase;
    cin>>testCase;

    if (testCase==1){
        cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
        for (int i=0;i<n;i++){
            lekari[i].pecati();
            cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].plata()<<endl;
        }
    }
    else {
        cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
        for (int i=0;i<n;i++){
            maticni[i].pecati();
            cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].plata()<<endl;
        }
    }

    delete [] lekari;
    delete [] maticni;

    return 0;
}
