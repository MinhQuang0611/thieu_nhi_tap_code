#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define nL "\n"

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, k; cin >> n >> k;
    vector<vector<ld>> dp(n + 1, vector<ld>(k + 1));
    dp[0][0] = 1;
    rep(i, 0, n){
        rep(j, 0, k + 1){
            if(j == 0 && i != 0) continue;
            rep(l, 1, k + 1){
                int newmax = max(l, j);
                dp[i + 1][newmax] += dp[i][j] / k;
            }
        }
    }
    ld ans = 0;
    rep(i, 1, k + 1){
        ans += i * dp[n][i];
    }
    ld r1 = ans * 1e6;
    ld r2 = r1 - ll(r1);
    if(fabs(r2 - 0.5) < 1e-5) r2 = ll(r1) % 2  == 0 ? 0 : 1;
    else if(r2 > 0.5) r2 = 1;
    else r2 = 0;
    ld rounded = ll(r1) + r2;
    rounded /= 1e6;
    cout << fixed << setprecision(6) << rounded << nL;
    
    return 0;
}
