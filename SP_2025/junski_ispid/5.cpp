#include<iostream>
#include <iomanip>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    char teren[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            teren[i][j] = '-';
        }
    }
    int igrac_x, igrac_y;
    cin >> igrac_x >> igrac_y;
    teren[igrac_x][igrac_y] = 'i';

    int topka_x, topka_y;
    cin >> topka_x >> topka_y;
    teren[topka_x][topka_y] = 'o';


    int x1_gol, y1_gol, x2_gol, y2_gol;
    cin >> x1_gol >> y1_gol >> x2_gol >> y2_gol;
    for (int i = x1_gol; i <= x2_gol; i++) {
        for (int j = y1_gol; j <= y2_gol; j++) {
            teren[i][j] = ']';
        }
        cout << endl;
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << teren[i][j] << ' ';
        }
        cout << endl;
    }


    teren[topka_x][topka_y] = '-';
    int dx, dy;
    cin >> dx >> dy;
    int new_topka_x = topka_x + dx;
    int new_topka_y = topka_y + dy;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << teren[i][j] << ' ';
            }
            cout << endl;
        }

    if (new_topka_x<0 || new_topka_x>m || new_topka_y<0 || new_topka_y>n) {
        cout<<"OUT"<<endl;
    }
    else if (teren[new_topka_x][new_topka_y]==']'){
        cout<<"GOALL!"<<endl;
    }
    else{
        topka_x=new_topka_x;
        topka_y=new_topka_y;
        teren[topka_x][topka_y]=='o';
    }
}
