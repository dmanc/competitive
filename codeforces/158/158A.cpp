#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i<n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 0; i<n; i++) if(a[i] >= a[k - 1] && a[i] > 0) ans++;
    cout << ans;
    return 0;
}
