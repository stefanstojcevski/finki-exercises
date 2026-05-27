
#include <iostream>
using namespace std;
class Film {
private:
    char ime[100];
    float rejting;
    float zarabotka;
public:
    Film() {
        strcpy(this->ime,"");
        this->rejting=0;
        this->zarabotka=0;
    }
    Film( char ime[20], float rejting,float zarabotka) {
        strcpy(this->ime,ime);
        this->rejting=rejting;
        this->zarabotka=zarabotka;

    }
    ~Film(){
    }

    float getZarabotka() {
        return zarabotka;
    }


    void pecati(){
        cout<<"Ime: "<<ime<<endl;
        cout<<"Rejting: "<<rejting<<endl;
        cout<<"Zarabotka: "<<zarabotka<<endl;
    }
};
void printMostPopularFilm(Film filmovi[],int n) {
    int index=0;
    for (int i=0;i<n;i++) {
        if (filmovi[i].getZarabotka()>filmovi[index].getZarabotka()) {
            index=i;

        }
    }

            filmovi[index].pecati();



}
int main() {
    int n;
    cin >> n;

    Film films[100];

    char name[100];
    float rating;
    float revenue;

    for(int i = 0; i < n; i++){
        cin >> name >> rating >> revenue;
        films[i] = Film(name, rating, revenue);
    }

    cout << "-->Testing set methods and display()" << endl;

    films[0].pecati();

    cout << "-->Testing printMostPopularFilm()" << endl;

    printMostPopularFilm(films, n);

    return 0;
}
