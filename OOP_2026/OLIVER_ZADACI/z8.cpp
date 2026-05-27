#include <iostream>
using namespace std;
struct Footballplayer {
    char ime[100];
    int brojdres;
    int brojgolovi;
};
struct Footballteam {
    char ime[100];
    Footballplayer fudbaleri[11];

};
void bestTeam(Footballteam a[], int n) {
    int najmnogu=0;
    int index;

    for (int i=0;i<n;i++) {
        int max=0;
        for (int j=0;j<11;j++) {
            max+=a[i].fudbaleri[j].brojgolovi;
        }
        if (max>najmnogu) {
            najmnogu=max;
            index=i;
        }

    }
    cout<<"najdobar tim e:"<<a[index].ime;


}
int main() {
    int n;
    cin>>n;
    Footballteam a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i].ime;
        for (int j=0;j<11;j++) {
            cin>>a[i].fudbaleri[j].ime>>a[i].fudbaleri[j].brojdres>>a[i].fudbaleri[j].brojgolovi;
        }
    }
    bestTeam(a, n);

}