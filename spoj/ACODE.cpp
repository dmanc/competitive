#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    while(true) {
        string s; cin >> s;
        if(s == "0") break;
        vl dp(s.size() + 1);
        dp[0] = dp[1] = 1;
        rep(i, 2, s.size() + 1) {
            char c1 = s[i - 2] - '0';
            char c2 = s[i - 1] - '0';
            if(c1==1 || (c1 == 2 && c2 <= 6)) dp[i] += dp[i-2];
            if(c2 != 0) dp[i] += dp[i-1];
        }
        cout << dp[s.size()] << "\n";
    }
    return 0;
}
