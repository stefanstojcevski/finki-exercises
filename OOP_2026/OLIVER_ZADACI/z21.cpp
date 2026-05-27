#include <iostream>
using namespace std;
class Country {
private:
    char name[100];
    char capital[100];
    float area;
    float population;
public:
    Country(){
        strcpy(this->name,"");
        strcpy(this->capital,"");
        this->area=0;
        this->population=0;
    }
    Country(char name[100],char capital[100],float area,float population){
        strcpy(this->name,name);
        strcpy(this->capital,capital);
        this->area=area;
        this->population=population;
    }
    ~Country(){
    }

    void display() {
        cout<<"Country:"<<name<<endl;
        cout<<"Capital:"<<capital<<endl;
        cout<<"Area:"<<area<<endl;
        cout<<"Population:"<<population<<endl;
    }
    float getArea(){
        return area;
    }

};
void sortCountries(Country countrys[],int n) {
    Country temp;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++){
        if (countrys[j].getArea()>countrys[j+1].getArea()) {
            temp=countrys[j];
            countrys[j]=countrys[j+1];
            countrys[j+1]=temp;





        }
    }
    }
}
    int main() {
        int n;
        cin >> n;

        Country countries[100];

        char name[100];
        char capital[100];
        float area;
        float population;

        for(int i = 0; i < n; i++){
            cin >> name >> capital >> area >> population;
            countries[i] = Country(name, capital, area, population);
        }

        cout << "-->Testing display()" << endl;
        countries[0].display();

        cout << "-->Testing sortCountries()" << endl;
        sortCountries(countries, n);

        for(int i = 0; i < n; i++){
            countries[i].display();
        }

        return 0;
    }


