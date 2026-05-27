#include <iostream>
#include <cstring>
using namespace std;
class Mobilephone {
private:
    char model[50];
    int brmodel;
    int godina;
public:
Mobilephone() {
    strcpy(this->model,"");
    this->brmodel=0;
    this->godina=0;
}

Mobilephone(char model[50],int brmodel,int godina) {
    strcpy(this->model,model);
    this->brmodel=brmodel;
    this->godina=godina;
}

    Mobilephone(const Mobilephone &m) {
    strcpy(this->model,m.model);
    this->brmodel=m.brmodel;
    this->godina=m.godina;
}
    ~Mobilephone() {

}
    void print() {
    cout<<model<<" "<<brmodel<<" "<<"realese year:"<<godina<<endl;
}
};
class Owner {
private:
    char ime[50];
    char prezime[50];
    Mobilephone mobilentel;

public:
Owner() {
    strcpy(this->ime,"");
    strcpy(this->prezime,"");
    mobilentel=Mobilephone();

}
    Owner( char ime[50],char prezime[50],Mobilephone mobilentel) {
    strcpy(this->ime,ime);
    strcpy(this->prezime,prezime);
    this->mobilentel=mobilentel;


}

    Owner(const Owner &o) {
    strcpy(this->ime,o.ime);
    strcpy(this->prezime,o.prezime);
     this->mobilentel= o.mobilentel;

}


~Owner(){


}


void print(){
cout<<ime<<" "<<prezime<<endl;
    mobilentel.print();

}

};
int main() {
    char model[50];
    int brmodel;
    int godina;

    char ime[50];
    char prezime[50];

    // внес за MobilePhone
    cin >> model;
    cin >> brmodel;
    cin >> godina;

    Mobilephone phone(model, brmodel, godina);

    // внес за Customer
    cin >> ime;
    cin >> prezime;

    Owner c(ime, prezime, phone);

    // печатење
    c.print();

    return 0;
}