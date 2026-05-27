/*
*1. Se vnesuva N i niza od N broevi.
*Da se najde aritmeticka sredina i prviot clen pogolem od najmaliot clen od nizata (fakticki toj so najmala razlika)
/*
#include <iostream>
using namespace std;
int vtorNAJMAL(int n,int a[]) {
 for (int i=0;i<n-1;i++) {
  for (int j=i+1;j<n;j++) {
   if (a[i]>a[j]) {
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
   }

  }
 }
 if (a[0]!=a[1]) {
  return a[1];
 }
 else {
  return a[2];
 }
}
int main() {
 int n;
 int zbir=0;
 cin>>n;
 int a[n];
 for (int i=0;i<n;i++) {
  cin>>a[i];
  zbir+=a[i];
 }
 float sredna=(float)zbir/(float)n;
 cout<<"sredna---> "<<sredna<<endl;
 cout<<"vtornajmal----->"<< vtorNAJMAL(n,a);


}
2. Se vnesuva N i N recenici. Da se napravi funkcija koja ke ja transformira nizata taka sto ke nema soglaski i brojki.
Samoglaskite ostanuvaat bez razlika dali se golemi bukvi ili mali bukvi.

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void PRESVRT(char a[], char glavna[]) {
    int n = strlen(a);
    int q = 0;
    for (int i = 0; i < n; i++) {
            if (tolower(a[i]) == 'a' || tolower(a[i]) == 'e' || tolower(a[i]) == 'i' || tolower(a[i]) == 'o' ||
                tolower(a[i]) == 'u') {
                glavna[q] = a[i];
                q++;
            } else {
                continue;
            }
        }
 glavna[q]='\0';
}

int main() {
    int n;
    char a[100];
    char glavna[100];
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin.getline(a, 100);
        PRESVRT(a, glavna);
        cout<<glavna;
    }
}
3. Se vnesuvaat m i n i matrica mxn.
Da se napravi rekurzivna funkcija koja ke prima niza i golemina na niza.
Nizata pretstavuva red od samata matrica. Funkcijata vrakja 1 dokolku elementite od
redot odat naizmenicno po golemina pogolem pomal pogolem pomal i obratno a vrakja 0 dokolku ne.
Na kraj se pecati vo format br na red:dali e 0 ili 1 za site redovi
*/
#include <iostream>
using namespace std;

int REKURZIJA(int a[], int n) {
    if (n <= 2) {
        return 1;
    }
    if ((a[n - 3] < a[n - 2] && a[n - 2] > a[n - 1]) || (a[n - 3] > a[n - 2] && a[n - 2] < a[n - 1])) {
        return REKURZIJA(a, n - 1);
    }

    return 0;
}

int main() {
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        if (REKURZIJA(a[i], n) == 1) {
            cout << "1" << endl;
        } else {
            cout << "0";
        }
    }
}
