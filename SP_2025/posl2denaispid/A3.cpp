#include<iostream>
using namespace std;
void REKURZIJA(int n) {
    if (n<=0) {
        return;
    }
    cout<<n<<" ";

    REKURZIJA(n-3);
    cout<<n<<" ";


}
int main() {
    int n;
    cin>>n;
    REKURZIJA(n-3);

}