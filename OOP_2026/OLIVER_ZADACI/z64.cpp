#include <iostream>
#include<cstring>
using namespace std;

class Library {
protected:
    string ime;
    string grad;
    double clanarina;
    bool zavikend;

public:
    Library() {
       this->ime="";
        this->grad = "";
        this->clanarina = 0;
        this->zavikend = false;
    }

    Library(string ime, string grad, double clanarina, bool zavikend) {
       this->ime=ime;
        this->grad = grad;
        this->clanarina = clanarina;
        this->zavikend = zavikend;
    }

    Library(const Library &l) {
       this->ime=l.ime;
        this->grad = l.grad;
        this->clanarina = l.clanarina;
        this->zavikend = l.zavikend;
    }

    Library &operator=(const Library &l) {
        if (this != &l) {
       this->ime=l.ime;
            this->grad = l.grad;
            this->clanarina = l.clanarina;
            this->zavikend = l.zavikend;
        }
        return *this;
    }

    virtual void printDetail() =0;

    virtual double calculateMembershipCardCost() =0;

    bool getZavikend() {

        return zavikend;

    }

    virtual ~Library() {}
};

class AcademicLibrary : public Library {
protected:
    bool istrazuvajne;
    int brkolekcii;

public:
    AcademicLibrary() {
        this->istrazuvajne = false;
        this->brkolekcii = 0;
    }

    AcademicLibrary(string ime, string grad, double clanarina, bool zavikend, bool istrazuvajne,
                    int brkolekcii) : Library(ime, grad, clanarina, zavikend) {
        this->istrazuvajne = istrazuvajne;
        this->brkolekcii = brkolekcii;
    }

    AcademicLibrary(const AcademicLibrary &a) : Library(a) {
        this->istrazuvajne = a.istrazuvajne;
        this->brkolekcii = a.brkolekcii;
    }

    AcademicLibrary &operator=(const AcademicLibrary &a) {
        if (this != &a) {
            this->istrazuvajne = a.istrazuvajne;
            this->brkolekcii = a.brkolekcii;

       this->ime=a.ime;
            this->grad = a.grad;
            this->clanarina = a.clanarina;
            this->zavikend = a.zavikend;
        }
        return *this;
    }

    double calculateMembershipCardCost() {
        if (istrazuvajne) {
            return clanarina * 1.24 + brkolekcii * 6;
        }
        return clanarina + brkolekcii * 6;
    }

    void printDetail() {
        cout << ime << " - (Academic) " << grad << " " << brkolekcii << " " << calculateMembershipCardCost() << endl;
    }
};

class NationalLibrary : public Library {
protected:
    bool edukativni;
    int brrakopisi;

public:
    NationalLibrary() {
        this->edukativni = false;
        this->brrakopisi = 0;
    }

    NationalLibrary(string ime, string grad, double clanarina, bool zavikend, bool edukativni,
                    int brrakopisi) : Library(ime, grad, clanarina, zavikend) {
        this->edukativni = edukativni;
        this->brrakopisi = brrakopisi;
    }

    NationalLibrary(const NationalLibrary &n) : Library(n) {
        this->edukativni = n.edukativni;
        this->brrakopisi = n.brrakopisi;
    }

    NationalLibrary &operator=(const NationalLibrary &n) {
        if (this != &n) {
            this->edukativni = n.edukativni;
            this->brrakopisi = n.brrakopisi;

       this->ime=n.ime;
            this->grad = n.grad;
            this->clanarina = n.clanarina;
            this->zavikend = n.zavikend;
        }
        return *this;
    }

    double calculateMembershipCardCost() {
        if (edukativni) {
            return clanarina * 0.93 + brrakopisi * 15;
        }
        return clanarina + brrakopisi * 15;
    }

    void printDetail() {
        cout << ime << " - (National) " << grad << " " << brrakopisi << " " << calculateMembershipCardCost() << endl;
    }
};

int findMostExpensiveNationalLibrary(Library **l, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        NationalLibrary *nl = dynamic_cast<NationalLibrary *>(l[i]);
        if (nl) {
            if (l[i]->calculateMembershipCardCost()>l[max]->calculateMembershipCardCost()) {
                max = i;
            }
            if (l[i]->calculateMembershipCardCost()==l[max]->calculateMembershipCardCost()) {
                if (l[i]->getZavikend()==true) {
                    max=i;
                }
            }

        }
        else {
            max=-1;
        }
    }
    return max;

}

int main() {
    int n, testCase, type;
    cin >> testCase >> n;
    cin.ignore();

    Library** m = new Library*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        bool weekend_working;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> weekend_working;
        cin.ignore();

        if (type == 1) {
            bool open_cooperation;
            int specialized_articles;

            cin >> open_cooperation >> specialized_articles;
            cin.ignore();

            m[i] = new AcademicLibrary(name, city, base_price, weekend_working, open_cooperation, specialized_articles);
        } else {
            bool cultural_program;
            int national_articles;

            cin >> cultural_program >> national_articles;
            cin.ignore();

            m[i] = new NationalLibrary(name, city, base_price, weekend_working, cultural_program, national_articles);
        }
    }

    if(testCase == 1){
        cout << "Abstract and child classes OK" << endl;
    }
    else if(testCase == 2){
        for(int i = 0; i < n; i++){
            cout << m[i]->calculateMembershipCardCost() << endl;
        }
        cout << "calculateMembershipCardCost method OK" << endl;
    }
    else if(testCase == 3){
        for(int i = 0; i < n; i++){
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    }
    else if(testCase == 4){
        int most_expensive_nat_lib_index = findMostExpensiveNationalLibrary(m, n);
        if(most_expensive_nat_lib_index>=0){
            m[most_expensive_nat_lib_index]->printDetail();
        }else{
            cout << "National Library not found in the array!"<<endl;
        }
        cout << "findMostExpensiveNationalLibrary method OK" << endl;
    }


    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}