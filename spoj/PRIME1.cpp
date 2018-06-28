#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(ll n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(ll i = 5; i*i<=n; i+=6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        ll m, n;
        cin >> m >> n;
        for(ll i=m; i<=n; i++) {
            if(isPrime(i)) cout << i << "\n";
        }
        if(T != 0) cout << "\n";
    }
    return 0;
}
