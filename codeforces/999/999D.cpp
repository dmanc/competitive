#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vi a(n);
    for(ll i = 0; i<n; i++) cin >> a[i];
    vvi c(m);
    ll k = n/m;
    for(ll i = 0; i<n; i++) {
        ll mod = a[i] % m;
        c[mod].push_back(i);
    }
   
    stack<ll> free;
    for(ll it = 0; it < 2; it++) {
        for(ll i = 0; i<m; i++) {
            ll len = c[i].size();
            while(len > k) {
                free.push(c[i].back());
                c[i].pop_back();
                len--;
            }
            while(len < k && !free.empty()) {
                ll num = free.top();
                free.pop();
                c[i].push_back(num);
                len++;
            }
        }
    }

    vi ans(n);
    ll count = 0;
    for(ll i = 0; i<m; i++) {
        for(ll j = 0; j<c[i].size(); j++) {
            ll inc = (((i - a[c[i][j]]) % m) + m) % m;
            ans[c[i][j]] = a[c[i][j]] + inc;
            count += inc;
            
        }
    }
 
    cout << count << "\n";
    for(ll i = 0; i<n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
