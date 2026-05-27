#include <iostream>
#include <cstring>

using namespace std;
class PlDrustvo {
private:
    char *ime;
    int broj;
    int brclenovi;
public:
    PlDrustvo() {
        this->ime=new char[1];
        this->broj=0;
        this->brclenovi=0;

    }

    PlDrustvo( char *ime,int broj,int brclenovi) {
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->broj=broj;
        this->brclenovi=brclenovi;

    }

    PlDrustvo( const PlDrustvo &p) {
        this->ime=new char[strlen(p.ime)+1];
        strcpy(this->ime,p.ime);
        this->broj=p.broj;
        this->brclenovi=p.brclenovi;

    }

    PlDrustvo& operator=( const PlDrustvo &p) {
        if (this!=&p) {
            delete [] ime;
            this->ime=new char[strlen(p.ime)+1];
            strcpy(this->ime,p.ime);
            this->broj=p.broj;
            this->brclenovi=p.brclenovi;
        }
        return *this;
    }
    ~PlDrustvo() {
        delete [] ime;

    }
    PlDrustvo operator+(const PlDrustvo &p) {
        PlDrustvo result;
        result.brclenovi=this->brclenovi+p.brclenovi;
        if (this->brclenovi > p.brclenovi) {
            result.ime = new char[strlen(this->ime)+1];
            strcpy(result.ime, this->ime);
            result.broj = this->broj;
        } else {
            result.ime = new char[strlen(p.ime)+1];
            strcpy(result.ime, p.ime);
            result.broj = p.broj;
        }

        return result;


    }

    bool operator >(const PlDrustvo &p) {
        if (this->brclenovi>p.brclenovi) {
            return true;
        }
        return false;
    }


    bool operator <(const PlDrustvo &p) {
        if (this->brclenovi<p.brclenovi) {
            return true;
        }
        return false;
    }

    friend ostream& operator <<(ostream &pecati,const PlDrustvo &p) {
        pecati << p.ime << " " << p.broj << " " << p.brclenovi << endl;
        return pecati;
    }

    void najmnoguClenovi(PlDrustvo d[], int n) {
        int maxIndex = 0;
        for (int i=0;i<n;i++) {
            if (d[i].brclenovi>d[maxIndex].brclenovi) {
                maxIndex=i;
            }

        }
        cout <<"Najmnogu clenovi ima planinarskoto drustvo: "<<d[maxIndex] << endl;

    }
};

int main()
{
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i=0;i<3;i++)
    {
        char ime[100];
        int brTuri;
        int brClenovi;
        cin>>ime;
        cin>>brTuri;
        cin>>brClenovi;
        PlDrustvo p(ime,brTuri,brClenovi);
        drustva[i] = p;

    }

    pl = drustva[0] + drustva[1];
    cout<<pl;

    najmnoguClenovi(drustva, 3);

    return 0;
}