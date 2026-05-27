#include <iostream>
#include<cstring>
using namespace std;

class Igrachka {
public:
    virtual float getVolumen() = 0;

    virtual float getMasa() = 0;

    virtual float getPlostina() = 0;
};

class Forma {
protected:
    char boja[100];
    int gustina;

public:
    Forma() {
        strcpy(this->boja, "");

        this->gustina = 0;
    }

    Forma(char *boja, int gustina) {
        strcpy(this->boja, boja);
        this->gustina = gustina;
    }

    ~Forma() {
    }

};

class Topka : public Forma, public Igrachka {
private:
    int radius;

public:
    Topka()  {
        this->radius = 0;
    }

    Topka(char *boja, int gustina, int radius) : Forma(boja, gustina) {
        this->radius = radius;
    }

    float getVolumen() {
        return (4.0 / 3) * 3.14 * radius * radius * radius;
    }

    float getMasa() {
        return getVolumen() * gustina;
    }

    float getPlostina() {
        return 4 * 3.14 * radius * radius;
    }
};

class Kocka : public Forma, public Igrachka {
private:
    int visina;
    int shirina;
    int dlobochina;

public:
    Kocka() : Forma() {
        this->visina = 0;
        this->shirina = 0;
        this->dlobochina = 0;
    }

    Kocka(char *boja, int gustina, int visina, int shirina, int dlobochina)
        : Forma(boja, gustina) {
        this->visina = visina;
        this->shirina = shirina;
        this->dlobochina = dlobochina;
    }

    float getVolumen() {
        return visina * shirina * dlobochina;
    }

    float getMasa() {
        return getVolumen() * gustina;
    }

    float getPlostina() {
        return 2 * (visina * shirina + visina * dlobochina + shirina * dlobochina);
    }
};



int main() {
    //vnesi informacii za kupche

    //vnesi informacii za igrachkata na Petra
}
