#include<iostream>
using namespace std;

class Number {
public:
    virtual double doubleValue() =0;

    virtual int intValue() =0;

    virtual void print() =0;
};

//TODO preoptovaruvanje na operatorot ==///////////////////////////////////////
bool operator==(Number *eden, Number &dva) {
    if (eden->doubleValue() == dva.doubleValue()) {
        return true;
    }
    return false;
}


class Integer : public Number {
    //TODO da se dodadi izraz za nasleduvanje od Number////////////////////////////
private:
    int brojka;

public:
    //TODO da se deklariraat promenlivite/////////////////////////
    //TODO konstruktor so eden argument//////////////////////////
    Integer() {
        this->brojka = 0;
    }

    Integer(int brojka) {
        this->brojka = brojka;
    }

    //TODO da se prepokrijat metodite od klasata Number///////////////////
    virtual double doubleValue() {
        return (double) brojka;
    }

    virtual int intValue() {
        return brojka;
    }

    virtual void print() {
        cout << "Integer: " << brojka << endl;
    }
};

class Double : public Number {
    //TODO da se dodadi izraz za nasleduvanje od Number/////////////////////
private:
    double broj;

public:
    //TODO konstruktor so eden argument/////////////////////////
    Double() {
        this->broj = 0;
    }

    Double(double broj) {
        this->broj = broj;
    }

    //TODO da se prepokrijat metodite od klasata Number/////////////////////////
    virtual double doubleValue() {
        return (double) broj;
    }

    virtual int intValue() {
        return broj;
    }

    virtual void print() {
        cout << "Double: " << broj << endl;
    }
};

class Numbers {
private:
    Number **numbers;
    int brele;
    //TODO deklariranje na promenlivite\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    public:
    //TODO default konstruktor\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    Numbers() {
        this->brele = 0;
        this->numbers = nullptr;
    }

    Numbers(Number **numbers, int brele) {
        this->brele = brele;
        this->numbers = new Number *[brele];
        for (int i = 0; i < brele; i++) {
            this->numbers[i] = numbers[i];
        }
    }

    //TODO copy konstruktor///////////////////////////////
    Numbers(const Numbers &u) {
        this->brele = u.brele;
        this->numbers = new Number *[u.brele];
        for (int i = 0; i < u.brele; i++) {
            this->numbers[i] = u.numbers[i];
        }
    }

    //TODO operator =///////////////////////////////
    Numbers &operator=(const Numbers &u) {
        if (this != &u) {
            delete [] numbers;
            this->brele = u.brele;
            this->numbers = new Number *[u.brele];
            for (int i = 0; i < u.brele; i++) {
                this->numbers[i] = u.numbers[i];
            }
        }
        return *this;
    }

    //TODO destruktor////////////////////////
    ~Numbers() {
        delete [] numbers;
    }

    //TODO operator += (operatorot da prima pointer od objekt od Number, a ne referenca)/////////////
    Numbers &operator+=(Number *n) {
        for (int i = 0; i < brele; i++) {
            if (numbers[i] == *n) {
                return *this;
            }
        }
        Number **temp = new Number *[brele + 1];
        for (int i = 0; i < brele; i++) {
            temp[i] = numbers[i];
        }
        temp[brele++] = n;
        delete [] numbers;
        numbers = temp;
        return *this;
    }

    //TODO void statistics()//////////////
    void statistics() {
        int countAll = 0;
        double sumAll = 0;

        int countInt = 0;
        int sumInt = 0;

        int countDouble = 0;
        double sumDouble = 0;

        for (int i = 0; i < brele; i++) {
            countAll++;
            sumAll+=numbers[i]->doubleValue();
                Integer *in=dynamic_cast<Integer *>(numbers[i]);
                if (in) {
                    countInt++;
                    sumInt+=numbers[i]->doubleValue();
                }
                Double *du=dynamic_cast<Double *>(numbers[i]);
                if (du) {
                    countDouble++;
                    sumDouble+=numbers[i]->doubleValue();
                }


        }
        cout << " Sum of all numbers: " << sumAll << endl;

        cout << "Count of integer numbers: " << countInt << endl;

        cout << "Sum of integer numbers: " << sumInt << endl;

        cout << "Count of double numbers: " << countDouble << endl;

        cout << "Sum of double numbers: " << sumDouble << endl;
    }


    //TODO void integersLessThan (Integer n)/////////////////////
    void integersLessThan (Integer n) {
        for (int i = 0; i < brele; i++) {
            Integer *in=dynamic_cast<Integer*>(numbers[i]);
            if (in) {
                if (in->intValue()<n.intValue()) {
                    in->print();
                    cout<<endl;
                }

            }
        }
    }

    //TODO void doublesBiggerThan (Double n)
    void doublesBiggerThan (Double n) {
        for (int i = 0; i < brele; i++) {
            Double *du=dynamic_cast<Double*>(numbers[i]);
            if (du) {
                if (du->doubleValue()>n.doubleValue()) {
                    du->print();
                    cout<<endl;
                }

            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    Numbers numbers;
    for (int i = 0; i < n; i++) {
        int type;
        double number;
        cin >> type >> number;
        if (type == 0) {
            //Integer object
            Integer *integer = new Integer((int) number);
            numbers += integer;
        } else {
            Double *doublee = new Double(number);
            numbers += doublee;
        }
    }

    int lessThan;
    double biggerThan;

    cin >> lessThan;
    cin >> biggerThan;

    cout << "STATISTICS FOR THE NUMBERS\n";
    numbers.statistics();
    cout << "INTEGER NUMBERS LESS THAN " << lessThan << endl;
    numbers.integersLessThan(Integer(lessThan));
    cout << "DOUBLE NUMBERS BIGGER THAN " << biggerThan << endl;
    numbers.doublesBiggerThan(Double(biggerThan));

    return 0;
}
