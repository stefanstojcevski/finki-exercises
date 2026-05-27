#include <iostream>
#include <cstring>
using namespace std;
class BasketballPlayer {
private:
    char ime[20];
    char prezime[20];
    int brojnaDres;
    int poeni1;
    int poeni2;
    int poeni3;
public:
    BasketballPlayer (){
        strcpy(this->ime,"");
        strcpy(this->prezime,"");
        this->poeni1=0;
        this->poeni2=0;
        this->poeni3=0;
    }
    BasketballPlayer (char ime[20],char prezime[20],int brojnaDres,int poeni1,int poeni2,int poeni3){
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        this->brojnaDres = brojnaDres;
        this->poeni1=poeni1;
        this->poeni2=poeni2;
        this->poeni3=poeni3;
    }
    ~BasketballPlayer() {

    }

    float avg() {
        float zbir=poeni1+poeni2+poeni3;
        float avg=zbir/3.0;
        return avg;

    }

    void display() {
        cout<<"Player: "<<ime<<" "<<prezime<<" with number "<<brojnaDres<<" has "<<avg()<<" points on average";
    }



};
int main() {
    char ime[20];
    char prezime[20];
    int brojnaDres;
    int poeni1;
    int poeni2;
    int poeni3;

    cin>>ime;
    cin>>prezime;
    cin>>brojnaDres;
    cin>>poeni1;
    cin>>poeni2;
    cin>>poeni3;
    BasketballPlayer b(ime,prezime,brojnaDres, poeni1, poeni2, poeni3);
}