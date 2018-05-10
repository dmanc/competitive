#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vll ruth(N);
        vll bleminda(N);
        for(int i = 0; i<N; i++) cin >> ruth[i];
        for(int i = 0; i<N; i++) cin >> bleminda[i];
        sort(bleminda.rbegin(), bleminda.rend());
        sort(ruth.begin(), ruth.end());

        // Iterate through bleminda's rocks
        ll ans = 0;
        ll index1 = 0;
        ll index2 = ruth.size()-1;
        ll curMax = ruth[index2];
        ll curMin = ruth[index1];

        for(int i = 0; i<N; i++) {
            curMax = ruth[index2];
            curMin = ruth[index1];
            if(curMax <= bleminda[i]) {
                ans += curMin;
                index1++;
            }
            else index2--;
        }
        cout << ans << "\n";
    }
    return 0;
}
