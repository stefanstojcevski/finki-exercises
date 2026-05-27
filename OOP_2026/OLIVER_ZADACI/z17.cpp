/*
 *Да се креира структура Proizvod во која се чуваат податоци за кодот напрозиводот (низа од 20 знаци),
 *единична цена на производ (цел број), бројот на достапни производи кои ги има во еден магацин (цел број) .

Потоа да се креирa структура Narachka во која се чуваат податоци за името лицето кое ја прави нарачката (низи од 15 знаци),
низа од Proizvodi (максимум 10) кои ги има во нарачката, низа од бројот на нарачани производи за секоја производ посебно
(максимум10) и бројот на производи во нарачката .

Треба да се направи функција со потпис

void pecatiFaktura(Narachka n)

која што ќе ги отпечати една фактура за една нарачка (n) .

Во фактурата во првиот ред се печати: Faktura za XXXXX, каде XXXXX е името на лицето кое ја прави нарачката.

Ако сите производи може да се нарачаат печатат нарачаните производи, подредени по азбучен ред според кодот на производот.
Во следните редови, во секој ред посебно се печати кодот на производот, единична цена на производот, број на нарачани производи
и вкупната цена на производот (сите се одделени со едно празно место) . Исто така бројот на достапни производи од тој производ да
се ажурира (да се намали за бројот на нарачани производи од тој производ).
Во последниот ред да се отпечати: Vkupnata suma na fakturata e XXX, каде XXX е вкупната сума за цените за сите нарачани производи.

Ако постои производ кој не може да биде нарачан затоа што во магацинот не се достапни нарачаниот број производи
тогаш не може да се изготви фактура за нарачката. На екранот да се отпечати: Fakturata ne moze da se izgotvi.

For example:

Input
Stefan 2
proizvod1 10 1
proizvod2 20 3
3 2
Result
Faktura za Stefan
Fakturata ne moze da se izgotvi
--------------------------------------
*/
#include<iostream>
#include<cstring>
using namespace std;
struct Proizvod{
char kodNaProizvodi[20];
int cena;
int dostapni;
};
struct Narachka{
char ime[15];
Proizvod proizvodi[10];
int broj[10];
int n;
};
void pecatiFaktura(Narachka n){
int zbir=0;
	cout<<"Faktura za "<<n.ime<<endl;
	 for(int i=0;i<n.n;i++){
	 	if(n.broj[i]>n.proizvodi[i].dostapni){
	 		cout<<"Fakturata ne moze da se izgotvi."<<endl;
	 		return;
		 }
	 }

	  for(int i=0;i<n.n;i++){
	  	 for(int j=i+1;j<n.n;j++){
	  	 	if(strcmp(n.proizvodi[i].kodNaProizvodi,n.proizvodi[j].kodNaProizvodi)>0){
	  	 			Proizvod temp=n.proizvodi[i];
	  	 			n.proizvodi[i]=n.proizvodi[j];
	  	 			n.proizvodi[j]=temp;
			   }
		}
	}
	 for(int i=0;i<n.n;i++){
	 zbir=zbir+n.broj[i]*n.proizvodi[i].cena;
	 cout<<n.proizvodi[i].kodNaProizvodi<<" "<<n.proizvodi[i].cena<<" "<<n.broj[i]<<" "<<n.broj[i]*n.proizvodi[i].cena<<endl;
	 }
	 cout<<"Vkupnata suma na fakturata e "<<zbir<<endl;
}

int main(){
char grad[20];
Narachka narachka;
cin>>narachka.ime;
cin>>narachka.n;
for(int i=0;i<narachka.n;i++){
	cin>>narachka.proizvodi[i].kodNaProizvodi;
	cin>>narachka.proizvodi[i].cena;
	cin>>narachka.proizvodi[i].dostapni;
}
	for(int j=0;j<narachka.n;j++){
	cin>>narachka.broj[j];
}
pecatiFaktura(narachka);
}

