#include <iostream>
#include <cstring>
using namespace std;
class Chocolate {
private:
    char name[100];
    int price;
public:
    Chocolate() {
        strcpy(this->name,"");
        this->price=0;

    }

    Chocolate(char name[100],int price) {
        strcpy(this->name,name);
        this->price=price;

    }

    Chocolate(const Chocolate &c) {
        strcpy(this->name,c.name);
        this->price=c.price;

    }

    Chocolate& operator=(const Chocolate &c) {
        if (this!=&c) {
            strcpy(this->name,c.name);
            this->price=c.price;
        }
        return *this;
    }

    friend ostream& operator <<(ostream &pecati,const Chocolate &c) {
        pecati<<c.name<<": $"<<c.price;
    }

friend class ChocolateFactory;
};


class ChocolateFactory {
private:
    Chocolate *products;
    int numProducts;
    int *weeklyProduction;
public:
    ChocolateFactory() {
        this->products=nullptr;
        this->numProducts=0;
        this->weeklyProduction=new int[0];
    }

    ChocolateFactory(Chocolate *products,int numProducts,int *weeklyProduction) {
        this->products=new Chocolate[numProducts];
        for (int i=0;i<numProducts;i++) {
            this->products[i]=products[i];
        }
        this->numProducts=numProducts;
        this->weeklyProduction=new int[numProducts];
        for (int i=0;i<numProducts;i++) {
            this->weeklyProduction[i]=weeklyProduction[i];
        }
    }


    ChocolateFactory(const ChocolateFactory &f) {
        this->products=new Chocolate[f.numProducts];
        for (int i=0;i<f.numProducts;i++) {
            this->products[i]=f.products[i];
        }
        this->numProducts=f.numProducts;
        this->weeklyProduction=new int[f.numProducts];
        for (int i=0;i<f.numProducts;i++) {
            this->weeklyProduction[i]=f.weeklyProduction[i];
        }
    }

    ChocolateFactory& operator=(const ChocolateFactory &f) {
        if (this!=&f){
            delete [] products;
            delete [] weeklyProduction;
            this->products=new Chocolate[f.numProducts];
            for (int i=0;i<f.numProducts;i++) {
                this->products[i]=f.products[i];
            }
            this->numProducts=f.numProducts;
            this->weeklyProduction=new int[f.numProducts];
            for (int i=0;i<f.numProducts;i++) {
                this->weeklyProduction[i]=f.weeklyProduction[i];
            }
        }
        return *this;

    }
    ~ChocolateFactory() {
        delete [] products;
        delete [] weeklyProduction;
    }
   int weeklyIncome() const{
        int weeklyIncome=0;
        for (int i=0;i<numProducts;i++) {
            weeklyIncome+=weeklyProduction[i]*products[i].price;
        }
        return weeklyIncome;
    }
    bool operator>(const ChocolateFactory &f) {
        if (weeklyIncome()>f.weeklyIncome()) {
            return true;
        }
        return false;
    }

    bool operator<(const ChocolateFactory &f) {
        if (weeklyIncome()<f.weeklyIncome()) {
            return true;
        }
        return false;
    }

    ChocolateFactory operator+(const ChocolateFactory &f) {
        ChocolateFactory result;


        result.numProducts=this->numProducts+f.numProducts;
        result.products=new Chocolate[result.numProducts];
        result.weeklyProduction=new int[result.numProducts];
        for (int i=0;i<this->numProducts;i++) {
            result.products[i] = this->products[i];
            result.weeklyProduction[i]=this->weeklyProduction[i];

        }
        int j=0;
        for (int i=this->numProducts;i<result.numProducts;i++) {
            result.products[i] = f.products[j];
            result.weeklyProduction[i]=f.weeklyProduction[j];
            j++;
        }
        return result;
    }
  friend ostream& operator <<(ostream &pecati , const ChocolateFactory &f) {
        for (int i = 0; i < f.numProducts; i++) {
            pecati <<f.products[i] << " x " << f.weeklyProduction[i] << endl;
        }

        pecati << "$" << f.weeklyIncome() << "/wk";

        return pecati;
    }




};

int main() {
    int testCase;
    char name[100];
    int price;

    Chocolate products[100];
    int weeklyProduction[100];

    cin >> testCase;
    if (testCase == 0) {
        cout<<"Testing Chocolate print operator:"<<endl;
        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            cout<<Chocolate(name,price)<<endl;
        }
    }
    else if (testCase == 1) {
        cout<<"Testing ChocolateFactory print operator:"<<endl;

        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            products[i] = Chocolate(name, price);
            cin>>weeklyProduction[i];
        }

        ChocolateFactory cf(products,10,weeklyProduction);
        cout<<cf<<endl;
    }
    else if (testCase == 2) {
        cout<<"Testing ChocolateFactory comparison operators:"<<endl;

        for (int i = 0; i < 3; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,4,weeklyProduction);

        for (int i = 0; i < 4; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,4,weeklyProduction);

        cout<<cf1<<cf2;

        cout<<"< operator: "<< (cf1<cf2 ? "PASS" : "FAIL") <<endl;
        cout<<"> operator: "<< (cf2>cf1 ? "PASS" : "FAIL") <<endl;
    }
    else if (testCase == 3) {
        cout<<"Testing ChocolateFactory sum operator:"<<endl;

        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,5,weeklyProduction);
        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,5,weeklyProduction);

        cout<<cf1+cf2;
    }
}