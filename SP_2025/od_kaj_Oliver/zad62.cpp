#include <iostream>
using namespace std;
void ispecatiObratnoNiza(int a,int n) {
    for(int i=n-1;i>=0;i--){
        cout<<(a+i)<<" ";
    }
}
int main() {
    int a[100];
    int n,pozMin=0,pozMax=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>*(a+i);
    }
    ispecatiObratnoNiza(a,n);

    }

}
/*#include<iostream>
using namespace std;
void ispecatiObratnoNiza(int a,int n){
        for(int i=n-1;i>=0;i--){
    cout<<(a+i)<<" ";
    }
}

int main(){
    int a[100];
    int n,pozMin=0,pozMax=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>*(a+i);
    }
    ispecatiObratnoNiza(a,n);

}
 *
 *
 *
 **/