/*
*За програмски јазик да се употреби C.

Креирајте структура InvoiceItem во која ќе ги чувате следните податоци:

идентификациски број (максимум 10 карактери)
количина (цел број)
цена (цел број)
Потоа, креирајте структура Invoice во која ќе ги чувате следните податоци:

идентификациски број (максимум 10 карактери)
број на ставки (цел број)
низа од ставки (InvoiceItem)
На крај, креирајте структура Client во која ќе ги чувате следните податоци:

име (максимум 100 карактери)
број на фактури (цел број)
низа од фактури (Invoice)
Напишете функција, bestClient која што ќе го испечати клиентот кој што има најголема сума на фактури што треба да ја плати.
 Доколку постојат повеќе, се печати првиот. Сумата на една фактура се пресметува како сума од сите
ставки на фактурата плус 18% ДДВ на целата сума од таа фактура. Сумата на сите фактури се пресметува
 како збир од сумите на сите фактури (овде НЕ додавате ДДВ)

Од тастатура се внесува прво број на клиенти, па податоците за клиентот, па број на фактури
за секој клиент, па низата од фактури, и за секоја фактура се внесува број на ставки, па низата од ставки.

For example:

Input:
2
Jordancho 2
inv001 3
stavka1 100
stavka2 200
stavka3 3000
inv002 1
stavka1 10000
Martin 1
inv001 1
stavka1 100

Result:
Jordancho
 **/
#include <iostream>
struct InvoiceItem {
 char id[10];
 int kolicina;
 int cena;

};
struct Invoice {
 char id[10];
 int brStavki;
 InvoiceItem nizaStavki[100];

};
struct Client {
 char ime[100];
 int brojnafakturi;
 Invoice nizafakturi[100];
};
using namespace std;
void bestClient(Client a[],int n) {

 int najgolem=0;
 int index;
 for (int i=0;i<n;i++) {
  int zbir=0;


  for (int j=0;j<a[i].brojnafakturi;j++) {
   int faktura=0;

   for (int w=0;w<a[i].nizafakturi[j].brStavki;w++) {

     faktura+=a[i].nizafakturi[j].nizaStavki[w].cena * a[i].nizafakturi[j].nizaStavki[w].kolicina;

   }
   faktura=faktura*1.18;
   zbir+=faktura;
  }
  if (zbir>najgolem) {
   najgolem=zbir;
   index=i;
  }

  }

 cout<<a[index].ime;


}
int main() {
 int n;
 cin>>n;
 Client a[n];
 for (int i=0;i<n;i++) {
  cin>>a[i].ime>>a[i].brojnafakturi;
  for (int j=0;j<a[i].brojnafakturi;j++) {
   cin>>a[i].nizafakturi[j].id>>a[i].nizafakturi[j].brStavki;
   for (int w=0;w<a[i].nizafakturi[j].brStavki;w++) {
    cin>>a[i].nizafakturi[j].nizaStavki[w].id>>a[i].nizafakturi[j].nizaStavki[w].kolicina>>a[i].nizafakturi[j].nizaStavki[w].cena;
   }
  }
 }
 bestClient(a,n);

}