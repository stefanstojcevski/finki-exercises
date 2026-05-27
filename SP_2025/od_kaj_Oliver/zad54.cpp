/*
 *Да се имплементира рекурзивна функција int mask (int number, int k) која што во бројот number ќе ги замени сите цифри <= од k со 0,
 *а сите цифри > к со 1. Пример: Влез number = 771256, k = 3 Резултат: 110011 (цифрите 7,5,6 бидејќи се поголеми од k=3 се маскираат во 1,
 *а цифрите 1 и 2 бидејќи се <= k се маскираат во 0)
 *
 *
 **/
#include<iostream>
using namespace std;

int mask(int number,int k){
    if(number==0){
        return 0;
    }
    int cifra=number%10;
    int maskCifra;
    if(cifra>k){
        maskCifra=1;
    }
    else{
        maskCifra=0;
    }
    return mask(number/10,k)*10+maskCifra;
}
int main(){
    int number,k;
    cin>>number>>k;
    cout<<mask(number,k)<<endl;
}