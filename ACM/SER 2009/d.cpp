#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define mp make_pair
#define forf(i, n) for (int i = 0; i < n; i++)
#define forb(i, n) for (int i = n - 1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main() {
    int n, m, k;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin >> m >> k;
        vi pattern(k);
        forf(i, k) {
            cin >> pattern[i];
        }
        ll total = 0;
        int d = n;
        forf(i, m) {
            total += d;
            d += pattern[i % k];
        }
        cout << total << '\n';
    }
    return 0;
}
