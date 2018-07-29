#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ll N; cin >> N;
        ll ans = 0;
        for(ll i = 5; i<=N; i*=5) {
            ans += N / i;
        }
        cout << ans << "\n";
    }
    return 0;
}
