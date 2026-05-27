#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
void promena(char a[],char b[]) {
    int q=0;
    for (int i=0;i<strlen(a);i++) {
        if (tolower(a[i])== 's') {
            b[q]='$';
            q++;
        }
        else if (tolower(a[i])=='m') {
            b[q]='^';
            b[q+1]='^';
            q+=2;
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
    char max[100];
    cin>>n;
    cin.ignore();
    char a[100];
    char b[100];
    max[0] = '\0';
    for (int i=0;i<n;i++) {
        cin.getline(a,80);
        promena( a,b);
        if (strlen(b)>strlen(max)) {
            strcpy(max,b);
        }
    }
    cout<<max;
}