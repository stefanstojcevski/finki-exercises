/*Korisnikto vnesuva niza od n broevi da se podredi (Sortira) nizata vo rastecki redosled
5
12 3 45 8 90
izlez:
3 8 12 45 90
--------------
i  j
12 3 45 8 90
i           j
3  12 45 8 90
   i       j
3 12  45 8 90
      i  j
3 8  45 12 90
        i   j
3 8  12 45 90
*/
#include<iostream>
using namespace std;
int podreduvajne (int a[],int n) {
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (a[i]>a[j]) {
                int zam=a[i];
                a[i]=a[j];
                a[j]=zam;
            }
        }
    }

}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    podreduvajne(a,n);
    for (int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }

    return 0;
}