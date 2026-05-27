/*
*Да се креира структура Igrac во која се чуваат податоци за еден играч на компјутерската игра.
*За играчот се чуваат информации за корисничкото име на играчот (низа од 15 знаци),
*број на ниво до кој играчот е стигнат (цел број) и број на освоени поени (цел број) (10 поени).

Потоа да се креирa структура KompjuterskaIgra во која се чуваат податоци за името на играта (низа од 20 знаци),
низа од играчи кои ја играат играта (најмногу 30) и бројот на играчи. (10 поени)

Треба да се направи функција со потпис (15 поени)

void najdobarIgrac(KompjuterskaIgra *lista, int n)
Оваа функција треба да го испечати името на најдобриот играч на онаа игра која има најголема популарност (ја играат наjголем број на играчи).
Најдобар играч е играчот кој има најголем број на освоени поени. Ако има повеќе играчи со ист максимален број на освоени поени, најдобар е играчот кој има достигнато најголемо ниво.

Печатењето е во форматот: "Najdobar igrac e igracot so korisnicko ime XXXXX koj ja igra igrata YYYYYY". (XXXXXX е корисничкото име на најдобриот играч,а YYYYY е името на играта која ја играат најголем број на играчи)

(Забелешка: секогаш ќе има точно еден најдобар играч)

Функционалност на задачата и дополнување на main функцијата (10 поени)

Забелешка: Задачата да се реши во програмскиот јазик C+

For example:

Input
2
Snake
2
user1 5 120
user2 4 120
Cars
3
koliubavi 5 130
fikjo 3 150
motor 4 140
Result
Najdobar igrac e igracot so korisnicko ime fikjo koj ja igra igrata Cars
--------------------------------------------------------------------

 **/
#include <iostream>
using namespace std;
struct igrac {
 char korisnickoime[15];
 int nivo;
 int brojnaosvoenipoeni;


};
struct KompjuterskaIgra {
 char ime[20];
 int brojnaigraci;
 igrac igraci[30];
};
void najdobarIgrac(KompjuterskaIgra a[], int n) {
 int najpopularna=0;
 int index=0;

 for (int i=0;i<n;i++) {
  if (a[i].brojnaigraci>a[najpopularna].brojnaigraci) {
   najpopularna=i;
  }
 }
 for (int j=0;j<a[najpopularna].brojnaigraci;j++) {
  if(a[najpopularna].igraci[j].brojnaosvoenipoeni>a[najpopularna].igraci[index].brojnaosvoenipoeni) {
   index=j;

  }
  else if (a[najpopularna].igraci[j].brojnaosvoenipoeni ==
         a[najpopularna].igraci[index].brojnaosvoenipoeni &&
         a[najpopularna].igraci[j].nivo >
         a[najpopularna].igraci[index].nivo) {

   index = j;
         }
 }
 cout<<"Najdobar igrac e igracot so korisnicko ime "<< a[najpopularna].igraci[index].korisnickoime <<" koj ja igra igrata "<< a[najpopularna].ime ;

}
int main() {
 int n;
 cin>>n;
 KompjuterskaIgra a[n];
 for (int i=0;i<n;i++) {
  cin>>a[i].ime>>a[i].brojnaigraci;
  for (int j=0;j<a[i].brojnaigraci;j++) {
   cin>>a[i].igraci[j].korisnickoime>>a[i].igraci[j].nivo>>a[i].igraci[j].brojnaosvoenipoeni;

  }
 }
 najdobarIgrac(a, n);



}