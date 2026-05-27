#include <iostream>
using namespace std;
int main() {
    int a[100];
    int b[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for (int j = 0; j < n; j++) {
        cin>>b[j];
    }
    bool isti=true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            isti=false;
            break;
        }
    }
    if (isti) {
        cout<<"ISTI"<<endl;
    } else {
        cout<<"NE SE ISTI"<<endl;
    }
    return 0;


}