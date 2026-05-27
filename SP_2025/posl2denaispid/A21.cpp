#include <iostream>
using namespace std;


void pecatiEdinici(int k) {
    if (k == 0) {
        return;
    }
    cout << 1;
    pecatiEdinici(k - 1);
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        pecatiEdinici(i-1);
        cout << i;
        pecatiEdinici(i-1);
        cout << endl;
    }

    return 0;
}
