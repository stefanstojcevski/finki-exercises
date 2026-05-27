/*
*1. Da se najde vtoriot najgolem element na nizata (samo so edno izminuvanje na nizata) i aritmetichkata sredina na nizata
2. Ista kako pogore
3. Se vnesuva matrica i So rekurzija da se najde dali elementite na parni pozicii od sekoj od redovite na matricata se strogo rastechki
(ili opagjachki ne sum sigurna) a elementite na neparni obratno (strogo opagjachki mislam) (vo nekoj labaraorii pishale deka mora samo so
edna funckija, kaj mene nishto ne kazaa)
 *

#include <iostream>
using namespace std;
void najgolemi(int a[],int n,int *max1, int *max2) {
 for (int i=0;i<n;i++) {
  if (a[i]>*max1) {
   *max2=*max1;
   *max1=a[i];
  }
  if (a[i]>*max2 && a[i]!=*max1){
   *max2=a[i];
  }
 }
 }
 int main() {
  int n;
  int max1=-9999;
  int max2=-99999;
  cin>>n;
  int a[n];
 int zbir=0;
  for (int i=0;i<n;i++) {
   cin>>a[i];
   zbir+=a[i];

  }
 najgolemi(a ,n,&max1, &max2);
 cout<<zbir/n<<endl;
 cout<<max1<<"  "<<max2;
 }

 k    k      k       k
r  [0.1] [0.2] [0.3] [0.4]
r  [1.1] [1.2] [1.3] [1,4]
r  [2.1] [2.2] [2.3] ][2.4]


Se vnesuva matrica i So rekurzija da se najde dali elementite na parni pozicii od sekoj od redovite na matricata se strogo rastechki
(ili opagjachki ne sum sigurna) a elementite na neparni obratno (strogo opagjachki mislam) (vo nekoj labaraorii pishale deka mora samo so
edna funckija, kaj mene nishto ne kazaa)
 */

#include <iostream>
using namespace std;
int REKURZIJA(int a[],int n) {
 if (n<10) {
  return 1;
 }
 if (a[n%2==0] && a[n-1]<a[n-3]) {
  return 0;
 }
 else if (a[n%2!=0] && a[n-1]>a[n-3]) {
  return 0;
 }
 return REKURZIJA(a,n-1);

}
int main() {
 int m,n;
 cin>>m>>n;
 int a[m][n];
 for (int i=0;i<m;i++) {
  for (int j=0;j<n;j++) {
   cin>>a[i][j];
  }
 }
 for (int i=0;i<m;i++) {
  REKURZIJA(a[i],n);

 }

}