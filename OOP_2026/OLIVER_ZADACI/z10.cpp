/*
 *
*1.5 Држави
Да се напише програма која од стандарден влез ќе чита податоци за држави и на екран ќе го отпечати името
 и презимето на претседателот на државата чиj што главен град има најмногу жители. Податоци за држава:

име
претседател
главен град
број на жители.
Податоци за град:

име
број на жители.
Податоци за претседател:

име
презиме
политичка партија.
3
Makedonija
Gordana
Siljanovska
VMRO
Skopje
200000
2000000
Grcija
Jorgo
Papandreus
SARP
Atina
3000000
8000000
Bugarija
Bojko
Borisov
PAP
Sofija
2500000
6000000
Presedatel:Jorgo Papandreus
 **/
#include <iostream>
using namespace std;
struct Presedatel{
 char ime[100];
 char prezime[100];
 char politickaPartija[100];
};
struct Grad{
 char ime[100];
 int brojZiteli;
};
struct Drzava{
 char ime[100];
 Presedatel presedatel;
 Grad glavenGrad;
 int brojZiteli;
};
int main() {
 int n;
 cin>>n;
 Drzava a[n];
 for (int i=0;i<n;i++) {
  cin>>a[i].ime;
  cin>>a[i].presedatel.ime>>a[i].presedatel.prezime>>a[i].presedatel.politickaPartija;
  cin>>a[i].glavenGrad.ime>>a[i].glavenGrad.brojZiteli;
  cin>>a[i].brojZiteli;
 }
 int maxZiteli=0;
 for (int i=0; i<n;i++) {
  if (a[i].glavenGrad.brojZiteli>a[maxZiteli].glavenGrad.brojZiteli) {
   maxZiteli=i;
  }

 }
 cout<<"Pretsedatel:"<<a[maxZiteli].presedatel.ime<<" "<<a[maxZiteli].presedatel.prezime;

}
