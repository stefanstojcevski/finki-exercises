#include <iostream>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    char teren[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            teren[i][j]='-';
        }
    }
    int topka_x,topka_y;
    cin>>topka_x>>topka_y;
    teren[topka_x][topka_y]='o';
    int igrac_x, igrac_y;
    cin>>igrac_x>>igrac_y;
    teren[igrac_x][igrac_y]='i';
    int stativa1_x,stativa1_y,stativa2_x,stativa2_y;
    cin>>stativa1_x>>stativa1_y>>stativa2_x>>stativa2_y;
    for (int i=stativa1_x;i<=stativa2_x;i++) {
        for (int j=stativa1_y;j<=stativa2_y;j++) {
            teren[i][j]=']';
        }
    }
    teren[topka_x][topka_y]='-';
    int dx,dy;
    cin>>dx>>dy;
    int new_x,new_y;
    new_x=topka_x+dx;
    new_y=topka_y+dy;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cout<<teren[i][j]<<" ";
        }
        cout<<endl;
    }
     if (new_x<0 || new_x>=m || new_y<0 || new_y>=n) {
        cout<<"OUT!"<<endl;
    }
    else if (teren[new_x][new_y]==']') {
        cout<<"GOAL!"<<endl;
    }

    else {
        teren[new_x][new_y]='o';
    }
}


