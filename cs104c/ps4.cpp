#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ll N, X, K;
        cin >> N >> X >> K;
        int low = 0;
        int high = N;
        while(low + 1 < high) {
            ll mid = low + ((high - low)/2);
            ll handshakes = mid*(mid-1)/2;
            ll room = K*(mid/X);
            if(handshakes + room <= N) {
                low = mid;
            }
            else{
                high = mid;
            }
        }
        cout << low << "\n";
    }
    return 0;
}
