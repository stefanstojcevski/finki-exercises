#include <iostream>
using namespace std;
int filter(int n, int *a, int *min,int *max,int pozmin,int pozmax) {
    for (int i=0; i<n;i++) {
        if ((a+i)>max) {
            max=(a+i);
            pozmax=i;
        }
        if ((a+1)<min) {
            min=(a+i);
            pozmin=i;
        }
    }

}




int main() {
    int n;
    int pozmin=0;
    int pozmax=0;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> (a+i);
    }
    int min = (a+0);
    int max = (a+0);
    filter(n, a,  &min, &max, pozmin, pozmax);
    cout<<"Min:"<<min<<" pozMin: "<<pozmin<<endl;
    cout<<"Max:"<<max<<" pozMax: "<<pozmax<<endl;
}





/*
*#include<iostream>
using namespace std;
int minMax(int *a,int n,int *min,int max,int pozMin,int pozMax){
        for(int i=0;i<n;i++){
        if((a+i)>max){
            max=(a+i);
            pozMax=i;
        }
            if((a+i)<min){
            min=(a+i);
                pozMin=i;
        }
    }
}
int main(){
    int a[100];
    int n,pozMin=0,pozMax=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>(a+i);
    }
    int min=(a+0);
    int max=(a+0);
    minMax(a,n,&min,&max,&pozMin,&pozMax);
    cout<<"Min:"<<min<<" pozMin: "<<pozMin<<endl;
    cout<<"Max:"<<max<<" pozMax: "<<pozMax<<endl;
    if(pozMin<pozMax){
            for(int i=pozMin;i<=pozMax;i++){
        cout<<(a+i)<<" ";
    }
}
    else{
            for(int i=pozMax;i<=pozMin;i++){
        cout<<(a+i)<<" ";
        }
    }

}
 *
 *
 **/