
#include <iostream>
#include <cstring>

using namespace std;

class Igrachka {
public:
    virtual float getVolumen() = 0;
    virtual float getMasa() = 0;
    virtual float getPlostina() = 0;
};

class Forma {
protected:
    char boja[100];
    int gustina;
public:
    Forma(){}
    Forma(char *boja, int gustina)
    {
        strcpy(this->boja, boja);
        this->gustina=gustina;
    }

    ~Forma(){}
    // да се имплементираат потребните методи

};


class Kocka : public Forma, public Igrachka{
private:
    int visina;
    int sirina;
    int dlabocina;
public:
    Kocka(){}
    Kocka(char *boja, int gustina, int visina, int sirina, int dlabocina): Forma(boja,gustina)
    {
        this->visina=visina;
        this->sirina=sirina;
        this->dlabocina=dlabocina;
    }
    float getVolumen()
    {
        return visina*sirina*dlabocina;
    }
     float getMasa() {
    return getVolumen()*gustina;
    }
    float getPlostina()
    {
        return 2*(visina*sirina+sirina*dlabocina+visina*dlabocina);
    }
    ~Kocka(){}

};
class Topka : public Forma, public Igrachka{
private:
    int radius;
public:
    Topka(){}
    Topka(char *boja, int gustina, int radius) : Forma(boja,gustina)
    {
        this->radius=radius;
    }
     float getVolumen()
     {
         float r;
         r=(4.0/3)*3.14;
         return r*radius*radius*radius;
     }
    float getMasa()
    {
        return getVolumen()*gustina;
    }
    float getPlostina()
    {
        return 3.14*4*radius*radius;
    }
    ~Topka(){}
};
int main(){
	//vnesi informacii za kupche
	int n, tip, radius, visina, sirina, dlabocina, gustina;
	char boja[100];
	cin>>n;
	Igrachka **kupce;
	kupce = new Igrachka *[n];
	for(int i=0; i<n; i++)
	{
	cin>>tip;
	if(tip==1)
	{
	    cin>>boja;
	    cin>>gustina;
	    cin>>radius;
	    kupce[i]=new Topka(boja,gustina,radius);
	}
    else if(tip==2)
    {
        cin>>boja;
	    cin>>gustina;
	    cin>>visina;
        cin>>sirina;
        cin>>dlabocina;
        kupce[i] = new Kocka (boja, gustina, visina, sirina, dlabocina);
    }
	}

    //vnesi informacii za igrachkata na Petra
        cin>>boja;
	    cin>>gustina;
	    cin>>visina;
        cin>>sirina;
        cin>>dlabocina;
        Kocka petra (boja,gustina,visina, sirina, dlabocina);
        float masaigracki=0, masapetra,masakupce,maxvolumen=0, volumenkupce=0;
        masapetra=petra.getMasa();
        for(int i=0; i<n; i++)
        {
            masakupce=kupce[i]->getMasa();
            masaigracki+=masakupce;
            volumenkupce=kupce[i]->getVolumen();
        if(volumenkupce>maxvolumen){
            maxvolumen=volumenkupce;
        }
        }
            float volumenPetra=petra.getVolumen(),PlostinaPetra;
            if(masaigracki>masapetra)
                cout<<"DA"<<endl;
            else
                cout<<"NE"<<endl;
cout<<"Razlikata e: ";
if(volumenPetra>maxvolumen){

    cout<<volumenPetra-maxvolumen<<endl;
}
else{
    cout<<maxvolumen-volumenPetra<<endl;

}
PlostinaPetra=petra.getPlostina();
float min=99999;
  for(int i=0; i<n; i++)
        {
            masakupce=kupce[i]->getPlostina();
            if(masakupce<min)
                min=masakupce;
        }
cout<<"Razlikata e: ";
if(PlostinaPetra>min){

    cout<<(int)PlostinaPetra-min<<endl;

}
else{
      cout<<(int)min-PlostinaPetra<<endl;


}
	return 0;
}
