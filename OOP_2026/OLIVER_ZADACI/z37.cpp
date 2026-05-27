#include<iostream>
using namespace std;
class Potpisuvac {
private:
    char ime[20];
    char prezime[20];
    char maticen[20];
public:
    Potpisuvac() {
        strcpy(this->ime,"");
        strcpy(this->prezime,"");
        strcpy(this->maticen,"");
    }

    Potpisuvac( char ime[20],char prezime[20],char maticen[20]) {
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        strcpy(this->maticen,maticen);
    }

    Potpisuvac( const Potpisuvac &p) {
        strcpy(this->ime,p.ime);
        strcpy(this->prezime,p.prezime);
        strcpy(this->maticen,p.maticen);
    }
     friend class Dogovor;
};
class Dogovor {
private:
    int brojnadog;
    char kategorija[50];
    Potpisuvac popisuvaci[3];
public:
    Dogovor() {
        this->brojnadog=0;
        strcpy(this->kategorija,"");
        for (int i=0;i<3;i++) {
            this->popisuvaci[i]=Potpisuvac();
        }

    }

    Dogovor(int brojnadog,char kategorija[50],Potpisuvac popisuvaci[3]) {
        this->brojnadog=brojnadog;
        strcpy(this->kategorija,kategorija);
        for (int i=0;i<3;i++) {
           this-> popisuvaci[i]=popisuvaci[i];
        }

    }

    Dogovor(const Dogovor &d) {
        this->brojnadog=d.brojnadog;
        strcpy(this->kategorija,d.kategorija);
        for (int i=0;i<3;i++) {
            this->popisuvaci[i]=d.popisuvaci[i];
        }

    }

    bool proverka() {
        if(strcmp(popisuvaci[0].maticen, popisuvaci[1].maticen) == 0 ||
           strcmp(popisuvaci[0].maticen, popisuvaci[2].maticen) == 0 ||
           strcmp(popisuvaci[1].maticen, popisuvaci[2].maticen) == 0) {
            return true;
           }
        return false;
    }



};


int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin >> embg >> ime >> prezime;
        Potpisuvac p1(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p2(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p3(ime, prezime, embg);
        cin >> broj >> kategorija;
        Potpisuvac p[3];
        p[0] = p1;
        p[1] = p2;
        p[2] = p3;
        Dogovor d(broj, kategorija, p);
        if(d.proverka() == true)
            cout << "Dogovor "<<i+1<<":"<<endl<<"Postojat potpishuvaci so ist EMBG" << endl;
        else
            cout << "Dogovor "<<i+1<<":"<<endl<<"Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}