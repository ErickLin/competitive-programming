#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    cout << (a1 + a2 + a3) * (a1 + a2 + a3)
        - a1 * a1 - a3 * a3 - a5 * a5 << '\n';
}
