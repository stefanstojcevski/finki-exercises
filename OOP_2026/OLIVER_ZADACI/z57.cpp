#include <iostream>
#include<cstring>
using namespace std;

class MarathonRunner {
protected:
    char *ime;
    char zemja[40];
    double prosecnabrzina;
    double vkupnadolzina;
    double vreme;

public:
    MarathonRunner() {
        this->ime = new char[0];
        strcpy(this->zemja, "");
        this->prosecnabrzina = 0;
        this->vkupnadolzina = 0;
        this->vreme = 0;
    }

    MarathonRunner(char *ime, char zemja[40], double prosecnabrzina, double vkupnadolzina, double vreme) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        strcpy(this->zemja, zemja);
        this->prosecnabrzina = prosecnabrzina;
        this->vkupnadolzina = vkupnadolzina;
        this->vreme = vreme;
    }

    MarathonRunner(const MarathonRunner &m) {
        this->ime = new char[strlen(m.ime) + 1];
        strcpy(this->ime, m.ime);
        strcpy(this->zemja, m.zemja);
        this->prosecnabrzina = m.prosecnabrzina;
        this->vkupnadolzina = m.vkupnadolzina;
        this->vreme = m.vreme;
    }

    MarathonRunner &operator=(const MarathonRunner &m) {
        if (this != &m) {
            delete [] ime;
            this->ime = new char[strlen(m.ime) + 1];
            strcpy(this->ime, m.ime);
            strcpy(this->zemja, m.zemja);
            this->prosecnabrzina = m.prosecnabrzina;
            this->vkupnadolzina = m.vkupnadolzina;
            this->vreme = m.vreme;
        }
        return *this;
    }

    ~MarathonRunner() {
        delete[] ime;
    }

    double rating() {
        return ((prosecnabrzina * 0.45) + (vkupnadolzina * 0.3) + (vreme * 0.25));
    }

    void print() {
        cout << ime << endl;

        cout << "Average speed: " << prosecnabrzina << endl;

        cout << "Total distance: " << vkupnadolzina << endl;

        cout << "Тotal time: " << vreme << endl;

        cout << "Rating: " << rating() << endl;
    }
};

class EliteMarathonRunner : public MarathonRunner {
private:
    double EliteavgSpeed;
    double Elitedistance;
    double Elitetime;

public:
    EliteMarathonRunner() {
        this->EliteavgSpeed = 0;
        this->Elitedistance = 0;
        this->Elitetime = 0;
    }

    EliteMarathonRunner(MarathonRunner &marathonrunners, double EliteavgSpeed, double Elitedistance,
                        double Elitetime) : MarathonRunner(marathonrunners) {
        this->EliteavgSpeed = EliteavgSpeed;
        this->Elitedistance = Elitedistance;
        this->Elitetime = Elitetime;
    }


    EliteMarathonRunner(char *ime, char zemja[40], double prosecnabrzina, double vkupnadolzina, double vreme,
                        double EliteavgSpeed, double Elitedistance, double Elitetime) : MarathonRunner(
        ime, zemja, prosecnabrzina, vkupnadolzina, vreme) {
        this->EliteavgSpeed = EliteavgSpeed;
        this->Elitedistance = Elitedistance;
        this->Elitetime = Elitetime;
    }

    EliteMarathonRunner(const EliteMarathonRunner &e) : MarathonRunner(e) {
        this->EliteavgSpeed = e.EliteavgSpeed;
        this->Elitedistance = e.Elitedistance;
        this->Elitetime = e.Elitetime;
    }

    EliteMarathonRunner &operator=(const EliteMarathonRunner &e) {
        if (this != &e) {
            this->EliteavgSpeed = e.EliteavgSpeed;
            this->Elitedistance = e.Elitedistance;
            this->Elitetime = e.Elitetime;
            delete [] ime;
            this->ime = new char[strlen(e.ime) + 1];
            strcpy(this->ime, e.ime);
            strcpy(this->zemja, e.zemja);
            this->prosecnabrzina = e.prosecnabrzina;
            this->vkupnadolzina = e.vkupnadolzina;
            this->vreme = e.vreme;
        }
        return *this;
    }

    ~EliteMarathonRunner() {
    }

    double eliteRating() {
        return EliteavgSpeed * 0.7 + vkupnadolzina * 0.1 + vreme * 0.3;
    }

    double rating() {
        return eliteRating() + rating();
    }

    void print() {
        MarathonRunner::print();
        cout << "Elite Rating: " << rating() << endl;
        cout << "New Rating: " << eliteRating() << endl;
    }
};

int main() {
    char name[50];
    char country[40];
    double avgSpeed;
    double distance;
    double time;
    double EliteavgSpeed;
    double Elitedistance;
    double Elitetime;

    MarathonRunner *RUNNERs = new MarathonRunner[5];
    EliteMarathonRunner *elRUNNERs = new EliteMarathonRunner[5];
    int n;
    cin >> n;

    if (n == 1) {
        cout << "MARATHON RUNNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> country >> avgSpeed >> distance >> time;
            RUNNERs[i] = MarathonRunner(name, country, avgSpeed, distance, time);
            RUNNERs[i].print();
        }
    } else if (n == 2) {
        for (int i = 0; i < 5; ++i) {
            cin >> name >> country >> avgSpeed >> distance >> time;
            cin >> EliteavgSpeed >> Elitedistance >> Elitetime;
            RUNNERs[i] = MarathonRunner(name, country, avgSpeed, distance, time);
            elRUNNERs[i] = EliteMarathonRunner(RUNNERs[i], EliteavgSpeed, Elitedistance, Elitetime);
        }

        cout << "NBA RUNNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            RUNNERs[i].print();

        cout << "ELITE RUNNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            elRUNNERs[i].print();
    } else if (n == 3) {
        for (int i = 0; i < 5; ++i) {
            cin >> name >> country >> avgSpeed >> distance >> time;
            cin >> EliteavgSpeed >> Elitedistance >> Elitetime;
            elRUNNERs[i] = EliteMarathonRunner(name, country, avgSpeed, distance, time,
                                               EliteavgSpeed, Elitedistance, Elitetime);
        }
        cout << "ELITE RUNNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            elRUNNERs[i].print();
    }

    delete [] RUNNERs;
    delete [] elRUNNERs;
}
