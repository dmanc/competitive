#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MOD 1e9 + 7
#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<long long> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vi a(n); rep(i, 0, n) cin >> a[i];
    vi cnt(31);
    rep(i, 0, n) cnt[__builtin_ctz(a[i])]++;
    while(q--) {
        ll b; cin >> b;
        ll ans = 0;
        for(int i = 30; i>=0 && b>0; i--) {
            ll need = min(b >> i, cnt[i]);
            ans += need;
            b -= (1 << i) * need;
        }
        if(b > 0) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
