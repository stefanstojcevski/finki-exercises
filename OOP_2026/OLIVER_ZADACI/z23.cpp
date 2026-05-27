#include <iostream>
#include <cstring>
using namespace std;
class Book {
private:
    char title[100];
    int year;
    float price;
public:
    Book() {
        strcpy(this->title,"");
        this->year=0;
        this->price=0;

    }
    Book(char title[100],int year, float price) {
        strcpy(this->title,title);
        this->year=year;
        this->price=price;

    }
    ~ Book() {

    }
    void display() {
        cout<<"TITLE: "<<title<<endl;
        cout<<"YEAR: "<<year<<endl;
        cout<<"PRICE: "<<price<<endl;

    }
    float getPrice() {
        return price;

    }


};
void printMostExpensiveBook(Book a[],int n) {
    int max=0;
    for (int i=0;i<n;i++) {
        if (a[i].getPrice()>a[max].getPrice()) {
            max=i;
        }
    }
    a[max].display();

}
int main() {
    int n;
    cin>>n;
    Book a[n];
    char title[100];
    int year;
    float price;
    for (int i=0;i<n;i++) {
        cin>>title;
        cin>>year;
        cin>>price;
        a[i] = Book(title, year, price);
    }
    printMostExpensiveBook(a, n);

}