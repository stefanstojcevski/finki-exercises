#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
void funkcija(char a[],char b[]) {
    int q=0;
    int n=strlen(a);
    for (int i=0;i<n;i++) {
        if (tolower(a[i])== 'a' || tolower(a[i])== 'e' || tolower(a[i])== 'i' || tolower(a[i])== 'o' || tolower(a[i])== 'u') {
            continue;
        }
        else {
            b[q]=a[i];
            q++;
        }
    }
    b[q]='\0';
}
int main() {
    int n;
    cin>>n;
    cin.ignore();
    char b[100];
    char a[100];
    for (int i=0;i<n;i++) {
        cin.getline(a , 100);
        funkcija(a,b);
        cout<<b;

    }
}