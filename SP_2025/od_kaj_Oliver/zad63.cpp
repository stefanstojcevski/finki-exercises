#include<iostream>
using namespace std;
int Njgolemi(int a[],int n){
    int max1=0;
    int max2=0;
    for(int i=0;i<n;i++){
        if(a[i]>max1){
            max2=max1;
            max1=a[i];
        }
        else if(a[i]>max2 && a[i]!=max1){
            max2=a[i];
        }
    }
    cout<<"max1:"<<max1<<endl;
    cout<<"max2:"<<max2<<endl;
}
int main(){
    int n,sum=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
    }
    cout<<"arst:"<<sum/n<<endl;
    Njgolemi(a,n);
}