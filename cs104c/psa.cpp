#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 100100;

ll arr[N];
ll n, m;

ll tree[4 * N];

// 0 = root
// children of i = 2 * i + 1, 2 * i + 2

ll build(int i, int l, int r) {
    if (l == r) {
        // base case
        tree[i] = arr[l];
    } else {
        tree[i] = __gcd(build(2 * i + 1, l, (l + r) / 2),
                        build(2 * i + 2, (l + r) / 2 + 1, r));
    }

    return tree[i];
}

void build() {
    build(0, 1, n);
}

ll query(int i, int l, int r, int a, int b) {
    if (l >= a && r <= b) return tree[i];
    if (r < a || b < l) return 0;

    return __gcd(query(2 * i + 1, l, (l + r) / 2, a, b), query(2 * i + 2, (l + r) / 2 + 1, r, a, b));
}

ll query(int a, int b) {
    return query(0, 1, n, a, b);
}

ll update(int i, int l, int r, int j, int v) {
    if (j < l || j > r) return tree[i];
    if (l == r) {
        tree[i] = v;
    } else {
        tree[i] = __gcd(update(2 * i + 1, l, (l + r) / 2, j, v),
                        update(2 * i + 2, (l + r) / 2 + 1, r, j, v));
    }

    return tree[i];
}

void update(int j, int v) {
    update(0, 1, n, j, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 1; i<=n; i++) cin >> arr[i];
        build();
        for(int i = 0; i<m; i++) {

            ll type, a, b;
            cin >> type >> a >> b;
            //cout << type << "\n";
            if(type == 1) {
                // Change the ith element of A to x (1 indexed)
                update(a, b);
            }
            else {
                // Take GCD of a range
                cout << query(a, b) << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
