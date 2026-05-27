#include<iostream>
using namespace std;
int main(){
    int m,n,brojac=0;
    cin>>m>>n;
    int a[100][100];
    int b[100][100];
    for(int i=0;i<m;i++){//tri pati
        for(int j=0;j<n;j++){//tri pati po tri
            cin>>a[i][j];
        }
    }

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>b[i][j];
        }
    }



    for(int j=0;j<n;j++) { //4 pati
        bool najden=false;

        for(int i=0;i<n;i++) {//4 po 4
            bool istaKolona=true;
            for(int k=0;k<m;k++){//4 po 4 po 4
                if(a[k][j]!=b[k][i]){
                    istaKolona=false;
                    break;
                }
            }
            if(istaKolona){
                najden=true;
                break;
            }
        }
        if(najden){
            brojac++;
        }
    }
    cout<<brojac<<endl;
}