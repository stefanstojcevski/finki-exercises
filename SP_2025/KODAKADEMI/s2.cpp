#include <iostream>
using namespace std;

bool cikcak(int n ) {
    if (n <10) {
        return true;
    }
    int cifra1 = n % 10;
    int cifra2 = (n / 10) % 10;
    if ((cifra1<5 && cifra2>=5) || (cifra1>=5 && cifra2<5) ) {
        return cikcak(n / 10);
    }
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        bool Ecikcak = true;
        if (n < 10) {
            continue;
        }
        if (cikcak(n)) {
            cout << n << endl;
        }
    }
}
