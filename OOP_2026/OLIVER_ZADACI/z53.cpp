#include <iostream>
#include<cstring>
using namespace std;

class Course {
private:
    char *ime;
    int *listapoeni;
    int brojpoeni;

public:
    Course() {
        this->ime = new char[1];
        this->ime[0] = '\0';
        this->listapoeni= new int[0];
        this->brojpoeni=0;
    }

    Course( char *ime,int *listapoeni,int brojpoeni) {
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->brojpoeni=brojpoeni;
        this->listapoeni=new int[brojpoeni];
        for (int i=0;i<brojpoeni;i++) {
            this->listapoeni[i]=listapoeni[i];
        }

    }

    Course(const Course &c) {
        this->ime = new char[strlen(c.ime)+1];
        strcpy(this->ime,c.ime);
        this->brojpoeni=c.brojpoeni;
        this->listapoeni=new int[c.brojpoeni];
        for (int i=0;i<c.brojpoeni;i++) {
            this->listapoeni[i]=c.listapoeni[i];
        }

    }

    Course& operator=(const Course &c) {
        if (this!=&c) {
            delete [] ime;
            delete [] listapoeni;
            this->ime = new char[strlen(c.ime)+1];
            strcpy(this->ime,c.ime);
            this->brojpoeni=c.brojpoeni;
            this->listapoeni=new int[c.brojpoeni];
            for (int i=0;i<c.brojpoeni;i++) {
                this->listapoeni[i]=c.listapoeni[i];
            }
        }
        return *this;

    }
    ~Course() {
        delete [] ime;
        delete [] listapoeni;
    }

    void addPoints(int p) {
        int *tmp=new int[brojpoeni+1];
        for (int i=0;i<brojpoeni;i++) {
            tmp[i]=listapoeni[i];
        }
        tmp[brojpoeni]=p;
        brojpoeni++;
        delete[] listapoeni;
        listapoeni=tmp;

    }
    double average() const {
        int zbir=0;
        for (int i=0;i<brojpoeni;i++) {
            zbir+=listapoeni[i];
        }
        return (double)zbir/(double)brojpoeni;
    }


    Course & operator+=(int p) {
        int *tmp=new int[brojpoeni+1];
        for (int i=0;i<brojpoeni;i++) {
            tmp[i]=listapoeni[i];
        }
        tmp[brojpoeni]=p;
        brojpoeni++;
        delete[] listapoeni;
        listapoeni=tmp;
        return*this;

    }
    friend ostream & operator <<(ostream & pecati , const Course &c) {
        pecati<<c.ime<<" - "<<c.average()<<" - ";
        if (c.brojpoeni==0) {
            pecati<<"NO DATA";
        }
          else if (c.average()<50) {
            pecati<<"FAIL";
        }
        else if (c.average()>=50 && c.average()<79) {
            pecati<<"PASS";
        }
        else if (c.average()>=79) {
            pecati<<"EXCELLENT";
        }

        return pecati;
    }
};

int main() {
    Course c;

    char ime[100];
    int *listapoeni;
    int brojpoeni;

    cin>>ime;
    cin>>brojpoeni;
    listapoeni = new int[brojpoeni];
    for (int i=0;i<brojpoeni;i++) {
        cin>>listapoeni[i];
    }
    c=Course(ime,listapoeni,brojpoeni);

    int p;
    cin>>p;
    c.addPoints( p);
    cout<<c;
    return 0;
}
