/*
 i  j     i  j     i  j
[0][0]   [0][1]   [0][2]
[1][0]   [1][1]   [1][2]
[2][0]   [2][1]   [2][2]


*/
#include <iostream>
#include <cstring>
using namespace std;
void podreduvajne_parni(int a[],int o) {
 for (int i = 0; i < o-1; i++) {

  for (int j = i+1; j < o; j++) {

   if (a[i] > a[j]) {

    int temp = a[i];

    a[i] = a[j];

    a[j] = temp;

   }

  }
 }
 for (int i = 0; i < o; i++) {
  cout<<a[i]<<endl;
 }
}


void podreduvajne_neaparni(int a[],int p) {
 for (int i = 0; i < p-1; i++) {

  for (int j = i+1; j < p; j++) {

   if (a[i] < a[j]) {

    int temp = a[i];

    a[i] = a[j];

    a[j] = temp;

   }

  }
 }
 for (int i = 0; i < p; i++) {
  cout<<a[i]<<endl;
 }
}
int main() {
 int n;
 int o;
 int p;
 int zbir=0;
 int a[o];
 int b[p];
 while (cin>>n) {

  if (n%2==0) {
   zbir+=n;
   a[o]=n;
   o++;
   podreduvajne_parni( a, o);
  }
  else {
   b[p]=n;
   p++;
   podreduvajne_neaparni( a, p);
  }
 }


}
