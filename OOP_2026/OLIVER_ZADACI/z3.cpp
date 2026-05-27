#include<iostream>
#include<iomanip>
using namespace std;
struct Student{
    char ime[100];
    int index;
    int brojKursevi;
    int nizaKodovi[100];
};
struct Course{
    char ime[100];
    int kod;
    int broj_studenti;
};

int get_most_popular_course(struct Course courses[],int brojKursevi){
    int maxKurs=0;
    for(int i=0;i<brojKursevi;i++){
        if(courses[i].broj_studenti>courses[maxKurs].broj_studenti){
            maxKurs=i;
        }
    }
    return maxKurs;
}

int main(){

    int broj_studenti,broj_kursevi;
    cin>>broj_studenti>>broj_kursevi;
    Course kursevi[100];
    Student studenti[100];

    for(int i=0;i<broj_kursevi;i++){
        cin>>kursevi[i].ime>>kursevi[i].kod;
        kursevi[i].broj_studenti=0;
    }

    for(int i=0;i<broj_kursevi;i++){
        cin>>studenti[i].ime>>studenti[i].index>>studenti[i].brojKursevi;
        for(int j=0;j<studenti[i].brojKursevi;j++){
            cin>>studenti[i].nizaKodovi[j];
        }
    }

    int index=get_most_popular_course(kursevi,broj_kursevi);
    cout<<"Najpopularen kurs e: "<<kursevi[index].ime<<endl;

}