#include <bits/stdc++.h>

const int MAX_N = 100100;

using namespace std;
typedef long long ll;

ll n, m, k;
ll arr[MAX_N];
ll q[MAX_N];
ll op[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    
    ll operations[m+1][3];
    for(int i = 1; i<=n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i<=m; i++) {
        ll l, r, d;
        cin >> l >> r >> d;
        operations[i][0] = l;
        operations[i][1] = r;
        operations[i][2] = d;
    }
 
    for(int i = 0; i<k; i++) {
        ll x, y;
        cin >> x >> y;
        q[x] += 1;
        q[y+1] -= 1;
    }

    for(int i = 1; i<=m; i++) {
        q[i] += q[i-1];
    }

    for(int i = 1; i<m+1; i++) {
        op[operations[i][0]] += q[i]*operations[i][2];
        op[operations[i][1] + 1] -= q[i]*operations[i][2];
    }

    for(int i = 1; i<=n; i++) {
        op[i] += op[i-1];
    }

    for(int i = 1; i<=n; i++) {
        arr[i] += op[i];
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
