/*i  j     i  j     i  j
a[0][0]  a[0][1]  a[0][2]
a[1][0]  a[1][1]  a[1][2]
a[2][0]  a[2][1]  a[2][2]
*/

#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int j=0;j<n;j++){
        cout<<a[m/2][j]<<" ";  // za sredna redica
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        cout<<a[i][n/2]<<" ";  // za kolona redica
    }

}