/*
*Да се напише функција која прима низа и N со покажувачи ги заменува секој пар соседни елементи

Пример:
[1, 2, 3, 4, 5] → [2, 1, 4, 3, 5]
 *
 *
 *
 **/




#include <iostream>
using namespace std;

void promeni(int a[], int n) {
    for (int i=0;i<n;i++) {
        if (*(a+i+1)==0) {
            *(a+i)=*(a+0);
        }
        else {
            *(a+i)=*(a+i+1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i =0;i < n; i++) {
        cin>>a[i];
    }

    promeni(a, n);

    for (int i=0; i<n;i++) {
        cout<<a[i]<<" ";
    }

    return 0;
}