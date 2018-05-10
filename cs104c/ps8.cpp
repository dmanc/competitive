#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long long mod = 1e9 + 7;

ll power(ll k, ll d) {
    ll pow = 1;
    while(d) {
        if(d % 2 == 1) {
            pow = (pow % mod) * (k % mod);
            d--;
        }
        k = (k % mod)*(k % mod);
        d = d / 2;
    }
    return pow % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ll n, k, d;
        cin >> n >> k >> d;
        cout << (n%mod) * (power(k % mod, d) % mod) % mod << "\n";
    }
    return 0;
}
