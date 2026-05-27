#include <iostream>
#include<cstring>
using namespace std;
int main() {
    char a[100],maxA[100],pr,po;
    bool ePRVA=true;
    int zemiprva=0;
    int zemiposledna=0;
    int max=0;
    int brojacvkupno=0;

    while (cin.getline(a,100) && a[0]!='#') {
        for (int i=0;i<strlen(a);i++) {
            int brojac=0;
            ePRVA=true;
            if (isnumber(a[i])) {
                if (ePRVA) {
                    brojac++;
                    zemiprva=i;
                    ePRVA=false;
                }
                else {
                    brojac++;
                    zemiposledna=i;
                }
            }
            if (brojac>1 && brojacvkupno>=max) {
                max=brojacvkupno;
                strcpy(maxA,a);
                pr=zemiprva;
                po=zemiposledna;
            }
            brojacvkupno=0;
            brojac=0;
        }
            for (int i=pr;i<=po;i++) {
                cout<<maxA[i]<<" ";
            }



        }

    }
