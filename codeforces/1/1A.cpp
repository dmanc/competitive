#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n, m, a;
    cin >> n >> m >> a;
    cout << (ll) ceil(n/a) * (ll) ceil(m/a);
    return 0;
}
