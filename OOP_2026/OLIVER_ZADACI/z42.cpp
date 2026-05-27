#include <iostream>
#include <cstring>
using namespace std;

class DisciplinaryAction {
private:
    char *ime;
    int indeks;
    char *pricina;
    int brojsesi;
public:
    DisciplinaryAction() {
        this->ime=new char[1];
        this->indeks=0;
        this->pricina=new char[1];
        this->brojsesi=0;
    }

    DisciplinaryAction(char *ime,int indeks,char *pricina,int brojsesi) {
        this->ime=new char [strlen(ime)+1];
        strcpy(this->ime,ime);
        this->indeks=indeks;
        this->pricina=new char [strlen(pricina)+1];
        strcpy(this->pricina,pricina);
        this->brojsesi=brojsesi;
    }

    DisciplinaryAction (const DisciplinaryAction &d) {
        this->ime=new char [strlen(d.ime)+1];
        strcpy(this->ime,d.ime);
        this->indeks=d.indeks;
        this->pricina=new char [strlen(d.pricina)+1];
        strcpy(this->pricina,d.pricina);
        this->brojsesi=d.brojsesi;
    }


    DisciplinaryAction& operator=(const DisciplinaryAction &d) {
        if (this!=&d) {
            delete [] ime;
            delete [] pricina;

            this->ime=new char [strlen(d.ime)+1];
            strcpy(this->ime,d.ime);
            this->indeks=d.indeks;
            this->pricina=new char [strlen(d.pricina)+1];
            strcpy(this->pricina,d.pricina);
            this->brojsesi=d.brojsesi;
        }
        return *this;
    }

    ~DisciplinaryAction() {
        delete [] ime;
        delete [] pricina;
    }

    void setIndex(int indeks) {
        this->indeks=indeks;
    }

    int getIndex() {
        return indeks;

    }

    friend ostream & operator<<(ostream & pecati , const DisciplinaryAction &d) {
            pecati<<"Student: "<<d.ime<<endl;
            pecati<<"Student index: "<<d.indeks<<endl;
            pecati<<"Reson: "<<d.pricina<<endl;
            pecati<<"Lesons: "<<d.brojsesi<<endl;


        return pecati;

    }

    DisciplinaryAction& operator++() {
        brojsesi++;
        return *this;

    }

    bool operator>=(const DisciplinaryAction &d) {

            return this->brojsesi >= d.brojsesi;

    }

};
int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for (int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;
        int sessions;

        cin >> name >> index >> reason >> sessions;

        arr[i] = DisciplinaryAction(name, index, reason, sessions);
    }

    cout << "-- Testing operator = & operator <<  --\n";
    cout << arr[0];

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    cout << arr[0];

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    cout << merka;

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for (int i = 0; i < n; i++)
        cout << arr[i];


    cout << "\nTesting operator  and <<" << endl;
    for (int i = 0; i < n; i)
        cout << (arr[i]);


    cout << "\nTesting operator >=" << endl;
    for (int i = 0; i < n; i) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << i << " " << ((arr[i] >= arr[j]) ? ">= " : "< ") << j << endl;
            }
        }
    }

    return 0;
}