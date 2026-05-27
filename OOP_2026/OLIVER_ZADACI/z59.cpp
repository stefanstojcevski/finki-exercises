#include <iostream>
#include<cstring>
using namespace std;

class Hero {
protected:
    char *ime;
    char klasa[40];
    double damage;
    double speed;
    double power;
public:
    Hero() {
        this->ime=new char[0];
        strcpy(this->klasa,"");
        this->damage=0;
        this->speed=0;
        this->power=0;

    }

    Hero(  char *ime,char klasa[40],double damage,double speed,double power) {
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        strcpy(this->klasa,klasa);


        this->damage=damage;
        this->speed=speed;
        this->power=power;

    }

    Hero( const Hero &h) {
        this->ime=new char[strlen(h.ime)+1];
        strcpy(this->ime,h.ime);
        strcpy(this->klasa,h.klasa);

        this->damage=h.damage;
        this->speed=h.speed;
        this->power=h.power;

    }

    Hero & operator=( const Hero &h) {
        if (this!=&h) {
            delete [] ime;
            this->ime=new char[strlen(h.ime)+1];
            strcpy(this->ime,h.ime);
            strcpy(this->klasa,h.klasa);

            this->damage=h.damage;
            this->speed=h.speed;
            this->power=h.power;
        }
        return *this;

    }
    ~Hero() {
        delete [] ime;

    }

    double poweer() {
        return 0.4*damage+0.25*speed+0.35*power;
    }

    void print () {
        cout<<"ime - "<<ime<<endl;
        cout<<"damage - "<<damage<<endl;
        cout<<"speed - "<<speed<<endl;
        cout<<"power - "<<power<<endl;
        cout<<"Power: "<<poweer()<<endl;
    }
};
class LegendaryHero:public Hero {
protected:
   double legdamage;
    double legspeed;
    double legability;
public:
    LegendaryHero() {
        this->legdamage=0;
        this->legspeed=0;
        this->legability=0;

    }
    LegendaryHero( Hero heroes,double legdamage,double legspeed,double legability):Hero( heroes) {
        this->legdamage=legdamage;
        this->legspeed=legspeed;
        this->legability=legability;

    }

    LegendaryHero( char *ime,char klasa[40],double damage,double speed,double power,double legdamage,double legspeed,double legability):Hero( ime,klasa,damage,speed,power) {
        this->legdamage=legdamage;
        this->legspeed=legspeed;
        this->legability=legability;

    }

    LegendaryHero( const LegendaryHero &l):Hero( l) {
        this->legdamage=l.legdamage;
        this->legspeed=l.legspeed;
        this->legability=l.legability;

    }


    LegendaryHero& operator =( const LegendaryHero &l) {
        if (this!=&l) {
            this->legdamage=l.legdamage;
            this->legspeed=l.legspeed;
            this->legability=l.legability;

            delete [] ime;
            this->ime=new char[strlen(l.ime)+1];
            strcpy(this->ime,l.ime);
            strcpy(this->klasa,l.klasa);
            this->damage=l.damage;
            this->speed=l.speed;
            this->power=l.power;

        }
        return *this;
    }

    double legendaryPower() {
        return (0.25* legdamage)+(0.35* legspeed)+(0.4* legability);
    }

    double poweer() {
        double zbir= legendaryPower()+Hero::poweer();
        return zbir/2.0;

    }

    void print() {

      Hero::print();
cout<<"Legendary Power: "<<legendaryPower()<<endl;
cout<<"New Power: "<<poweer()<<endl;


    }


};

int main() {


    char name[50];
    char klasa[40];
    double attackDamage;
    double attackSpeed;
    double abilityPower;
    double legendaryAttackDamage;
    double legendaryAttackSpeed;
    double legendaryAbilityPower;

    Hero * heroes = new Hero[5];
    LegendaryHero * legendaryHeroes = new LegendaryHero[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "HEROES:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> klasa >> attackDamage >> attackSpeed >> abilityPower;
            heroes[i] = Hero(name, klasa, attackDamage, attackSpeed, abilityPower);
            heroes[i].print();
        }
    }
    else if (n == 2) {

        for (int i=0; i < 5; ++i){
            cin >> name >> klasa >> attackDamage >> attackSpeed >> abilityPower;
            cin >> legendaryAttackDamage >> legendaryAttackSpeed >> legendaryAbilityPower;
            heroes[i] = Hero(name, klasa, attackDamage, attackSpeed, abilityPower);
            legendaryHeroes[i] = LegendaryHero(heroes[i], legendaryAttackDamage, legendaryAttackSpeed, legendaryAbilityPower);
        }

        cout << "HEROES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            heroes[i].print();

        cout << "LEGENDARY HEROES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            legendaryHeroes[i].print();

    }
    else if (n == 3) {

        for (int i=0; i < 5; ++i){
            cin >> name >> klasa >> attackDamage >> attackSpeed >> abilityPower;
            cin >> legendaryAttackDamage >> legendaryAttackSpeed >> legendaryAbilityPower;
            legendaryHeroes[i] = LegendaryHero(name, klasa, attackDamage, attackSpeed, abilityPower, legendaryAttackDamage, legendaryAttackSpeed, legendaryAbilityPower);
        }
        cout << "LEGENDARY HEROES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            legendaryHeroes[i].print();

    }

    delete [] heroes;
    delete [] legendaryHeroes;
}
