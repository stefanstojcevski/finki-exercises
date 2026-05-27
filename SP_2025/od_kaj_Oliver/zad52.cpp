/*
*курзДа се напише реивна функција која што прима еден аргумент
-број x истата ќе враќа 1 доколку секоја цифра во бројот е поголема од претходната, а во спротивно 0.
Пример бројот 12345 е растечки, додека пак бројот 12325 не е растечки број.
Од стандарден влез се вчитува прво број N, а потоа N броеви. За секој број да се испечати 1 или 0 (во нов ред),
доколку бројот е растечки или не е растечки.
 *
 **/


#include<iostream>
using namespace std;
int rastecki(int x){
    if(x<10){
        return 1;
    }
    int poslednaCifra=x%10;
    int predPoslednaCifra=(x/10)%10;
    if(poslednaCifra<=predPoslednaCifra){
        return 0;
    }

    return rastecki(x/10);

}
int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        cout<<rastecki(x)<<endl;
    }
}