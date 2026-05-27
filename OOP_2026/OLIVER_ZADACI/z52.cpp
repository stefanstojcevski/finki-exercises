#include <iostream>
#include<cstring>
using namespace std;

class Student {
private:
    char *ime;
    int *brojpolozeni;
    int broj;

public:
    Student() {
        this->ime = new char[1];
        this->ime[0] = '\0';

        this->brojpolozeni = new int[0];
        this->broj = 0;
    }

    Student(char *ime, int *brojpolozeni, int broj) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->broj = broj;
        this->brojpolozeni = new int[broj];
        for (int i = 0; i < broj; i++) {
            this->brojpolozeni[i] = brojpolozeni[i];
        }
    }


    Student(const Student &s) {
        this->ime = new char[strlen(s.ime) + 1];
        strcpy(this->ime, s.ime);
        this->broj = s.broj;
        this->brojpolozeni = new int[s.broj];
        for (int i = 0; i < s.broj; i++) {
            this->brojpolozeni[i] = s.brojpolozeni[i];
        }
    }


    Student &operator=(const Student &s) {
        if (this != &s) {
            delete [] ime;
            delete [] brojpolozeni;
            this->ime = new char[strlen(s.ime) + 1];
            strcpy(this->ime, s.ime);
            this->broj = s.broj;
            this->brojpolozeni = new int[s.broj];
            for (int i = 0; i < s.broj; i++) {
                this->brojpolozeni[i] = s.brojpolozeni[i];
            }
        }
        return *this;
    }

    ~Student() {
        delete [] ime;
        delete [] brojpolozeni;
    }

    void addGrade(int grade) {
        int *tmp = new int[broj + 1];
        for (int i = 0; i < broj; i++) {
            tmp[i] = brojpolozeni[i];
        }
        tmp[broj++] = grade;
        delete [] brojpolozeni;
        brojpolozeni = tmp;
    }

    double average() const {
        double zbir = 0;
        for (int i = 0; i < broj; i++) {
            zbir += brojpolozeni[i];
        }

        return zbir / (double) broj;
    }

    friend ostream &operator<<(ostream &pecati, const Student &s) {
        pecati << s.ime << " - " << s.average() << " - ";
        if (s.average() < 6) {
            pecati << "BAD";
        } else if (s.average() >= 6 && s.average() < 9) {
            pecati << "GOOD";
        } else if (s.average() >= 9) {
            pecati << "EXCELLENT";
        }
        return pecati;
    }
};

int main() {
    Student s;
    int n;
    cin >> n;


    char ime[100];
    int *brojpolozeni;
    int broj;

    for (int i = 0; i < n; i++) {
        cin >> ime;

        cin >> broj;
        brojpolozeni = new int[broj];
        for (int j = 0; j < broj; j++) {
            cin >> brojpolozeni[j];
        }
        s = Student(ime, brojpolozeni, broj);

        int grade;
        cin >> grade;

        s.addGrade(grade);
        delete [] brojpolozeni;
    }

    cout<<s;
}
