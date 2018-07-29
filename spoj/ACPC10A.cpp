#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a1, a2, a3;
    while(true) {
        cin >> a1 >> a2 >> a3;
        if(a1 == 0 && a2 == 0 && a3 == 0) break;
        ll diff = a2 - a1;
        ll div = a2 / a1;
        if(a2 + diff == a3) cout << "AP " << a3 + diff << "\n";
        else if(a2 * div == a3) cout << "GP " << a3 * div << "\n";
    }
    return 0;
}
