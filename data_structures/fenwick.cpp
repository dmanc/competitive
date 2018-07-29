#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FenwickTree {
    vector<ll> bit;
    FenwickTree(int n) : bit(n) {}

    // bit[idx] += dif
    void update(int idx, ll dif) {
        for(; idx < sz(bit); idx |= (idx + 1)) bit[idx] += dif;
    }
    // Query in the range [0, idx)
    ll query(int idx) {
        ll ans = 0;
        for(; idx > 0; idx &= idx - 1) ans += bit[idx - 1];
        return ans;
    }
    // Query in the range [l, r)
    ll query(int l, int r) {
        return query(r) - query(l);
    }
};

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    FenwickTree tree(5);
    tree.update(0, 1);
    tree.update(1, 2);
    tree.update(2, 3);
    tree.update(3, 4);
    tree.update(4, 5);
    cout << tree.query(4, 5) << "\n";
    cout << tree.query(3) << "\n";
    return 0;
}
