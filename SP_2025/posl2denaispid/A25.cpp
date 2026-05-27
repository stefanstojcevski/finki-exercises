/*
Da se najde najgolgiot zbor vo edna recenica ama samo dolzinata negova?
primer: Zdravo Oliver Nikolajevic kako si denes?
izlez:11
*/
#include<iostream>
#include<cstring>
using namespace std;
int main(){
 char a[1000];
 cin.getline(a,1000);
 int brojac=0,pocetok=0,kraj=0,max=0,maxPocetok=0;
 for(int i=0;a[i]!='\0';i++){
  if(a[i]!=' '){
   if(brojac==0){
    pocetok=i;
   }
   brojac++;
  }
  else{
   if(brojac>max){
    max=brojac;
    maxPocetok=pocetok;
   }
   brojac=0;
  }
 }
 if(brojac>max){
  max=brojac;
  maxPocetok=pocetok;
 }
 for(int i=maxPocetok;i<maxPocetok+max;i++){
  cout<<a[i];
 }

 cout<<" Najdolgiot zbor ima "<<max<<" znaci"<<endl;


}





