/*
*Да се креира структура Книга за која се чува името на книгата (низа од карактери), ISBN (низа од карактери),
*број на луѓе кои ја имаат прочитано книгата и рејтинг на книгата.

Потоа да се дефинира структура Автор за која се чува името на авторот (низа од карактери),
презиме (низа од карактери), број на книги што ги има напишано и низа од книги што ги има напишано.

Да се надополни main функцијата така што ќе се прочитаат n автори заедно со книгите што ги имаат напишано.

Потребно е да се креираат две функции:

- void mostPopularAuthor(author authors[100], int n) која на екран ќе испечати Most popular author: ИМЕ

- void mostPopularBookByAuthor(author authors[100], int n) which will print the most popular on the screenwhich will print the most popular book of the author who has written the least number of books in the format Author: NAME SURNAME, Most popular book: NAME, ISBN of the book
Note: the most popular book is the one with the highest rating, the most popular author is the one whose books have been read by the largest number of people, the book of the author who has written the fewest books in the format Author: NAME SURNAME, Most popular book: NAME, ISBN of the book
Note: the most popular book is the one with the highest rating, the most popular author is the one whose books have been read by the most people
input:
3
J.K
Rowling
3
Stone
ISBN12345
5000
9.3
Secrets
ISBN67890
4000
8.8
Azkaban
ISBN11121
333
9.5
George
Martin
1
Thrones
ISBN56565
1500
8.5
J.R.R
Tolkien
2
Hobbit
ISBN121212
200
5.3
Rings
ISBN32363
3500
2.2
output:
Most popular author: J.K Rowling
Author: George Martin, Most popular book: Thrones, ISBN56565/
 *
 **/

#include <iostream>
using namespace std;
struct Kniga {
 char ime[30];
 char ISBN[30];
 int brojCitateli;
 float rejting;
};
struct Avtor {
 char ime[30];
 char prezime[30];
 int brojKnigi;
 Kniga nizaKnigi[30];
};
void mostPopularAuthor(Avtor avtori[], int n) {
 int najpoznat=0;
 int index;
 for (int i=0;i<n;i++) {
  int vkupno=0;
  for (int j=0;j<avtori[i].brojKnigi;j++) {
   vkupno+=avtori[i].nizaKnigi[j].brojCitateli;

  }
  if (vkupno>najpoznat) {
   najpoznat=vkupno;
   index=i;
  }
 }
 cout<<"Most popular author: "<<avtori[index].ime<<endl;
}
void mostPopularBookByAuthor(Avtor avtori[100], int n) {
 int min=0;
 int najmal=0;

 for (int i=0;i<n;i++) {
  if (avtori[i].brojKnigi<avtori[najmal].brojKnigi) {
    najmal=i;
  }
 }
int max=0;

  for (int j=0;j<avtori[najmal].brojKnigi;j++) {
   if (avtori[najmal].nizaKnigi[j].rejting>avtori[najmal].nizaKnigi[max].rejting)
   max=j;
  }


 cout<<"Author: "<<avtori[najmal].ime<<","<<" Most popular book: "<<avtori[najmal].nizaKnigi[max].rejting<<", "<<avtori[najmal].nizaKnigi[max].ISBN;




}
int main() {
 int n;
 cin>>n;
 Avtor avtori[n];
 for (int i=0;i<n;i++) {
  cin>>avtori[i].ime>>avtori[i].prezime>>avtori[i].brojKnigi;
  for (int j=0;j<avtori[i].brojKnigi;j++) {
   cin>>avtori[i].nizaKnigi[j].ime>>avtori[i].nizaKnigi[j].ISBN>>avtori[i].nizaKnigi[j].brojCitateli>>avtori[i].nizaKnigi[j].rejting;
  }
 }
 mostPopularAuthor( avtori, n);
 mostPopularBookByAuthor(avtori, n);
}