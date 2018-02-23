#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    ll low = 1;
    ll high = n*m+1;
    while(low + 1 < high) {
        ll mid = low + (high - low)/2;
        ll sum = 0;
        for(int i = 1; i<=n; i++) {
            sum += min((mid-1)/i, m);
        }
        //cout << "\n";
        //cout << mid << " " << sum << "\n\n";
        if(sum < k)
            low = mid;
        else
            high = mid;
    }
    cout << low << "\n";
}
