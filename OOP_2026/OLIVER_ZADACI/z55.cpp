#include <iostream>
#include <cstring>
using namespace std;

class Song {
private:
    char ime[100];
    int vremetraejne;
public:
    Song() {
        strcpy(this->ime,"UNKNOWN");
        this->vremetraejne=0;

    }

    Song( char ime[100],int vremetraejne) {
        strcpy(this->ime,ime);
        this->vremetraejne=vremetraejne;

    }

    Song(const Song &s ) {
        strcpy(this->ime,s.ime);
        this->vremetraejne=s.vremetraejne;

    }

    Song& operator=(const Song &s ) {
        if (this!=&s) {
            strcpy(this->ime,s.ime);
            this->vremetraejne=s.vremetraejne;
        }
        return *this;
    }


    void play(int seconds) {
        vremetraejne+=seconds;
        if (vremetraejne>300) {
            vremetraejne=300;
        }
    }

    friend ostream& operator<<(ostream & pecati,const Song &s) {
        pecati<<s.ime<<" - "<<s.vremetraejne<<"/300 - ";
        if (s.vremetraejne<100) {
            pecati<<"STARTED";
        }
        else if (s.vremetraejne>=100 && s.vremetraejne<300) {
            pecati<<"ALMOST DONE";
        }
        else if (s.vremetraejne==300) {
            pecati<<"FINISHED";
        }

        return pecati;
    }



};
int main() {
    int n;
    cin>>n;
    Song p;
    for (int i=0;i<n;i++) {
        char ime[100];
        int vremetraejne;
        cin>>ime;
        cin>>vremetraejne;
        p=Song(ime,vremetraejne);

        int seconds;
        cin>>seconds;
        p.play(seconds);

        cout<<p;
    }


}