#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll N; cin >> N;
        ll sum = 0;
        rep(i, 0, N) {
            ll num; cin >> num;
            sum = (sum + num) % N;
        }
        if(sum) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
