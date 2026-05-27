#include <iostream>
#include<cstring>
#include <cmath>
using namespace std;

class Shape {
protected:
    int strana;

public:
    Shape() {
        this->strana = 0;
    }

    Shape(int strana) {
        this->strana = strana;
    }

    Shape(const Shape &s) {
        this->strana = s.strana;
    }

    virtual double plostina()=0;

    virtual void pecati()=0;

    virtual int getType()=0;
};
class Square:public Shape {
    protected:
public:
    Square(int strana):Shape(strana) {
    }
    virtual double plostina() {
        return strana*strana;
    }

    virtual void pecati() {
        cout<<"Square so plostina = "<<plostina()<<endl;

    }

    virtual int getType() {
        return 1;
    }
};



class Circle:public Shape {
protected:
public:
    Circle(int strana):Shape(strana) {
    }
    virtual double plostina() {
        return 3.14 * strana * strana;
    }

    virtual void pecati() {
        cout<<"Circle so plostina = "<<plostina()<<endl;
    }

    virtual int getType() {
        return 2;
    }
};


class Triangle:public Shape {
protected:
public:
    Triangle(int strana):Shape(strana) {
    }
    virtual double plostina() {
        return (sqrt(3)/4) * strana * strana;
    }

    virtual void pecati() {
        cout<<"Triangle so plostina = "<<plostina()<<endl;
    }

    virtual int getType() {
        return 3;
    }
};
void checkNumTypes(Shape** niza, int n) {
    int triagolnici=0,kvadrati=0,krugovi=0;

    for (int i=0;i<n;i++) {
        Triangle *t=dynamic_cast<Triangle *>(niza[i]);
        if (t) {
            triagolnici++;

        }


        Square *s=dynamic_cast<Square *>(niza[i]);
        if (s) {
            kvadrati++;

        }


        Circle *c=dynamic_cast<Circle *>(niza[i]);
        if (c) {
            krugovi++;

        }

    }
    cout<<"Broj na kvadrati vo nizata = "<<kvadrati<<endl;
    cout<<"Broj na krugovi vo nizata = "<<krugovi<<endl;
    cout<<"Broj na triagolnici vo nizata = "<<triagolnici<<endl;
}
int main() {

    int n;
    cin >> n;


    Shape **niza;

    niza = new Shape*[n];


    int classType;
    int side;

    for(int i = 0; i < n; ++i){

        cin >> classType;
        cin >> side;
        if(classType == 1){
            niza[i] =  new Square(side);
        }
        else if (classType == 2){
            niza[i] = new Circle(side);
        }
        else if (classType == 3){
            niza[i] = new Triangle(side);
        }
    }


    for(int i = 0; i < n; ++i){

        niza[i]->pecati();
    }

    checkNumTypes(niza, n);


    return 0;

}
