#include <iostream>
#include <cstring>
using namespace std;
enum GeneticMechanism {
    RNA=0,
    DNA=1
};

enum sostojki {
    DMG=0,
    PEG=1,
    SM_102=2,
    DPSC=3
};
class CovidVaccine {
protected:
    char proizvoditel[100];
    char *ime;
    int efikasnost;
public:
    CovidVaccine() {
        strcpy(this->proizvoditel,"");
        this->ime=new char[0];
        this->efikasnost=0;
    }
    CovidVaccine( char proizvoditel[100],char *ime,int efikasnost) {
        strcpy(this->proizvoditel,proizvoditel);
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->efikasnost=efikasnost;
    }
    CovidVaccine( const CovidVaccine &c ) {
        strcpy(this->proizvoditel,c.proizvoditel);
        this->ime=new char[strlen(c.ime)+1];
        strcpy(this->ime,c.ime);
        this->efikasnost=c.efikasnost;
    }
    CovidVaccine& operator =( const CovidVaccine &c ) {
        if (this!=&c) {
            delete [] ime;
            strcpy(this->proizvoditel,c.proizvoditel);
            this->ime=new char[strlen(c.ime)+1];
            strcpy(this->ime,c.ime);
            this->efikasnost=c.efikasnost;
        }
        return *this;
    }
    virtual ~CovidVaccine() {
        delete [] ime;
    }
    virtual float calculateVaccineEfficiency()const =0;

bool operator <=(const CovidVaccine &c ) const{
    if (calculateVaccineEfficiency()<=c.calculateVaccineEfficiency()) {
        return true;
    }
    return false;
}
};
class GeneticVaccine:public CovidVaccine {
protected:
    GeneticMechanism ovailiova;
public:
    GeneticVaccine() {
        this->ovailiova=RNA;
    }
    GeneticVaccine(char proizvoditel[100],char *ime,int efikasnost, unsigned short ovailiova):CovidVaccine(proizvoditel,ime,efikasnost) {
        this->ovailiova=(GeneticMechanism) ovailiova;
    }
    GeneticVaccine(const GeneticVaccine &g ):CovidVaccine(g) {
        this->ovailiova=g.ovailiova;
    }

    GeneticVaccine& operator =(const GeneticVaccine &g ) {
        if (this!=&g) {
            this->ovailiova=g.ovailiova;
            delete [] ime;
            strcpy(this->proizvoditel,g.proizvoditel);
            this->ime=new char[strlen(g.ime)+1];
            strcpy(this->ime,g.ime);
            this->efikasnost=g.efikasnost;

        }
        return *this;
    }

    float calculateVaccineEfficiency()const  {
        if (ovailiova==RNA) {
            return efikasnost*1.35;
        }
        return efikasnost*1.55;
    }

    friend ostream& operator<<(ostream& pecati,const GeneticVaccine &g) {
        pecati<<"Vaccine info: "<<g.ime<<" - "<<g.proizvoditel<<" - "<<g.calculateVaccineEfficiency()<<
            "Mechanism for storing genetic information: "<<g.ovailiova<<endl;
        return pecati;
    }

};

class InactivatedVaccine:public CovidVaccine {
protected:
    sostojki sostojkii;
public:
    InactivatedVaccine() {
        this->sostojkii=DMG;
    }
    InactivatedVaccine(char proizvoditel[100],char *ime,int efikasnost,unsigned short sostojkii):CovidVaccine(proizvoditel,ime,efikasnost) {
        this-> sostojkii= (sostojki)sostojkii;
    }
    InactivatedVaccine(const InactivatedVaccine &i):CovidVaccine(i) {
        this-> sostojkii= i.sostojkii;
    }
    InactivatedVaccine& operator =(const InactivatedVaccine &i) {
        if (this!=&i) {
            this-> sostojkii= i.sostojkii;
            delete [] ime;
            strcpy(this->proizvoditel,i.proizvoditel);
            this->ime=new char[strlen(i.ime)+1];
            strcpy(this->ime,i.ime);
            this->efikasnost=i.efikasnost;
        }
        return *this;
    }

    float calculateVaccineEfficiency() const {
        if (sostojkii==DMG) {
            return efikasnost*0.90;
        }
        else if (sostojkii==PEG) {
            return efikasnost*1.12;
        }
        else if (sostojkii==SM_102) {
            return efikasnost*0.85;
        }
        else if (sostojkii==DPSC) {
            return efikasnost*1.20;
        }
    }
    friend ostream& operator<<(ostream& pecati,const InactivatedVaccine &i) {
        pecati<<"Vaccine info: "<<i.ime<<" - "<<i.proizvoditel<<" - "<<i.calculateVaccineEfficiency()<<
            "The vaccine consists of the following ingredient: "<<i.sostojkii<<endl;
        return pecati;
    }
};


void mostEffectiveInactivatedVaccine(CovidVaccine **covidi,int n) {
    int max=-1;
    for (int i=0;i<n;i++) {
        InactivatedVaccine *j=dynamic_cast<InactivatedVaccine *>(covidi[i]);
        if (j) {
            if (max=-1 ||covidi[max]->calculateVaccineEfficiency() <= covidi[i]->calculateVaccineEfficiency()) {
                max=i;
            }


        }
    }
    if (max!=-1) {
        cout<<*(dynamic_cast<InactivatedVaccine *>(covidi[max]));

    }


}
int main() {
    int test_case;

    cin >> test_case;

    //For CovidVaccine
    char manufacturer[100];
    char vaccineName[100];
    float basicEfficiencyCoefficient;

    //For GeneticVaccine
    unsigned short geneticMechanism; // 0 -> RNA, 1 -> DNA

    //For InactivatedVaccine
    unsigned short constituentIngredient; //0 -> DMG, 1 -> PEG, 2 -> SM_102, 3 -> DPSC


    if (test_case == 1) {
        // Test Case GeneticVaccine - Constructor, operator <<, calculateVaccineEfficiency
        cout << "Testing class GeneticVaccine, operator<< and calculateVaccineEfficiency" << endl;
        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        cout << gv;
    } else if (test_case == 2) {
        // Test Case InactivatedVaccine - Constructor, operator <<, calculateVaccineEfficiency
        cout << "Testing class InactivatedVaccine, operator<< and calculateVaccineEfficiency" << endl;
        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> constituentIngredient;

        InactivatedVaccine iv(manufacturer, vaccineName, basicEfficiencyCoefficient, constituentIngredient);

        cout << iv;
    } else if (test_case == 3) {
        cout << "Testing operator <=" << endl;

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> constituentIngredient;

        InactivatedVaccine iv(manufacturer, vaccineName, basicEfficiencyCoefficient, constituentIngredient);

        if (gv <= iv) {
            cout << iv;
        } else {
            cout << gv;
        }
    } else if (test_case == 4) {
        cout << "Testing operator <=" << endl;

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv1(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv2(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        if (gv1 <= gv2) {
            cout << gv2;
        } else {
            cout << gv1;
        }
    } else if (test_case == 5) {
        cout << "Testing function: mostEffectiveInactivatedVaccine " << endl;

        //1 - GeneticVaccine
        //2 - InactivatedVaccine
        short vaccineType;

        int number_of_vaccines;
        CovidVaccine **vaccine_array;

        cin >> number_of_vaccines;

        vaccine_array = new CovidVaccine *[number_of_vaccines];

        for (int i = 0; i < number_of_vaccines; ++i) {
            cin >> vaccineType;

            cin.get();
            cin.getline(manufacturer, 100);
            cin.getline(vaccineName, 100);
            cin >> basicEfficiencyCoefficient;

            switch (vaccineType) {
                case 1:
                    cin >> geneticMechanism;
                    vaccine_array[i] = new GeneticVaccine(manufacturer, vaccineName, basicEfficiencyCoefficient,
                                                          geneticMechanism);
                    break;
                case 2:
                    cin >> constituentIngredient;
                    vaccine_array[i] = new InactivatedVaccine(manufacturer, vaccineName, basicEfficiencyCoefficient,
                                                              constituentIngredient);
                    break;
            }

        }

        mostEffectiveInactivatedVaccine(vaccine_array, number_of_vaccines);
        delete[] vaccine_array;
    }

    return 0;
}

