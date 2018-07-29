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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    double max_val = -1;
    rep(i, 0, n) {
        double sum = 0;
        rep(j, i, n) {
            sum += a[j];
            if(j - i >= k - 1) {
                double avg = sum / (j - i + 1);
                max_val = max(avg, max_val);
            }
        }
    }
    cout << max_val;
    return 0;
}
