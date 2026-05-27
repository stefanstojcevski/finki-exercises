#include<iostream>
using namespace std;
class Category {
private:
    char ime[20];
public:
    Category() {
        strcpy(this->ime,"unname");
    }

    Category( char ime[20]) {
        strcpy(this->ime,ime);
    }


    void print() {
        cout<<ime<<endl;
    }


};





class NewsArticle {
private:
    Category category;
    char title[30];
public:
    NewsArticle() {
        this->category=Category();
        strcpy(this->title,"untitlted");

    }

    NewsArticle(Category category,char title[30]) {
        this->category=category;
        strcpy(this->title,title);

    }
    NewsArticle(Category category) {
        this->category = category;
        strcpy(this->title, "untitled");
    }

    void print() {
        category.print();
        cout<<title<<endl;
    }

};




class FrontPage {
private:
    NewsArticle newarticle;
    float cena;
    int editionNumber;
public:

    FrontPage() {
        this->newarticle=NewsArticle();
        this->cena=0;
        this->editionNumber=0;
    }

    FrontPage(NewsArticle newarticle,float cena,int editionNumber) {
        this->newarticle=newarticle;
        this->cena=cena;
        this->editionNumber=editionNumber;
    }
    FrontPage(NewsArticle newarticle, float cena) {
        this->newarticle = newarticle;
        this->cena = cena;
        this->editionNumber = 0;
    }


    void print() {
        cout<<cena<<" "<<editionNumber<<endl;
        newarticle.print();

    }
};




int main() {
    char categoryName[20];
    char articleTitle[30];
    float price;
    int editionNumber;

    int testCase;
    cin >> testCase;


    if (testCase == 1) {
        int iter;
        cin >> iter;
        while (iter > 0) {
            cin >> categoryName;
            cin >> articleTitle;
            cin >> price;
            cin >> editionNumber;
            Category category(categoryName);
            NewsArticle article(category, articleTitle);
            FrontPage frontPage(article, price, editionNumber);
            frontPage.print();
            iter--;
        }
    }
    else if (testCase == 2) {
        cin >> categoryName;
        cin >> price;
        cin >> editionNumber;
        Category category(categoryName);
        NewsArticle article(category);
        FrontPage frontPage(article, price, editionNumber);
        frontPage.print();
    }// test case 3
    else if (testCase == 3) {
        cin >> categoryName;
        cin >> articleTitle;
        cin >> price;
        Category category(categoryName);
        NewsArticle article(category, articleTitle);
        FrontPage frontPage(article, price);
        frontPage.print();
    }
    else {
        FrontPage frontPage = FrontPage();
        frontPage.print();
    }
    return 0;
}