#include <iostream>
#include <cstring>

using namespace std;
class Ingredient {
private:
    char *name;
    int quantity;
    int calories;
public:
    Ingredient() {
        this->name=new char[1];
        this->quantity=0;
        this->calories=0;

    }

    Ingredient(char *name,int quantity,int calories) {
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->quantity=quantity;
        this->calories=calories;

    }

    Ingredient(const Ingredient &i) {
        this->name=new char[strlen(i.name)+1];
        strcpy(this->name,i.name);
        this->quantity=i.quantity;
        this->calories=i.calories;

    }


    Ingredient& operator=(const Ingredient &i) {
        if (this!=&i) {
            delete [] name;
            this->name=new char[strlen(i.name)+1];
            strcpy(this->name,i.name);
            this->quantity=i.quantity;
            this->calories=i.calories;
        }
        return *this;
    }
    ~Ingredient() {
        delete [] name;

    }

int brojkalori() {
        return calories*quantity;
    }

    friend ostream& operator <<(ostream& pecati,const Ingredient &i) {
        pecati<<i.name<<" :"<<i.quantity<<"g/ml";
        return pecati;
    }

   char *getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }
};

class Dish {
private:
    Ingredient *ingredients;
    char *dishName;
    int ingredientCount;
public:
    Dish() {
        this->ingredients=nullptr;
        this->dishName=new char[1];
        this->ingredientCount=0;
    }

    Dish( Ingredient *ingredients,char *dishName,int ingredientCount) {
        this->ingredientCount=ingredientCount;
        this->ingredients=new Ingredient[ingredientCount];
        for (int i=0;i<ingredientCount;i++) {
            ingredients[i]=  ingredients[i];
        }
        this->dishName=new char[strlen(dishName)+1];
        strcpy(this->dishName,dishName);

    }
    Dish(char *name) {
        this->ingredientCount = 0;
        this->ingredients = nullptr;

        this->dishName = new char[strlen(name)+1];
        strcpy(this->dishName, name);
    }


    Dish( const Dish &d) {
        this->ingredientCount=d.ingredientCount;
        this->ingredients=new Ingredient[d.ingredientCount];
        for (int i=0;i<d.ingredientCount;i++) {
            ingredients[i]=  d.ingredients[i];
        }
        this->dishName=new char[strlen(d.dishName)+1];
        strcpy(this->dishName,d.dishName);
    }

    Dish& operator=( const Dish &d) {
        if (this!=&d){
            delete [] ingredients;
            delete [] dishName;

            this->ingredientCount=d.ingredientCount;
            this->ingredients=new Ingredient[d.ingredientCount];
            for (int i=0;i<d.ingredientCount;i++) {
                ingredients[i]=  d.ingredients[i];
            }
            this->dishName=new char[strlen(d.dishName)+1];
            strcpy(this->dishName,d.dishName);
        }
        return *this;

    }
    ~Dish() {
        delete [] ingredients;
        delete [] dishName;

    }
    int getTotalCaloreis() const{
        int zbir=0;
        for (int i=0;i<ingredientCount;i++) {
            zbir+=ingredients[i].brojkalori();
        }
        return zbir;
    }

    Dish operator+(const Dish &d) {
        Dish result;

        result.ingredientCount = this->ingredientCount + d.ingredientCount;
        result.ingredients = new Ingredient[result.ingredientCount];


        for (int i = 0; i < d.ingredientCount; i++) {
            result.ingredients[i] = d.ingredients[i];
        }

        for (int i = 0; i < this->ingredientCount; i++) {
            result.ingredients[d.ingredientCount + i] = this->ingredients[i];
        }

        result.dishName = new char[strlen(d.dishName) + 1];
        strcpy(result.dishName, d.dishName);

        return result;
    }

    Dish& operator+=(const Ingredient &i) {
        Ingredient *temp=new Ingredient[ingredientCount+1];
        for (int j=0;j<ingredientCount;j++) {
            temp[j]=ingredients[j];
        }
        temp[ingredientCount]=i;
        ingredientCount++;
        delete[] ingredients;
        ingredients=temp;
        return *this;

    }

    bool operator ==(const Dish &d) {
        if (getTotalCaloreis()==d.getTotalCaloreis()) {
            return true;
        }
        return false;
    }

    friend ostream& operator <<(ostream& pecati,const Dish &d) {
        pecati << "Dish: " << d.dishName << endl;

        for (int i = 0; i < d.ingredientCount; i++) {
            pecati << "- " << d.ingredients[i].getName()
                   << ": " << d.ingredients[i].getQuantity() << "g/ml" << endl;
        }

        pecati << "Total Calories: " << d.getTotalCaloreis() << endl;

        return pecati;
    }







};
int main() {
    char name [50];
    cin>>name;
    // Create Ingredients
    Ingredient tomato(name, 200, 20);
    cin>>name;
    Ingredient onion(name, 100, 30);
    cin>>name;
    Ingredient cheese(name, 50, 50);


    cin>>name;
    // Create Dishes
    Dish salad(name);
    salad += tomato;
    salad += onion;

    cin>>name;
    Dish pizza(name);
    pizza += tomato;
    pizza += cheese;

    // Test + operator
    Dish combinedDish = salad + pizza;
    cout<<combinedDish;

    cout<<"---------------------"<<endl;

    //Test = operator
    Ingredient ingredient = tomato;
    cout<<ingredient;
    cout<<endl;

    cout<<"---------------------"<<endl;

    // Test == operator
    if (salad == pizza) {
        cout << "Salad and Pizza have the same calories." << endl;
    } else {
        cout << "Salad and Pizza do not have the same calories." << endl;
    }

    cout<<"---------------------"<<endl;

    //Test << operator
    cout << "Salad:" << endl;
    cout << salad;

    cout << "Pizza:" << endl;
    cout << pizza;

    return 0;

}
