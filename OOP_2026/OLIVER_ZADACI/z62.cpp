#include <iostream>
#include <cstring>

using namespace std;

class NBAPlayer {
protected:
    char *ime;
    char tim[40];
    double prosececnipoeni;
    double prosececniasistenci;
    double prosececniskokovi;

public:
    NBAPlayer() {
        this->ime = new char[1];
        strcpy(this->ime, "");
        strcpy(this->tim, "");
        this->prosececnipoeni = 0;
        this->prosececniasistenci = 0;
        this->prosececniskokovi = 0;
    }

    NBAPlayer(char *ime, char tim[40], double prosececnipoeni, double prosececniasistenci, double prosececniskokovi) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        strcpy(this->tim, tim);
        this->prosececnipoeni = prosececnipoeni;
        this->prosececniasistenci = prosececniasistenci;
        this->prosececniskokovi = prosececniskokovi;
    }

    NBAPlayer(const NBAPlayer &n) {
        this->ime = new char[strlen(n.ime) + 1];
        strcpy(this->ime, n.ime);
        strcpy(this->tim, n.tim);
        this->prosececnipoeni = n.prosececnipoeni;
        this->prosececniasistenci = n.prosececniasistenci;
        this->prosececniskokovi = n.prosececniskokovi;
    }

    NBAPlayer &operator=(const NBAPlayer &n) {
        if (this != &n) {
            delete [] ime;
            this->ime = new char[strlen(n.ime) + 1];
            strcpy(this->ime, n.ime);
            strcpy(this->tim, n.tim);
            this->prosececnipoeni = n.prosececnipoeni;
            this->prosececniasistenci = n.prosececniasistenci;
            this->prosececniskokovi = n.prosececniskokovi;
        }
        return *this;
    }

    ~NBAPlayer() {
        delete [] ime;

    }

    double rating() {
        return prosececnipoeni*0.45+prosececniasistenci*0.30+prosececniskokovi*0.25;
    }
    void  print() {
       cout<<"Ime - "<<ime<<endl;

       cout<<"Points: "<<prosececnipoeni<<endl;

       cout<<"Assists: "<<prosececniasistenci<<endl;

       cout<<"Rebounds: "<<prosececniskokovi<<endl;

       cout<<"Rating: "<< rating()<<endl;
    }
};

class AllStarPlayer:public  NBAPlayer{
protected:
    double allprosececnipoeni;
    double allprosececniasistenci;
    double allprosecniskokovi;
public:
    AllStarPlayer() {
        this->allprosececnipoeni=0;
        this->allprosececniasistenci=0;
        this->allprosecniskokovi=0;
    }

    AllStarPlayer(NBAPlayer players,double allprosececnipoeni,double allprosececniasistenci,double allprosecniskokovi):NBAPlayer(players) {
        this->allprosececnipoeni=allprosececnipoeni;
        this->allprosececniasistenci=allprosececniasistenci;
        this->allprosecniskokovi=allprosecniskokovi;
    }

    AllStarPlayer(char *ime,char tim[40],double prosececnipoeni,double prosececniasistenci,double prosececniskokovi,double allprosececnipoeni,double allprosececniasistenci,double allprosecniskokovi):NBAPlayer(ime,tim,prosececnipoeni,prosececniasistenci,prosececniskokovi) {
        this->allprosececnipoeni=allprosececnipoeni;
        this->allprosececniasistenci=allprosececniasistenci;
        this->allprosecniskokovi=allprosecniskokovi;
    }

    AllStarPlayer(const AllStarPlayer &a):NBAPlayer(a) {
        this->allprosececnipoeni=a.allprosececnipoeni;
        this->allprosececniasistenci=a.allprosececniasistenci;
        this->allprosecniskokovi=a.allprosecniskokovi;
    }

    AllStarPlayer& operator=(const AllStarPlayer &a) {
        if (this!=&a) {
            this->allprosececnipoeni=a.allprosececnipoeni;
            this->allprosececniasistenci=a.allprosececniasistenci;
            this->allprosecniskokovi=a.allprosecniskokovi;

            delete [] ime;
            this->ime = new char[strlen(a.ime) + 1];
            strcpy(this->ime, a.ime);
            strcpy(this->tim, a.tim);
            this->prosececnipoeni = a.prosececnipoeni;
            this->prosececniasistenci = a.prosececniasistenci;
            this->prosececniskokovi = a.prosececniskokovi;


        }
        return *this;
    }

    double allStarRating() {
        return allprosececnipoeni*0.3+allprosececniasistenci*0.4+allprosecniskokovi*0.3;
    }

    double rating() {
        return (allStarRating()+NBAPlayer::rating())/2.0;
    }

    void print() {
        NBAPlayer::rating();
        cout<<"All Star Rating: "<<allStarRating()<<endl;

cout<<"New Rating: "<<rating()<<endl;
    }
};

int main() {
    char name[50];
    char team[40];
    double points;
    double assists;
    double rebounds;
    double allStarPoints;
    double allStarAssists;
    double allStarRebounds;

    NBAPlayer * players = new NBAPlayer[5];
    AllStarPlayer * asPlayers = new AllStarPlayer[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            players[i] = NBAPlayer(name,team,points,assists,rebounds);
            players[i].print();
        }
    }
    else if (n == 2) {

        for (int i=0; i < 5; ++i){
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            players[i] = NBAPlayer(name,team,points,assists,rebounds);
            asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
        }

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            players[i].print();

        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            asPlayers[i].print();

    }
    else if (n == 3) {

        for (int i=0; i < 5; ++i){
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                         allStarPoints,allStarAssists,allStarRebounds);
        }
        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            asPlayers[i].print();

    }

    delete [] players;
    delete [] asPlayers;
}
