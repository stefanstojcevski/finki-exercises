/*
*Да се напише функциска програма што како влезни аргументи прима низа од знаци. Функцијата
враќа 1 ако низата го дава истиот стринг читано одлево надесно и одесно налево, во спротивно
враќа 0.
Пример: adv37465.?fr@rf?.56473vda
 *
 **/
#include<iostream>
#include<cstring>
using namespace std;
bool palindrom_niza(char *a){
 int n=strlen(a);
 for (int i=0;i<n/2;i++) {
  if ((*(a+i))!=(*(a+n-i-1))) {
    return false;
  }
 }
 return true;

}
int main(){
 char a[1000];
 cin.getline(a,1000);
 if (palindrom_niza(a)) {
  cout<<"E PALINDROM"<<endl;
 }
 else if (!palindrom_niza(a)){
  cout<<"NE E PALINDROM"<<endl;
 }


}