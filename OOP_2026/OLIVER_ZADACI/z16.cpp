/*
 *Да се креира структура Воз во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци),
 *предвиден бројот на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).

Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци),
низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).

Треба да се направи функција со потпис

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
во која се печати релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри),
а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал број
на километри, да се испечати релацијата на последниот таков.

Забелешка: Задачата да се реши во програмскиот јазик C++

For example:

Input
1
Dresden
2
Dresden-Berlin 192 200
Dresden-Lajpcig 115 90
Dresden
Result:
Najkratka relacija: Dresden-Lajpcig (115 km)

-------------------------------------------------
#include<iostream>
#include<cstring>
using namespace std;
struct Voz{
char relacija[50];
float km;
int brPatnici;
};
struct ZeleznickaStanica{
char grad[20];
Voz vozovi[30];
int brVozovi;
};
void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad){
int indexi=0,indexj=0;
for(int i=0;i<n;i++){
	float min=zs[i].vozovi[0].km;
	if(strcmp(zs[i].grad,grad)==0){
	for(int j=0;j<zs[i].brVozovi;j++){
	if(zs[i].vozovi[j].km<=min){
		min=zs[i].vozovi[j].km;
		indexi=i;
		indexj=j;
	}
}
}
}

cout<<"Najkratka relacija: "<<zs[indexi].vozovi[indexj].relacija<<" ("<<zs[indexi].vozovi[indexj].km<<" km)"<<endl;
}
int main(){
int n;
char grad[20];
cin>>n;
ZeleznickaStanica z[n];
for(int i=0;i<n;i++){
	cin>>z[i].grad;
	cin>>z[i].brVozovi;
	for(int j=0;j<z[i].brVozovi;j++){
		cin>>z[i].vozovi[j].relacija;
		cin>>z[i].vozovi[j].km;
		cin>>z[i].vozovi[j].brPatnici;
}
}
cin>>grad;
najkratkaRelacija(z,n,grad);
}
 **/

#include <iostream>
#include <cstring>
using namespace std;
struct Voz {
	char pravec[50];
	int brojkm;
	int brojpatnici;
};
struct ZeleznickaStanica {
	char gradvokooje[20];
	int brojvozovi;
	Voz vozovi[30];
};
void najkratkaRelacija(ZeleznickaStanica a[], int brvozovi, char grad[]) {
	int najmal=0;
	int index=0;
	for (int i=0;i<brvozovi;i++) {

		for (int j=0;j<a[i].brojvozovi;j++) {
			if (strcmp(grad,a[i].gradvokooje)==0) {
				if (a[i].vozovi[j].brojkm<=a[index].vozovi[najmal].brojkm) {
					najmal=j;
					index=i;
				}


			}

		}
	}
	cout<<"Najkratka relacija:"<<a[index].vozovi[najmal].pravec <<"("<<a[index].vozovi[najmal].brojkm<<"km)";

}
int main() {
	int brvozovi;
	cin>>brvozovi;
	ZeleznickaStanica a[brvozovi];
	for (int i=0;i<brvozovi;i++) {
		cin>>a[i].gradvokooje>>a[i].brojvozovi;
		for (int j=0;j<a[i].brojvozovi;j++) {
			cin>>a[i].vozovi[j].pravec>>a[i].vozovi[j].brojkm>>a[i].vozovi[j].brojpatnici;
		}
	}
	char grad[20];
	cin>>grad;
	najkratkaRelacija(a,brvozovi, grad);
}