#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
    char naslov[30];
    int strani;

public:
    Book() {
        strcpy(this->naslov, "TEST BOOK");
        this->strani = 0;
    }

    Book(char naslov[30], int strani) {
        strcpy(this->naslov, naslov);
        this->strani = strani;
    }

    Book(const Book &b) {
        strcpy(this->naslov, b.naslov);
        this->strani = b.strani;
    }

    Book& operator=(const Book &b) {
        if (this!=&b) {
            strcpy(this->naslov, b.naslov);
            this->strani = b.strani;
        }
        return *this;
    }


    void readPages(int pages) {
        strani += pages;
        if (strani > 200) {
            strani = 200;
        }
    }

    friend ostream & operator<<(ostream & pecati,const Book &b) {
        pecati << b.naslov << " - " << b.strani << "/200 - ";
        if (b.strani < 100) {
            pecati << "IN PROGRESS" << endl;
        } else if (b.strani < 200) {
            pecati << "ALMOST DONE" << endl;
        } else if (b.strani == 200) {
            pecati << "FINSHED" << endl;
        }
        return pecati;
    }
};

int main() {
    int n;
    cin>>n;
    Book b;
    char naslov[30];
    int strani;
    int pages;
    for (int i=0;i<n;i++) {
        cin>> naslov;
        cin >> strani;
        b = Book(naslov, strani);
        cin >> pages;
        b.readPages(pages);
        cout<<b;
    }
}
