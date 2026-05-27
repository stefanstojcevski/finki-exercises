/*
*Да се креира структура SkiLift во која се чуваат податоци за името на ски лифтот (низа од 15 знаци),
 максимален број на корисници што може да опслужи на едно возење, дали е пуштен во функција.

Потоа да се креирa структура SkiCenter во која се чуваат податоци за името на скијачкиот центар,
држава во која се наоѓа (низи од 20 знаци), низа од ски лифтови (макс 20) што ги има и број на ски лифтови.

Треба да се направи функција со потпис

void najgolemKapacitet(SkiCenter *sc, int n)
која што ќе го отпечати ски центарот што има најголем капацитет за опслужување скијачи
(вкупниот број на скијачи кои може да се опслужуваат во еден момент вкупно на сите ски лифтови во центарот).
 Доколку два ски центри имаат ист капацитет, тогаш се печати оној кој има поголем број на ски лифтови.
Притоа треба да се испечатат во посебен ред името, државата и капацитетот на ски центарот.
Кога се пресметува капацитет на еден ски центар во предвид се земаат само ски лифтовите кои се поставени дека се во функција.

For example:

Input
1
Mavrovo
Makedonija
6
Ednosed
30
1
Dvosed
60
1
Ciciban
10
1
Galicki
20
1
Belicki
36
0
Plavi
40
1
Result
Mavrovo
Makedonija
160

 **/
#include <iostream>
using namespace std;
struct SkiLift {
 char ime[15];
 int brojKorisnici;
 int pustenVofunkcija;
};
struct SkiCenter {
 char ime[15];
 char drzava[20];
 int brojskilivtovi;
 SkiLift nizaodskilivtovi[100];

};
void najgolemKapacitet(SkiCenter a[], int n) {
 int max=0;
 int index=0;
 for (int i=0;i<n;i++) {
  int zbir=0;
  for (int j=0;j<a[i].brojskilivtovi;j++) {
  if (a[i].nizaodskilivtovi[j].pustenVofunkcija==1) {
   zbir+=a[i].nizaodskilivtovi[j].brojKorisnici;
  }
  }
  if (zbir>max) {
   max=zbir;
   index=i;
  }

 }
 cout<<a[index].ime<<endl;
 cout<<a[index].drzava<<endl;
 cout<<max<<endl;


}
int main() {
 int n;
 cin>>n;
 SkiCenter a[n];

 for (int i=0;i<n;i++) {
  cin>>a[i].ime>>a[i].drzava>>a[i].brojskilivtovi;
  for (int j=0;j<a[i].brojskilivtovi;j++) {
   cin>>a[i].nizaodskilivtovi[j].ime>>a[i].nizaodskilivtovi[j].brojKorisnici>>a[i].nizaodskilivtovi[j].pustenVofunkcija;
  }
 }
 najgolemKapacitet(a,n);

}