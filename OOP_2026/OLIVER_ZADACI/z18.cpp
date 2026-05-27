/*
 *Да се дефинира класа Film, во која ќе се чуваат информации за:

    име низа од 100 знаци
    режисер низа од 50 знаци
    жанр низа од 50 знаци
    година цел број

Сите променливи треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:

    default конструктор и конструктор со аргументи
    метод за печатење на информациите за филмот

Дополнително да се реализира надворешна функција:

    void pecati_po_godina(Film *f, int n, int godina) која ќе прима аргумент низа од филмови, вкупниот број на филмови и година, а треба да ги отпечати само филмовите кои се направени во дадената година.

For example:
Input

4
Frankenweenie
Tim_Burton
Animation
2012
Lincoln
Steven_Spielberg
History
2012
Wall-E
Andrew_Stanton
Animation
2008
Avatar
James_Cameron
Fantasy
2009
2008


Result
Ime: Wall-E
Reziser: Andrew_Stanton
Zanr: Animation
Godina: 2008
----------------------------------------------

#include<iostream>
#include<cstring>
using namespace std;
class Film{
	private:
	char ime[100];
	char reziser[50];
	char zanr[50];
	int godina;
	public:
		Film(){//deafult constructor
		strcpy(this->ime,"");
		strcpy(this->reziser,"");
		strcpy(this->zanr,"");
		this->godina=0;
		}
		Film(char ime[100],char reziser[50],char zanr[50],int godina){//constructor so argumenti
		strcpy(this->ime,ime);
		strcpy(this->reziser,reziser);
		strcpy(this->zanr,zanr);
		this->godina=godina;
		}
		~Film(){//destruct
		}

		Film(char i[100],char r[50],char z[50],int g){//constructor so argumenti
		strcpy(ime,i);
		strcpy(reziser,r);
		strcpy(zanr,z);
		godina=g;
		}


		int getGodina(){ //get funkcija za godinata koja sto sakame da ja zememe
			return godina;
		}
		void setGodina(int godina){//set funkcija ako sakame da smenime godina
			this->godina=godina;
		}
		void pecati(){
cout<<"Ime: "<<ime<<endl;
cout<<"Reziser: "<<reziser<<endl;
cout<<"Zanr: "<<zanr<<endl;
cout<<"Godina: "<<godina<<endl;
		}
};

 void pecati_po_godina(Film *f, int n, int godina){
 		for(int i = 0; i < n; ++i) {
 			if(f[i].getGodina()==godina){
 				f[i].pecati();
			 }
 		}
 }
int main() {
 	int n;
 	cin >> n;
 	//da se inicijalizira niza od objekti od klasata Film
 	Film film[n];
 	for(int i = 0; i < n; ++i) {
 		char ime[100];
 		char reziser[50];
 		char zanr[50];
 		int godina;
 		cin >> ime;
 		cin >> reziser;
 		cin >> zanr;
 		cin >> godina;
 		//da se kreira soodveten objekt
Film f(ime,reziser,zanr,godina);
film[i]=f;
}
 	int godina;
 	cin >> godina;
 	//da se povika funkcijata pecati_po_godina
pecati_po_godina(film,  n,  godina);
 	return 0;
 }

 */

#include<iostream>
#include<cstring>
using namespace std;
class Film {
private:
	char ime[100];
	char reziser[50];
	char zanr[50];
	int godina;
public:
	Film() {          //defult constructor
		strcpy(this->ime,"");
		strcpy(this->reziser,"");
		strcpy(this->zanr,"");
		this->godina=0;
	}
	Film(char ime[],char reziser[],char zanr[],int godina) {  // construktor so argumenti
		strcpy(this->ime,ime);
		strcpy(this->reziser,reziser);
		strcpy(this->zanr,zanr);
		this->godina=godina;

	}
	~Film(){      //destruct
	}

	int getGodina(){         //get funkcija za godinata koja sto sakame da ja zememe
		return godina;
	}
	void setGodina(int godina){       //set funkcija ako sakame da smenime godina
		this->godina=godina;
	}

	void pecati(){
		cout<<"Ime: "<<ime<<endl;
		cout<<"Reziser: "<<reziser<<endl;
		cout<<"Zanr: "<<zanr<<endl;
		cout<<"Godina: "<<godina<<endl;
	}
};

void pecati_po_godina(Film f[], int n, int godina) {
	for(int i = 0; i < n; ++i) {
		if(f[i].getGodina()==godina){
			f[i].pecati();
		}
	}
}
	int main() {
		int n;
		cin >> n;
		//da se inicijalizira niza od objekti od klasata Film
		Film film[n];
		for(int i = 0; i < n; ++i) {
			char ime[100];
			char reziser[50];
			char zanr[50];
			int godina;
			cin >> ime;
			cin >> reziser;
			cin >> zanr;
			cin >> godina;
			//da se kreira soodveten objekt
			Film f(ime,reziser,zanr,godina);
			film[i]=f;
		}
	int godina;
	cin >> godina;
	//da se povika funkcijata pecati_po_godina
	pecati_po_godina(film,  n,  godina);
	return 0;
	}

