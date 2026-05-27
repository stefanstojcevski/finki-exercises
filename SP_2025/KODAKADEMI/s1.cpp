/*
 **/
#include<iostream>
#include<cstring>
using namespace std;
void parni(int n,int *zbir) {
 if (n==0) {
  return;
 }
 int cifra=n%10;
 if (cifra % 2 == 0) {
  cout << cifra << " ";
  *zbir += cifra;
 }

parni(n/10,zbir);
 if (cifra % 2 != 0) {
  cout << cifra << " ";
 }

}

int main() {
 int n;
 int zbir=0;
 while (cin>>n) {
  parni(n,&zbir);

 }


}
