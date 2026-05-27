#include <iostream>
#include <cstring>
using namespace std;
class InvalidTimeException{
public:
    void pecati(){
        cout<<"Vremeto ne e validno"<<endl;
    }
};
class Race {
protected:
    char ime[40];
    int godnaodr;
    int mesnaodr;
    float najvremevosek;
    float km;

public:
    Race() {
        strcpy(this->ime, "");
        this->godnaodr = 0;
        this->mesnaodr = 0;
        this->najvremevosek = 0;
        this->km = 0;
    }

    Race(char ime[40], int godnaodr, int mesnaodr, float najvremevosek, float km) {
        strcpy(this->ime, ime);
        this->godnaodr = godnaodr;
        this->mesnaodr = mesnaodr;
        this->najvremevosek = najvremevosek;
        this->km = km;
    }

    Race(const Race &r) {
        strcpy(this->ime, r.ime);
        this->godnaodr = r.godnaodr;
        this->mesnaodr = r.mesnaodr;
        this->najvremevosek = r.najvremevosek;
        this->km = r.km;
    }

    Race &operator =(const Race &r) {
        if (this != &r) {
            strcpy(this->ime, r.ime);
            this->godnaodr = r.godnaodr;
            this->mesnaodr = r.mesnaodr;
            this->najvremevosek = r.najvremevosek;
            this->km = r.km;
        }
        return *this;
    }

    virtual ~Race() {
    }

    virtual float heaviness() const {
        return najvremevosek / km;
    }

    friend ostream &operator<<(ostream &pecati, const Race &r) {
        pecati << r.ime << " " << r.mesnaodr << " " << r.godnaodr << " " << r.heaviness() << endl;
        return pecati;
    }
};

class CarRace : public Race {
protected:
    float *najdobrivre;
    int br;
    int brkrugovi;
    static float CAR_COF;

public:
    CarRace() {
        this->br = 0;
        this->najdobrivre = new float[0];
        this->brkrugovi = 0;
    }

    CarRace(char ime[40], int godnaodr, int mesnaodr, float najvremevosek, float km, float *najdobrivre, int br,
            int brkrugovi) : Race(ime, godnaodr, mesnaodr, najvremevosek, km) {
        this->br = br;
        this->najdobrivre = new float[br];
        for (int i = 0; i < br; i++) {
            this->najdobrivre[i] = najdobrivre[i];
        }
        this->brkrugovi = brkrugovi;
    }
    CarRace(char ime[40], int godnaodr, int mesnaodr, float najvremevosek, float km) {
        strcpy(this->ime,ime);
        this->godnaodr=godnaodr;
        this->mesnaodr=mesnaodr;
        this->najvremevosek=najvremevosek;
        this->km=km;

    }

    CarRace(const CarRace &c) : Race(c) {
        this->br = c.br;
        this->najdobrivre = new float[c.br];
        for (int i = 0; i < c.br; i++) {
            this->najdobrivre[i] = c.najdobrivre[i];
        }
        this->brkrugovi = c.brkrugovi;
    }

    CarRace &operator =(const CarRace &c) {
        if (this != &c) {
            delete [] najdobrivre;
            this->br = c.br;
            this->najdobrivre = new float[c.br];
            for (int i = 0; i < c.br; i++) {
                this->najdobrivre[i] = c.najdobrivre[i];
            }
            this->brkrugovi = c.brkrugovi;

            strcpy(this->ime, c.ime);
            this->godnaodr = c.godnaodr;
            this->mesnaodr = c.mesnaodr;
            this->najvremevosek = c.najvremevosek;
            this->km = c.km;
        }
        return *this;
    }

    ~CarRace() {
        delete [] najdobrivre;
    }


    float heaviness() const {
        float suma=0;
        for (int i = 0; i < br; i++) {
            suma+=najdobrivre[i];
        }

        float prosek=suma/br;
        float staro=Race::heaviness();
        float finalno= staro+(prosek*CAR_COF);
        if (brkrugovi>15) {
            return finalno*1.1;
        }
        else {
            return finalno;
        }
    }

    void setNumberLaps(int brkrugovi) {
        this->brkrugovi=brkrugovi;
    }
    static void setKoeficient(float k) {
        CAR_COF=k;
    }


    void operator +=(float time) {
        if(time<10){
            throw InvalidTimeException();
        }
        float *temp=new float[br+1];
        for (int i=0;i<br;i++) {
            temp[i]=najdobrivre[i];
        }
        temp[br]=time;
        br++;
        delete[] najdobrivre;
        najdobrivre=temp;
    }
    friend ostream &operator<<(ostream &pecati,const CarRace &r){
        pecati<<"["<<r.ime<<" "<<r.mesnaodr<<" "<<r.godnaodr<<" "<<r.heaviness()<<"]"<<endl;
        return pecati;
    }

};

float CarRace::CAR_COF = 0.3;

int main() {
    int testCase;
    cin >> testCase;
    char city[50];
    int year;
    int month;
    float bestTime;
    float length;
    float bestTimes[50];
    int n;
    int m;
    int izbor;
    int numberLaps;

    if (testCase == 1) {
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin >> length;
        Race t(city, year, month, bestTime, length);
        cout << t;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin >> length;
        cin >> numberLaps;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];
        CarRace mgt(city, year, month, bestTime, length, bestTimes, n, numberLaps);
        cout << mgt;
        CarRace mgt2;
    }
    if (testCase == 2) {
        cout << "===== Testiranje na operatorot += ======" << endl;
        Race *niza;
        cin >> m;
        niza = new Race [m];
        for (int i = 0; i < m; i++) {
            cin >> izbor;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >> length;
            if (izbor == 1) {
                niza[i] = new Race(city, year, month, bestTime, length);
            } else {
                cin >> numberLaps;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                niza[i] = new CarRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << niza[i];

        // dodavanje novo najdobro vreme za prvata CarRace
        float best;
        cin >> best;
        int flag = 1;
        for (int i = 0; i < m; i++) {
            CarRace nn = dynamic_cast<CarRace>(niza[i]);
            if (nn != 0) {
                flag = 0;
                (*nn) += best;
                break;
            }
        }


        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 3) {
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin >> length;
        cin >> numberLaps;
        CarRace mgt(city, year, month, bestTime, length);
        mgt.setNumberLaps(numberLaps);
        float vreme1, vreme2;
        cin >> vreme1 >> vreme2;
        try {
            mgt += vreme1;
            mgt += vreme2;
        } catch (InvalidTimeException e) {
            e.pecati();
        }
        cout << mgt;
    }

    if (testCase == 5) {
        cout << "===== Testiranje na static clenovi ======" << endl;
        Race **niza;
        cin >> m;
        niza = new Race *[m];
        for (int i = 0; i < m; i++) {
            cin >> izbor;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >> length;
            if (izbor == 1) {
                niza[i] = new Race(city, year, month, bestTime, length);
            } else {
                cin >> numberLaps;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                niza[i] = new CarRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        CarRace::setKoeficient(0.7);
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }

    return 0;
}

}
