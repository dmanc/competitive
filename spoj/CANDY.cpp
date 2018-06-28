#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    while(true) {
        cin >> N;
        if(N == -1) break;
        vi arr(N);
        for(int i = 0; i<N; i++) cin >> arr[i];
        ll sum = 0;
        for(auto num : arr) sum += num;
        ll val = sum / N;
        if(val * N == sum) {
            ll ans = 0;
            for(auto num : arr) {
                if(val < num) ans += num - val;
            }
            cout << ans << "\n";
        }
        else cout << -1 << "\n";
    }
    return 0;
}
