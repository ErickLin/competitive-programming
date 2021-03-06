#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#define mp make_pair
#define forf(i, n) for (int i = 0; i < n; i++)
#define forb(i, n) for (int i = n - 1; i >= 0; i--)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
typedef pair<int, int> ii;
typedef pair<double, double> pdd;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef unordered_set<string> uss;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, string> umss;
typedef vector<si> vsi;

class FiveRooksDiv2 {
  public:
    int findMax(vs board) {
      int max_count = 0;
      forf(i, 8) {
        int count = 0;
        forf(j, 8) {
          if (board[i][j] == 'R') {
            count++;
          }
        }
        max_count = max(count, max_count);
      }
      forf(j, 8) {
        int count = 0;
        forf(i, 8) {
          if (board[i][j] == 'R') {
            count++;
          }
        }
        max_count = max(count, max_count);
      }
      return max_count;
    }
};

int main() {
  FiveRooksDiv2 a;
  cout << a.findMax({ "RRRRRRRR", "RRRRRRRR", "RRRRRRRR", "RRRRRRRR", "RRRRRRRR", "RRRRRRRR", "RRRRRRRR", "RRRRRRRR" }) << '\n';
}
