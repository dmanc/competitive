#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5; // limit for array size
int n; // array size
int t[2 * N];

void build() { // build the tree
    for(int i = n - 1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) { // set value at position p
    for(t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p^1];
}

int query(int l, int r) { // sum on interval [l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> t[i + n];
    build();
    modify(0, 1);
    modify(2, 100);
    cout << query(2) << "\n";
    return 0;
}
