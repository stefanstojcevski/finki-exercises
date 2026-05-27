#include <iostream>
#include <cstring>
using namespace std;

class Film {
private:
    char naslov[100];
    int dolzina;
    int brojo;
    double zbir;

public:
    Film() {
        strcpy(this->naslov, "UNTITLED");
        this->dolzina = 0;
        this->brojo = 0;
        this->zbir = 0;
    }

    Film(char *naslov, int dolzina, int brojo, double zbir) {
        strcpy(this->naslov, naslov);
        this->dolzina = dolzina;
        this->brojo = brojo;
        this->zbir = zbir;
    }

    Film(const Film &f) {
        strcpy(this->naslov, f.naslov);
        this->dolzina = f.dolzina;
        this->brojo = f.brojo;
        this->zbir = f.zbir;
    }

    Film &operator=(const Film &f) {
        if (this != &f) {
            strcpy(this->naslov, f.naslov);
            this->dolzina = f.dolzina;
            this->brojo = f.brojo;
            this->zbir = f.zbir;
        }
        return *this;
    }

    ~Film() {
    }

    double AVERAGE_RATING() const {
        if (brojo == 0) {
            return 0;
        }
        double AVERAGE_RATING;
        AVERAGE_RATING = zbir / brojo;
        return AVERAGE_RATING;
    }

    friend ostream &operator <<(ostream &pecati, const Film &f) {
        pecati << f.naslov << " - " << f.dolzina << " min - ";
        if (f.AVERAGE_RATING() == 0) {
            pecati << "NO RATINGS" << endl;
        } else {
            pecati << f.AVERAGE_RATING() << endl;
        }
        return pecati;
    }

    void rateFilm(int rating) {
        brojo++;
        zbir += rating;
    }
};

int main() {
    int n;
    cin>>n;
    cin.ignore();
    Film p;
    char naslov[100];
    int dolzina;
    int brojo;
    double zbir=0;;
for (int i=0;i<n;i++) {
    cin.getline(naslov, 100);
    cin >> dolzina;
    cin.ignore();
    cin >> brojo;
    p = Film(naslov, dolzina, 0, zbir);
    int rating;
    for (int i = 0; i < brojo; i++) {
        cin >> rating;
        p.rateFilm(rating);
    }
    cout << p;
    cin.ignore();

}

}
