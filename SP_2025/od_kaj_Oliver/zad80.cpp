#include <iostream>
using namespace std;
void pomestuvajne(char a[], int x, int i) {
    if (a[i]=='\0') {
        return;

    }
    int bukva = a[i];
    if (isalpha(a[i])) {
        bukva=a[i]+x;
        if (isupper(a[i])) {
            if (bukva > 'Z')
                bukva = (bukva - 'A') % 26 + 'A';
        } else if (islower(a[i])) {
            if (bukva > 'z')
                bukva = (bukva - 'a') % 26 + 'a';
        }
        a[i]=bukva;
    }
    pomestuvajne(a, x, i +1);



}
int main() {
    int x, n;
    cin>>n>>x;
    cin.ignore();
    char a[80];
    for (int i=0; i<n; i++) {
        cin.getline(a,80);
        pomestuvajne(a,x,0);
        cout<<a<<endl;


    }

}