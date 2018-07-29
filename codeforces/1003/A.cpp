#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vi coins(101, 0);
    rep(i, 0, n) {
        coins[a[i]]++;
    }
    int max = -1;
    rep(i, 0, 101) {
        if(coins[i] > max) {
            max = coins[i];
        }
    }
    cout << max;
    return 0;
}
