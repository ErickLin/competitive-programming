#include <iostream>
using namespace std;

int main() {
    for (int a = 1; a <= 1000; a++) {
        for (int b = a + 1; b <= 1000; b++) {
            int c = 1000 - a - b;
            if (c != a && c != b && a * a + b * b == c * c) {
                cout << a << ' ' << b << ' ' << c << '\n';
                cout << a * b * c << '\n';
            }
        }
    }
}

