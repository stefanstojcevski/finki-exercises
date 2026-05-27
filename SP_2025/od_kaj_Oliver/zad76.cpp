/*
*Se vnesuvaat mi n i matrica mxn. Da se napravi rekurzivna funkcija koja ke prima niza i golemina na niza.
*Nizata pretstavuva red od samata matrica.
*Funkcijata vrakja 1 dokolku elementite od redot odat naizmenicno po golemina pogolem pomal pogolem pomal i obratno a vrakja 0 dokolku ne.
Na kraj se pecati vo format br na red:dali e 0 ili 1 za site redovi
 **/

#include<iostream>
using namespace std;
int naizmenicno(int *a,int n,bool akoPrviotEPoglem=true) {
 if(n<=1){
  return 1;
 }
 if((akoPrviotEPoglem && a[0]>=a[1]) || (!akoPrviotEPoglem && a[0]<=a[1])){
  return 0;
 }
 return naizmenicno(a+1,n-1,!akoPrviotEPoglem);
}

int main() {
 int m,n;
 int a[m][n];
 for (int i=0;i<m;i++) {
  for (int j=0;j<n;j++) {
   cin>>a[i][j];
  }
 }
 for (int i=0;i<m;i++) {
  int rezultat=naizmenicno(a[i],n);
  cout<<i+1<<":"<<rezultat<<endl;

 }


}
/*
*#include <iostream>
#include <cstring>
using namespace std;

int naizmenicno(int *a,int n,bool akoPrviotEPoglem=true) {
if(n<=1){
 return 1;
}
if((akoPrviotEPoglem && a[0]>=a[1]) || (!akoPrviotEPoglem && a[0]<=a[1])){
 return 0;
}
return naizmenicno(a+1,n-1,!akoPrviotEPoglem);
}


int main() {
    int m,n;

 cin >> m>>n;

    int a[m][n];

    for (int i = 0; i <m; i++) {
       for (int j = 0;j <n; j++) {
      cin>>a[i][j];
    }
    }

   for (int i = 0; i <m; i++) {
    int rezultat=naizmenicno(a[i],n);
    cout<<i+1<<":"<<rezultat<<endl;
   }
}
 *
 *
 *
 **/