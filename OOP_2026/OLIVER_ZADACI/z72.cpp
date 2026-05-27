#include <iostream>
#include <cstring>
using namespace std;

class Athlete {
protected:
    char name[50];
    int age;

public:
    Athlete() {
        strcpy(this->name, "");
        this->age = 0;
    }

    Athlete(char name[50], int age) {
        strcpy(this->name, name);
        this->age = age;
    }

    Athlete(const Athlete &a) {
        strcpy(this->name, a.name);
        this->age = a.age;
    }

    virtual void displayInfo() {
        cout << name << " " << age << endl;
    }
    virtual ~Athlete() {}
};

class Runner : public Athlete {
protected:
    double speed;

public:
    Runner() {
        this->speed = 0;
    }

    Runner(char name[50], int age, double speed) : Athlete(name, age) {
        this->speed = speed;
    }

    Runner(const Runner &r) : Athlete(r) {
        this->speed = r.speed;
    }

    void displayInfo() {
        cout << name << " " << age << " " << speed << endl;
    }
    double getSpeed() {
        return speed;
    }
};

class Jumper : public Athlete {
protected:
    double height;

public:
    Jumper() {
        this->height = 0;
    }

    Jumper(char name[50], int age, double height) : Athlete(name, age) {
        this->height = height;
    }

    Jumper(const Jumper &j) : Athlete(j) {
        this->height = j.height;
    }

    void displayInfo() {
        cout << name << " " << age << " " << height << endl;
    }
    double getHeight() {
        return height;
    }
};

class AllRoundAthlete : public Runner, public Jumper {
protected:
    int stamina;

public:
    AllRoundAthlete() {
        this->stamina = 0;
    }

    AllRoundAthlete(char name[50], int age, double speed, double height, int stamina) : Runner(name, age, speed),
        Jumper(name, age, height) {
        this->stamina = stamina;
    }

    AllRoundAthlete(const AllRoundAthlete &e) : Runner(e), Jumper(e) {
        this->stamina = e.stamina;
    }

    void displayInfo() {
        cout << "Athlete: " << Runner::name << endl;
        cout << "Age: " << Runner::age << endl;
        cout << "Speed: " << speed << " mph" << endl;
        cout << "Height: " << height << " m" << endl;
        cout << "Stamina: " << stamina << endl;
    }

};
Athlete* findAthleteWithMaxValue(Athlete** athletes, int n) {
    Athlete *maxAthlete = nullptr;

    double maxValue = -1;

    for (int i = 0; i < n; i++) {

        Runner *r = dynamic_cast<Runner*>(athletes[i]);

        if (r) {

            if (r->getSpeed() > maxValue) {

                maxValue = r->getSpeed();

                maxAthlete = athletes[i];

            }

        }

        Jumper *j = dynamic_cast<Jumper*>(athletes[i]);

        if (j) {

            if (j->getHeight() > maxValue) {

                maxValue = j->getHeight();

                maxAthlete = athletes[i];

            }

        }

    }

    return maxAthlete;
}
int main() {
    char name[50];
    int age;
    double speed;
    double height;
    int n;
    int choice;

    cin >> choice;
    if (choice == 1) {
        cin >> name >> age;
        AllRoundAthlete allRoundAthlete(name, age, 13.6, 1.80, 6);
        allRoundAthlete.displayInfo();
    } else {
        cin >> n;
        Athlete **athletes = new Athlete *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> age >> speed;
                athletes[i] = new Runner(name, age, speed);
            } else {
                cin >> name >> age >> height;
                athletes[i] = new Jumper(name, age, height);
            }
        }

        Athlete *mostPowerful = findAthleteWithMaxValue(athletes, n);
        if (mostPowerful) {
            mostPowerful->displayInfo();
        } else {
            cout << "No athlete found." << endl;
        }

        for (int i = 0; i < n; ++i) {
            delete athletes[i];
        }
        delete[] athletes;
    }

    return 0;
}
