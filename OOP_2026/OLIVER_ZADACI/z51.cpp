#include <iostream>
#include<cstring>
using namespace std;
class Movie {
private:
    char *naslov;
    int vremetraejne;
public:
    Movie() {
        this->naslov=new char[1];
        this->vremetraejne=0;
    }

    Movie(char naslov[100],int vremetraejne) {
        this->naslov=new char[strlen(naslov)+1];
        strcpy(this->naslov,naslov);
        this->vremetraejne=vremetraejne;
    }

    Movie(const Movie &m) {
        this->naslov=new char[strlen(m.naslov)+1];
        strcpy(this->naslov,m.naslov);
        this->vremetraejne=m.vremetraejne;
    }

    Movie& operator=(const Movie &m) {
        if (this!=&m) {
            delete [] naslov;
            this->naslov=new char[strlen(m.naslov)+1];
            strcpy(this->naslov,m.naslov);
            this->vremetraejne=m.vremetraejne;
        }
        return *this;
    }

    void watch(int minutes) {
        vremetraejne+=minutes;
        if (vremetraejne>180) {
            vremetraejne=180;
        }

    }
    ~Movie() {
        delete [] naslov;

    }

    // void print() {
    //     cout<<naslov<<" - "<<vremetraejne<<"/180 - ";
    //     if (vremetraejne<60) {
    //         cout<<"STARTED";
    //     }
    //     else if (vremetraejne>=60 && vremetraejne<180){
    //         cout<<"NEAR END";
    //     }
    //     else {
    //         cout<<"FINISHED";
    //     }
    //}
    friend ostream & operator<<(ostream & pecati,const Movie &m) {
        pecati<<m.naslov<<" - "<<m.vremetraejne<<"/180 - ";
        if (m.vremetraejne<60) {
            pecati<<"STARTED";
        }
        else if (m.vremetraejne>=60 && m.vremetraejne<180){
            pecati<<"NEAR END";
        }
        else {
            pecati<<"FINISHED";
        }
        return pecati;
    }
};

int main() {
    Movie m;
    char naslov[100];
    int vremetraejne;
    cin>>naslov;
    cin>>vremetraejne;
    m=Movie(naslov,vremetraejne);
    int minutes;
    cin>>minutes;
    m.watch(minutes);
    cout<<m;


}