#include <iostream>
#include <cstring>
using namespace std;
int SVRZNICI(char a[]) {
    int n=strlen(a);
    int brojacB=0;
    int brojacG=0;
    for (int i=0;i<n;i++) {
        if (isspace(a[i])) {
            if (brojacB<=3 && brojacB>=1) {

                brojacG++;
            }
            brojacB=0;
        }
        if (isalpha(a[i])) {
            brojacB++;
        }

    }
    if (brojacB<=3 && brojacB>=1) {
        brojacG++;
    }
    return brojacG;

}
int main() {
    char a[100];
    char max[100];
    int MAX=0;
    while (cin.getline(a,100)) {

        if (SVRZNICI(a)>MAX) {
            strcpy(max,a);
            MAX=SVRZNICI(a);
        }




    }
    cout<<MAX<<": "<<max;
}