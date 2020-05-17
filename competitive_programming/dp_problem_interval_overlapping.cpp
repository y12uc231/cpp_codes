#include "/Users/satyapriyakrishna/Documents/codes/cpp_codes/stdc++.h"
#include <assert.h>

/**
 * Link to problem : https://www.spoj.com/problems/MFISH/
 **/

using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define s(n) cin >> n
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define wt while(true)
#define all(x) x.begin(),x.end()
#define pb push_back
#define ls(x) ((2*(x)) + 1)
#define rs(x) ((ls(x)) + 1)
#define md(a,b) (((a) + (b))/2)
#define INF (1e9 + 7)
 
ll t, u, v, n, k, m, c, d, f, e, l, r, y;
string ss, s1, s2;
vll a, b;
const int N = 100025;
ll DP [N];
ll X [N];
ll S [N];
pll P [N];
int main()      {
        csl;
        cin >> n;
        rep (i, n) {
                cin >> X[i];
                S[i] = (i == 0 ? X[i] : (S[i - 1] + X[i]));
        }
        rep (i, n) {
                DP[i] = 0;
        }
        cin >> m;
        rep (i, m) {
                cin >> P[i].first >> P[i].second;
                P[i].first--;
        }
        sort(P, P + m);
        ll last = 0;
        ll curmax = -132;
        rep (i, m) {
                curmax = -132;
                reps (j, max(last, P[i].first - P[i].second + 1), P[i].first + 1) {
                        if (j + P[i].second - 1 >= n)   break;
                        DP[j + P[i].second - 1] = max(DP[j + P[i].second - 1], (j == 0 ? 0 : DP[j - 1]) + S[j + P[i].second - 1] - (j == 0 ? 0 : S[j - 1]));
                        curmax = max(curmax, DP[j + P[i].second - 1]);
                        DP[j + P[i].second - 1]  = max(DP[j + P[i].second - 1], curmax);
                }
                last = P[i].first + 1;
                reps (j, min(n - 1, P[i].first + P[i].second), (i == m - 1 ? n : P[i + 1].first)) {
                        DP[j] = curmax;
                }
        }
        cout << DP[n - 1] << '\n';
    return 0;
}


