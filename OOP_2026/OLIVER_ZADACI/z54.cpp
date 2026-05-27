#include <iostream>
#include<cstring>
using namespace std;

enum TipNaKniga {
    strucna = 0, roman = 1
};

class Book {
private:
    char naslov[30];
    int seriski;
    TipNaKniga tip;
    float cena;
    static int generator;

public:
    Book() {
        strcpy(this->naslov, "");
        this->seriski = generator++;
        this->tip = roman;
        this->cena = 0;
    }

    Book(char naslov[30], int tip, float cena) {
        strcpy(this->naslov, naslov);
        this->seriski = generator++;
        this->tip = (TipNaKniga) tip;
        this->cena = cena;
    }


    Book(const Book &b) {
        strcpy(this->naslov, b.naslov);
        this->seriski = b.seriski;
        this->tip = (TipNaKniga) b.tip;
        this->cena = b.cena;
    }

    Book &operator =(const Book &b) {
        if (this != &b) {
            strcpy(this->naslov, b.naslov);
            this->seriski = b.seriski;
            this->tip = (TipNaKniga) b.tip;
            this->cena = b.cena;
        }
        return *this;
    }

    ~Book() {
    }

    friend ostream &operator <<(ostream &pecati, const Book &b) {
        pecati << b.seriski << "-" << b.naslov << " ";
        if (b.tip == strucna) {
            pecati << "STRUCNA";
        } else {
            pecati << "ROMAN";
        }
        pecati << " " << b.cena << endl;
        return pecati;
    }

    Book &operator +=(float vrednost) {
        cena += vrednost;
        return *this;
    }
    friend class Bookstore;

    int getSeriski() const {
        return seriski;
    }

    TipNaKniga getTip() {
        return tip;
    }
    int getCena() {
        return cena;
    }
};

class BookStore {
private:
    char ime[20];
    Book *books;
    int brojj;

public:
    BookStore() {
        strcpy(this->ime, "");
        this->brojj = 0;
        this->books = nullptr;
    }

    BookStore(char ime[20]) {
        strcpy(this->ime, ime);
        this->brojj = 0;
       this->books=nullptr;
    }

    BookStore(const BookStore &s) {
        strcpy(this->ime, s.ime);
        this->brojj = s.brojj;
        this->books=new Book[s.brojj];
        for (int i = 0; i < s.brojj; i++) {
            books[i] = s.books[i];
        }
    }

    BookStore& operator=(const BookStore &s) {
        if (this != &s) {
            delete [] books;
            strcpy(this->ime, s.ime);
            this->brojj = s.brojj;
            this->books = new Book[s.brojj];
            for (int i = 0; i < s.brojj; i++) {
                books[i] = s.books[i];
            }
        }
        return *this;
    }

    ~BookStore() {
        delete [] books;
    }

    BookStore &operator+=(const Book &b){
        for(int i=0;i<brojj;i++){
            if(books[i].getSeriski()==b.getSeriski()){
                return *this;
            }
        }
        Book *temp=new Book[brojj+1];
        for(int i=0;i<brojj;i++){
            temp[i]=books[i];
        }
        temp[brojj++]=b;
        delete [] books;
        books=temp;
        return *this;
    }

    BookStore &operator -=(const Book &b){
        int index=-1;
        for (int i=0;i<brojj;i++) {
            if (books[i].getSeriski()==b.getSeriski()) {
                index=i;
            }
        }
        if (index==-1) {
            return *this;
        }

        Book *temp=new Book[brojj-1];
        int j=0;
        for (int i=0;i<brojj;i++) {
            if (i!=index) {
                temp[j]=books[i];
                j++;
            }
        }
        delete [] books;
        books= temp;
        brojj--;

        return *this;
    }





    friend ostream & operator <<(ostream & pecati,const BookStore &s ) {
        pecati<<s.ime<<endl;
        for (int i=0;i<s.brojj;i++) {
            cout<<s.books[i];
        }
        return pecati;
    }
    bool operator >(const BookStore &s) {
        if (this->brojj>s.brojj) {
            return true;
        }
        return false;
    }

    void createMarketPrice() {
        for (int i=0;i<brojj;i++) {
            if (books[i].getTip()==strucna) {
                books[i]+= books[i].getCena()*0.05;
            }
            else if (books[i].getTip()==roman) {
                books[i]+= books[i]. getCena()*0.03;
            }
        }
    }
};

BookStore best(BookStore *stores,int n) {
    int max=0;
    for (int i=0;i<n;i++) {
        if (stores[i]>stores[max]) {
            max=i;
        }
    }
    return stores[max];

}
int Book::generator=777550;
int main() {
     int testCase;
    cin >> testCase;
    if (testCase == 0) {
        cout << "TESTING BOOK CONSTRUCTOR" << endl;

        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);

        cout << "TEST PASSED" << endl;
    }
    else if (testCase == 1) {
        cout << "TESTING BOOK OPERATOR <<" << endl;

        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);

        cout << book1 << endl;
        cout << book2 << endl;
        cout << book3 << endl;

        cout << "TEST PASSED" << endl;
    }
    else if (testCase == 2) {
        cout << "TESTING BOOKSTORE OPERATOR <<" << endl;

        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);

        BookStore bookStore1("The Book Cellar");

        bookStore1 += book1;
        bookStore1 += book2;
        bookStore1 += book3;

        cout << bookStore1;

        cout << "TEST PASSED" << endl;
    }
    else if (testCase == 3) {
        cout << "TESTING BOOKSTORE OPERATOR += and <<" << endl;

        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);

        BookStore bookStore1("The Book Cellar");

        bookStore1 += book1;
        bookStore1 += book2;
        bookStore1 += book3;

        cout << bookStore1;

        bookStore1 += book1;
        cout << bookStore1;

        cout << "TEST PASSED" << endl;
    }
    else if (testCase == 4) {
        cout << "TESTING BOOKSTORE OPERATOR >" << endl;

        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);

        BookStore bookStore1("The Book Cellar");
        BookStore bookStore2("Word Wizard");

        bookStore1 += book1;
        bookStore1 += book2;

        bookStore2 += book3;

        cout << bookStore1;
        cout << bookStore2;

        if (bookStore1 > bookStore2) {
            cout << "The first bookstore has more books." << endl;
        } else {
            cout << "The second bookstore has more books or they are equal." << endl;
        }

        cout << "TEST PASSED" << endl;
    }
    else if (testCase == 5) {
        cout << "TESTING MARKET PRICE AND BEST" << endl;

        BookStore stores[2];

        stores[0] = BookStore("Store1");
        stores[1] = BookStore("Store2");

        Book b1("A", 0, 100);
        Book b2("B", 1, 200);
        Book b3("C", 0, 300);

        stores[0] += b1;
        stores[0] += b2;

        stores[1] += b3;

        stores[0].createMarketPrice();
        stores[1].createMarketPrice();

        cout << best(stores, 2);

        cout << "TEST PASSED" << endl;
    }

    return 0;
}
