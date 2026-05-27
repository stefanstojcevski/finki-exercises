#include<iostream>
#include<cstring>
using namespace std;
bool ePalindrom(char a[]) {
    int n=strlen(a);
    for (int i=0; i<n; i++) {
        if (a[i]!=a[n-i-1]) {
            return false;
        }
        return true;
    }
}
    bool imaCUDENZNAK(char a[]) {
    int n=strlen(a);
    for (int i=0;i<n;i++){
        if (ispunct(a[i])) {
            return true;
        }
    }
    return false;

}
int main() {
    int n;
    char max[80];
    int flag;
    int maxdolzina=0;
    cin>>n;
    char a[80];
    for (int i=0;i<n;i++) {
        cin>>a[i];
        if (ePalindrom && imaCUDENZNAK ) {
            flag=1;
            if (maxdolzina<strlen(a)) {
                maxdolzina=strlen(a);
                strcpy(max,a);
            }


        }
    }
    if (flag==1) {
        cout<<max;
    }
    else {
        cout<<"NEMA!"<<endl;
    }
}