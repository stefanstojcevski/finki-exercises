#include<iostream>
using namespace std;
int Njgolemi(int *a,int n,int *max,int *min,int *sum){
    int razlika=0;
    for(int i=0;i<n;i++){
        *sum=*sum+a[i];
        if(a[i]>*max){
            max=(a+i);
        }
        if(a[i]<*min){
            min=(a+i);
        }
    }
    razlika=*max-*min;
    for(int i=0;i<n;i++){
        (*(a+i))+=razlika;
    }



}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    int max=a[0];
    int min=a[0];
    int sum=0;
    Njgolemi(a,n,&max,&min,&sum);
    cout<<"MAX -> "<<max<<endl;
    cout<<"MIN -> "<<min<<endl;
    cout<<"SUM -> "<<sum<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}