#include <iostream>
using namespace std;
class Atom {
private:
    char symbol[3];
    double weight;
public:
    Atom() {
        strcpy(this->symbol,"");
        this->weight=0;
    }

    Atom( char symbol[2],int weight) {
        strcpy(this->symbol,symbol);
        this->weight=weight;
    }

    Atom(const Atom &a) {
        strcpy(this->symbol,a.symbol);
        this->weight=a.weight;
    }

    Atom& operator=(const Atom &a) {
        if (this!=&a) {
            strcpy(this->symbol,a.symbol);
            this->weight=a.weight;
        }
        return *this;
    }

    ~Atom() {

    }


    bool operator==(const Atom &a) {
        if (strcmp(symbol,a.symbol)) {
            return true;
        }
        return false;
    }

    double getWeight() {
        return weight;
    }
    friend class Molecule;
};

class Molecule {
private:
    Atom *atoms;
    int n;
public:
    Molecule() {
        this->atoms=nullptr;
        this->n=0;
    }

    Molecule( Atom *atoms,int n) {
        this->n=n;
        this->atoms=new Atom[n];
        for (int i=0;i<n;i++) {
           this-> atoms[i]=atoms[i];
        }
    }

    Molecule( const Molecule &m) {
        this->n=m.n;
        this->atoms=new Atom[m.n];
        for (int i=0;i<m.n;i++) {
            this-> atoms[i]=m.atoms[i];
        }
    }

    Molecule& operator =( const Molecule &m) {
        if (this!=&m){
            delete [] atoms;
        this->n=m.n;
        this->atoms=new Atom[m.n];
        for (int i=0;i<m.n;i++) {
            this-> atoms[i]=m.atoms[i];
        }
        }
        return *this;
    }


    ~Molecule() {
        delete [] atoms;
    }


    double getMolecularWeight() const{
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += atoms[i].getWeight();
        }
        return sum;
    }

    friend ostream& operator<<(ostream &pecati,const Molecule &m ) {
        pecati<<"Complete/Full test."<<endl;

        for (int i = 0; i < m.n; i++) {

            // печати симбол
            pecati << m.atoms[i].symbol;

            int count = 1;

            // брои исти атоми
            while (i + 1 < m.n && strcmp(m.atoms[i].symbol, m.atoms[i + 1].symbol) == 0) {
                count++;
                i++;
            }

            // ако има повеќе од 1 → печати број
            if (count > 1) {
                pecati << count;
            }
        }

        pecati << " --- " << m.getMolecularWeight() << endl;

        return pecati;
    }
    Molecule operator+(const Molecule &m) {
        Molecule result;

        result.n = this->n + m.n;
        result.atoms = new Atom[result.n];

        for (int i = 0; i < this->n; i++) {
            result.atoms[i] = this->atoms[i];
        }

        for (int i = 0; i < m.n; i++) {
            result.atoms[this->n + i] = m.atoms[i];
        }

        return result;
    }

    Molecule operator+(const Atom &a) {
        Molecule result;

        result.n = this->n + 1;
        result.atoms = new Atom[result.n];

        for (int i = 0; i < this->n; i++) {
            result.atoms[i] = this->atoms[i];
        }

        result.atoms[this->n] = a;

        return result;
    }


    friend Molecule operator+(const Atom &a1, const Atom &a2) {
        Atom temp[2];
        temp[0] = a1;
        temp[1] = a2;

        return Molecule(temp, 2);
    }

};



int main() {
    int testcase;
    cin >> testcase;
    switch (testcase) {
        case 0: {
            cout << "Testing Atom constructors and operators ==, =" << endl;
            Atom a1("H", 1.001);
            Atom a2("O", 15.997);
            Atom a3(a1);
            cout << (a1 == a3) << endl << (a2 == a3) << endl;
            a3 = a2;
            cout << (a1 == a3) << endl << (a2 == a3) << endl;
            break;
        }
        case 1: {
            cout << "Testing Molecule constructors, methods and operator =" << endl;
            Atom atoms[5];
            Atom c("C", 12.0096);
            Atom h("H", 1.001);
            atoms[0] = c;
            for (int i = 0; i < 4; ++i) {
                atoms[i + 1] = h;
            }

            Molecule m1(atoms, 5);
            Molecule m2(atoms, 3);
            Molecule m3(m1);

            cout << m1.getMolecularWeight() << endl << m2.getMolecularWeight() << endl;
            cout << m3.getMolecularWeight() << endl;

            m3 = m2;
            cout << m3.getMolecularWeight() << endl;
            break;
        }
        case 2: {
            cout << "Testing operator << on Molecule" << endl;

            Atom c("C", 12.0096);
            Atom h("H", 1.001);
            Atom o("O", 15.997);
            Atom cl("Cl", 35.45);

            Atom atoms0[3];
            atoms0[0] = h;
            atoms0[1] = h;
            atoms0[2] = o;
            cout << Molecule(atoms0, 3) << endl;  // H20

            atoms0[0] = h;
            atoms0[1] = o;
            atoms0[2] = h;
            cout << Molecule(atoms0, 3) << endl;  // HOH

            Atom atoms[5];
            atoms[0] = c;
            for (int i = 0; i < 4; ++i) atoms[i + 1] = h;

            cout << Molecule(atoms, 5) << endl;  // CH4

            Atom atoms1[10];

            for (int i = 0; i < 10; ++i) {
                if (i < 3) atoms1[i] = c;
                else if (i < 8) atoms1[i] = h;
                else if (i == 8) atoms1[i] = cl;
                else atoms1[i] = o;
            }

            cout << Molecule(atoms1, 10) << endl;  // C3H5ClO

            cout << endl << "[Formatting help: Print the atoms" << endl << "in the order of the atoms array." << endl;
            cout << "Consecutive atoms that are" << endl << "the same should be counted." << endl << "Then print the molecule weight.]" << endl;
            break;
        }
        case 3: {
            cout << "Testing operator + on class Molecule." << endl;
            Molecule m1, m2;
            Atom c("C", 12.0096);
            Atom h("H", 1.001);
            Atom o("O", 15.997);
            Atom cl("Cl", 35.45);
            Atom n("N", 14.006);

            m1 = c + h ;
            m2 = cl + n + o;
            cout << (m1 + m2) << endl;
            break;
        }
        case 4: {
            cout << "Complete/Full test." << endl;
            Molecule m, m1, m2;
            Atom c("C", 12.0096);
            Atom h("H", 1.001);
            Atom o("O", 15.997);
            Atom cl("Cl", 35.45);
            Atom n("N", 14.006);

            char input[10];
            int i = 1;
            while (true) {
                i = i == 0 ? 1 : 0;
                cin >> input;
                if (input[0] == 'E') return 0;
                while (input[0] != '.' && input[0] != '+') {
                    switch (input[0]) {
                        case 'H':
                            m = m + h;
                            break;
                        case 'O':
                            m = m + o;
                            break;
                        case 'N':
                            m = m + n;
                            break;
                        case 'C':
                            if (input[1] == 'l') m = m + cl;
                            else m = m + c;
                            break;
                    }
                    cin >> input;
                }
                if (i == 0) {
                    m1 = m;
                    m = Molecule();
                } else {
                    m2 = m;
                    cout << (m1 + m2) << endl;
                    m = Molecule();
                }
            }
        }
    }
}