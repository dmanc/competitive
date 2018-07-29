#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll k; cin >> k;
        if(k == 1) cout << 192 << "\n";
        else cout << 192 + (k-1)*250 << "\n";
    }
    return 0;
}
