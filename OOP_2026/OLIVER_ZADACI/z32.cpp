/*
 *Да се дефинира класа ParkingPlac во која се чуваат податоци за:

Адреса на плацот (низа од знаци, максимум 20),
Идентификациски број на плацот (динамичка низа од знаци),
Цена за паркирање за 1 час (цел број),
Заработка на паркинг плацот (цел број)
параметри потребни за дополнителниот дел од задачата:

Динамичка низа од класата Avtomobil
Број на паркирани автомобили во даден момент
За потребите на класата да се имплементираат :

соодветни конструктори и деструктор, и потребните get-функции (погледнете ги повиците во main функцијата)
функција pecati() за печатење на податоците за еден паркинг плац во следниот формат:

идентификациски_број адреса - X denari, ако X е заработката на паркинг плацот X не е 0

идентификациски_број адреса , ако X =0

функција platiCasovi(int casovi) која на заработката ја додава платената вредност за дадениот број на часови.

функција daliIstaAdresa(ParkingPlac p) во која се споредува дали дадениот паркинг плац е на иста адреса како паркинг плацот p.
Во дадената main функција прво се внесуваат n паркинг плацеви. Потоа се внесуваат m плаќања и на крај се печатат сите паркинг плацеви од низата кои имаат иста адреса со дадениот паркинг плац (објектот pCentar).

ДОПОЛНИТЕЛНО БАРАЊЕ

Дефинирајте класа Avtomobil во која се чуваат податоците за:

Бојата на автомобилот (низа од знаци, максимум 20)
Брендот на автомобилот (низа од знаци, максимум 20)
Моделот на автомобилот (низа од знаци, максимум 20)
За потребите на класата ќе треба да :

Се имплементира конструктор
Да го преоптоварите assignment operator-от
Понатака да пишете метод за класата ParkingPlac наречен parkirajVozilo(Avtomobil novoVozilo), неговата цел ќе биде да се паркира ново возило на паркингот во кој се повикува методот.

На крај ќе треба да се испечатат паркираните возила во еден паркинг преку методот pecatiParkiraniVozila() кој исто така треба да биде имплементиран во класата ParkingPlac.

Ориентирајте се според дадениот код во main методот за како се ова треба да го имплементирате.
 *
 **/





#include<iostream>
#include<cstring>
using namespace std;
class Avtomobil{
	private:
	char boja[20];
	char brend[20];
	char model[20];
	public:
		Avtomobil(char boja[20]="",char brend[20]="",char model[20]=""){
			strcpy(this->boja,boja);
			strcpy(this->brend,brend);
			strcpy(this->model,model);
		}
		Avtomobil(const  Avtomobil &a){
			strcpy(this->boja,a.boja);
			strcpy(this->brend,a.brend);
			strcpy(this->model,a.model);
		}
		Avtomobil& operator=(const  Avtomobil &a){
				if(this!=&a){
			strcpy(this->boja,a.boja);
			strcpy(this->brend,a.brend);
			strcpy(this->model,a.model);
		}
		return *this;
		}
		void pecati(){
			cout<<brend<<" "<<boja<<" "<<model<<endl;
		}
};
class ParkingPlac{
	private:
	char adresa[50];	
	char *id;//dinamicka niza od id
	int cena;
	int zarabotka;
	Avtomobil *avtomobil;//dinamicka niza od avtomobili
	int brAvtomobili;
	public:
		
		ParkingPlac (char adresa[50]="",char id[]="",int cena=0){
			strcpy(this->adresa,adresa);
			
			this->id=new char[strlen(id)+1];//alokacija na memorija za id
			strcpy(this->id,id);
			
			this->cena=cena;
			this->zarabotka=0;
			
			this->brAvtomobili=0;
			this->avtomobil=nullptr;
			
		}
		
			ParkingPlac (const ParkingPlac &p){
			strcpy(this->adresa,p.adresa);
			
			this->id=new char[strlen(p.id)+1];//alokacija na memorija za id
			strcpy(this->id,p.id);
			
			this->cena=p.cena;
			this->zarabotka=p.zarabotka;
			
			this->brAvtomobili=p.brAvtomobili;
			if(brAvtomobili>0){
					this->avtomobil=new Avtomobil[p.brAvtomobili];
					for(int i=0;i<p.brAvtomobili;i++){
						this->avtomobil[i]=p.avtomobil[i];
					}
			}else{
			this->avtomobil=NULL;//nullptr
		}
		}
		
		ParkingPlac& operator=(const ParkingPlac &p){
			if(this!=&p){
				delete [] id;
				delete [] avtomobil;
			strcpy(this->adresa,p.adresa);
			
			this->id=new char[strlen(p.id)+1];//alokacija na memorija za id
			strcpy(this->id,p.id);
			
			this->cena=p.cena;
			this->zarabotka=p.zarabotka;
			
			this->brAvtomobili=p.brAvtomobili;
			if(brAvtomobili>0){
					this->avtomobil=new Avtomobil[p.brAvtomobili];
					for(int i=0;i<p.brAvtomobili;i++){
						this->avtomobil[i]=p.avtomobil[i];
					}
			}else{
			this->avtomobil=NULL;//nullptr
		}
	}
	return *this;
		}
		~ParkingPlac(){
				delete [] id;
				delete [] avtomobil;
		}
		void pecati(){
			if(zarabotka!=0){
				cout<<id<<" "<<adresa<<" - "<<zarabotka<<" denari"<<endl;
			}
			else{
					cout<<id<<" "<<adresa<<endl;
			}
		}
		char *getId(){
			return id;
		}
		void platiCasovi(int casovi){
			zarabotka+=casovi*cena;
		}
		bool daliIstaAdresa(ParkingPlac p){
			return strcmp(this->adresa,p.adresa)==0;
		}
		void parkirajVozilo(Avtomobil novoVozilo){
			Avtomobil *temp=new Avtomobil[brAvtomobili+1];
			for(int i=0;i<brAvtomobili;i++){
				temp[i]=avtomobil[i];
			}
			temp[brAvtomobili++]=novoVozilo;
			delete [] avtomobil;
			avtomobil=temp;
		}
		void pecatiParkiraniVozila(){
				for(int i=0;i<brAvtomobili;i++){
				avtomobil[i].pecati();;
			}
		}
		
};
int main(){

	ParkingPlac p[100];

	int n,m;
	char adresa[50],id[50];
	int brojcasovi,cenacas;
	cin>>n;
	if(n > 0){


		for (int i=0;i<n;i++){
	        cin.get();
			cin.getline(adresa,50);
			cin>>id>>cenacas;

			ParkingPlac edna(adresa,id,cenacas);

	        p[i]=edna;
		}

		//plakjanje
		cin>>m;
		for (int i=0;i<m;i++){

			cin>>id>>brojcasovi;

	        int findId=false;
	        for (int j=0;j<m;j++){
	            if (strcmp(p[j].getId(),id)==0){
	                p[j].platiCasovi(brojcasovi);
	                findId=true;
	            }
	        }
			if (!findId)
	        cout<<"Ne e platen parking. Greshen ID."<<endl;
		}

	    cout<<"========="<<endl;
	    ParkingPlac pCentar("Cvetan Dimov","C10",80);
		for (int i=0;i<n;i++)
	        if (p[i].daliIstaAdresa(pCentar))
	            p[i].pecati();
	} else {

		ParkingPlac najdobarPlac("Mars", "1337", 1);
	    int brVozila;
	    cin >> brVozila;
	    for(int i = 0; i < brVozila; ++i){

	    	char boja[20];
	    	char brend[20];
	    	char model[20];

	    	cin >> boja >> brend >> model;
	    	Avtomobil novAvtomobil(boja, brend, model);
	    	najdobarPlac.parkirajVozilo(novAvtomobil);
	    }
	    if(brVozila != 0)
	    najdobarPlac.pecatiParkiraniVozila();

	}
}
