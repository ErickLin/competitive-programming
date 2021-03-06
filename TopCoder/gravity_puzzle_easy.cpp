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

class GravityPuzzleEasy {
  public:
    vs solve(vs board) {
      int n = board.size(), m = board[0].size();
      vs ret(board.size());
      forf(i, n) {
        forf(j, m) {
          ret[i].push_back('.');
        }
      }
      forf(j, m) {
        int freq = 0;
        forf(i, n) {
          if (board[i][j] == '#') {
            freq++;
          }
        }
        forb(i, n) {
          if (freq > 0) {
            ret[i][j] = '#';
            freq--;
          }
        }
      }
      return ret;
    }
};

int main() {
  GravityPuzzleEasy a;
  vs ans = a.solve({"#", ".", "."});
  forf(i, ans.size()) {
    cout << ans[i] << ',';
  }
  cout << '\n';
}
