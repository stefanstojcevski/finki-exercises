#include<iostream>
#include<iomanip>
using namespace std;

struct Student {
    char ime[100];
    int index;
    int brkursevi;
    char nizaodkod[100];
};
struct Course {
    char ime[100];
    int kod;
    int broj_studenti;
};

int najpoznata(struct Course cursevi[],int brCursoj) {
    int najpopularen=0;
    for (int i=0;i<brCursoj;i++) {
        if (cursevi[i].broj_studenti > cursevi[najpopularen].broj_studenti){
            najpopularen = i;
    }
}
        return najpopularen;
}


int main() {
    int brStudenti,brCursoj;
    Student studenti[brStudenti];
    Course cursevi[brCursoj];
    cin>>brStudenti>>brCursoj;
    for (int i=0;i<brCursoj;i++) {
        cin>>cursevi[i].ime>>cursevi[i].kod;
        curv
    }
    for (int i=0;i<brStudenti;i++) {
        cin>>studenti[i].ime>>studenti[i].index>>studenti[i].brkursevi;
        for (int j=0;j<studenti[i].brkursevi;j++) {
            cin>>studenti[j].nizaodkod;
        }

    }
    int ind = najpoznata(cursevi,brCursoj);



}