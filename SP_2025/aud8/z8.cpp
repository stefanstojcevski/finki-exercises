#include <iostream>
using namespace std;
int main() {
    int broj;
    int counter[10]={0};
    while(cin>>broj) {
        counter[broj]++;
    }
    for (int i=0;i<10;i++) {
        cout<<counter[i]<<" "<<endl;
    }
    return 0;
}