#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
void presvrt(char a[],char glaven[]) {
    int q=strlen(a);
    int j=0;
    for (int i=0;i<q;i++) {
        if (isspace(a[i])) {
            glaven[j]='*';
            j++;

        }
        else if (tolower(a[i])== 'q' || tolower(a[i])== 'w' || tolower(a[i])== 'e' || tolower(a[i])== 'r' || tolower(a[i])== 't' || tolower(a[i])== 'y' || tolower(a[i])== 'u' || tolower(a[i])== 'i' || tolower(a[i])== 'o' || tolower(a[i])== 'p' ) {
            continue;
        }
        else {
            glaven[j]=a[i];
            j++;
        }

    }
    glaven[j]='\0';

}
int main() {
    int n;
    cin>>n;
    cin.ignore();
    char a[100];
    char glaven[100];

    for (int i=0;i<n;i++) {
        cin.getline(a,100);
        presvrt(a,glaven);
        cout<<glaven;



    }



}