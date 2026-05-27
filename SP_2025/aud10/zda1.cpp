#include <iostream>
using namespace std;


int sum(int k) {
    if (k == 1)
        return 1;
    return k + sum(k - 1);
}


long long factorial(int k) {
    if (k == 0)
        return 1;
    return k * factorial(k - 1);
}

int main() {
    int n;
    long long result = 0;

    cout << "Vnesi n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        result += factorial(sum(i));
    }

    cout << "Zbirot e: " << result << endl;
    return 0;
}
