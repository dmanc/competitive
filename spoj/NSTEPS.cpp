#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    while(N--) {
        ll x, y;
        cin >> x >> y;
        if(x == y && x % 2 == 0) cout << x*2 << "\n";
        else if(x == y && x % 2 == 1) cout << x*2 - 1 << "\n";
        else if(x == y + 2) {
            if(x % 2 == 0) cout << x*2 - 2 << "\n";
            else cout << x*2 - 3 << "\n";
        }
        else cout << "No Number\n";
    }
    return 0;
}
