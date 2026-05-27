#include <iostream>
#include <iomanip>
using namespace std;
struct transaction {
    int id;
    int sum;
    int commission;
    int type;
};
int main() {
    int n;
    cin>>n;
    transaction a[100];
    int flag=0;
    for (int i=0;i<n;i++) {
        cin>>a[i].id>>a[i].sum>>a[i].commission>>a[i].type;
    }
    for (int i=0;i<n;i++) {
        if (a[i].type==1) {
            cout<<a[i].id<<" "<<a[i].commission+a[i].sum<<endl;
            flag=1;
        }
    }
    if (flag==0) {
        cout<<"se e plateno bez karticka"<<endl;
    }
}