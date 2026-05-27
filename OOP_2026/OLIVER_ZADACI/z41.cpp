#include <iostream>
#include <cstring>
using namespace std;


class Automobile {
private:
    char *marka;
    int *registracija;
    int maxbrzina;
public:
    Automobile() {
        this->marka=new char[1];
        this->registracija=new int[0];
        this->maxbrzina=0;
    }

    Automobile( char *marka,int *registracija,int maxbrzina) {
        this->marka=new char[strlen(marka)+1];
        strcpy(this->marka,marka);
        this->registracija=new int[5];
        for (int i=0;i<5;i++) {
            this->registracija[i]=registracija[i];

        }
        this->maxbrzina=maxbrzina;
    }


    Automobile( const Automobile &a) {
        this->marka=new char[strlen(a.marka)+1];
        strcpy(this->marka,a.marka);
        this->registracija=new int[5];
        for (int i = 0; i < 5; i++) {
            this->registracija[i] = a.registracija[i];
        }
        this->maxbrzina=a.maxbrzina;
    }


    Automobile& operator=( const Automobile &a) {
        if (this!=&a) {
            delete [] marka;
            delete [] registracija;
            this->marka=new char[strlen(a.marka)+1];
            strcpy(this->marka,a.marka);
            this->registracija=new int[5];
            for (int i = 0; i < 5; i++) {
                this->registracija[i] = a.registracija[i];
            }
            this->maxbrzina=a.maxbrzina;
        }
        return *this;
    }
    ~Automobile(){
        delete [] marka;
        delete [] registracija;
    }


    bool operator ==(const Automobile &a ) {
        for (int i = 0; i < 5; i++) {
            if (registracija[i] != a.registracija[i]) {
                return false;
            }
        }
        return true;
    }



    friend ostream & operator <<(ostream &pecati,const Automobile &a) {
        pecati<<"Marka\t"<<a.marka<<"\tRegistracija:[ ";
        for(int i=0;i<5;i++){
            pecati<<a.registracija[i]<<" ";
        }
        pecati<<"]"<<endl;
        return pecati;
    }
    friend class RentACar;

};


class RentACar {
private:
    char ime[100];
    int broj;
    Automobile *automobils;
public:
    RentACar() {
        strcpy(this->ime,"FINKI-Car");
        this->broj=0;
        this->automobils=nullptr;

    }

    RentACar(char ime[100]) {
        strcpy(this->ime,ime);
        this->broj=0;
        this->automobils=new Automobile[broj];
        for (int i=0;i<broj;i++) {
           this-> automobils[i]=automobils[i];

        }

    }

    RentACar (const RentACar &r) {
        strcpy(this->ime,r.ime);
        this->broj=r.broj;
        this->automobils=new Automobile[r.broj];
        for (int i=0;i<r.broj;i++) {
            this->automobils[i]=r.automobils[i];

        }

    }


    RentACar& operator=(const RentACar &r) {
        if (this!=&r) {
            delete [] automobils;
            strcpy(this->ime,r.ime);
            this->broj=r.broj;
            this->automobils=new Automobile[r.broj];
            for (int i=0;i<r.broj;i++) {
                this->automobils[i]=r.automobils[i];

            }
        }
        return *this;
    }
    ~RentACar() {
        delete [] automobils;
    }
    RentACar& operator+=(const Automobile &a){
        Automobile *temp=new Automobile[broj+1];
        for(int i=0;i<broj;i++){
            temp[i]=automobils[i];
        }
        temp[broj]=a;
        broj++;
        delete [] automobils;
        automobils=temp;
        return *this;
    }
    RentACar& operator -=(const Automobile &a) {
        for (int i=0;i<broj;i++) {
            if (automobils[i]==a) {
                automobils[i]=a;

            }
        }
        return *this;
    }
    void pecatiNadBrzina(int max) {
        cout<<ime<<endl;
        for (int i=0;i<broj;i++) {
            if (automobils[i].maxbrzina>=max) {
               cout<< automobils[i]<<endl;
            }
        }
    }



};


int main()
{
    RentACar agencija("FINKI-Car");
    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        char marka[100];
        int regisracija[5];
        int maximumBrzina;

        cin>>marka;

        for (int i=0;i<5;i++)
            cin>>regisracija[i];

        cin>>maximumBrzina;

        Automobile nov=Automobile(marka,regisracija,maximumBrzina);

        //dodavanje na avtomobil
        agencija+=nov;

    }
    //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin>>marka;
    for (int i=0;i<5;i++)
        cin>>regisracija[i];
    cin>>maximumBrzina;

    Automobile greshka=Automobile(marka,regisracija,maximumBrzina);

    //brishenje na avtomobil
    agencija-=greshka;

    agencija.pecatiNadBrzina(150);

    return 0;
}