#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

ll dp[1000001];

ll calc(ll n) {
    if(n <= 1000000) return dp[n];
    return max(calc(n/2) + calc(n/3) + calc(n/4), n);
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    ll n;
    while(cin >> n) {
        rep(i, 0, 5) if(i <= n) dp[i] = i;
        rep(i, 5, 1000001) dp[i] = max(dp[i/2] + dp[i/3] + dp[i/4], (ll) i);
        cout << calc(n) << "\n";
    }
    return 0;
}
