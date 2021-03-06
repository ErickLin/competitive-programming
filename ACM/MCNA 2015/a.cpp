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
    int m;
    map<char, int> wrong;
    map<char, int> time;
    while (cin >> m && m != -1) {
        char prob;
        string s;
        cin >> prob >> s;
        if (s == "wrong") {
            wrong[prob]++;
        } else if (time.find(prob) == time.end()) {
            time[prob] = m;
        }
    }
    int penalty = 0;
    for (auto it = time.begin(); it != time.end(); it++) {
        penalty += wrong[it->first] * 20;
        penalty += it->second;
    }
    cout << time.size() << ' ' << penalty << '\n';
    return 0;
}
