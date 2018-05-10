#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1e9+7;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ll X;
        cin >> X;
        ll** dp = new ll*[4];
        for(int i = 0; i<4; i++) dp[i] = new ll[X+1];
        for(int i = 0; i<4; i++) dp[i][0] = 1;
        int *coins = new int[5];
        coins[0] = 1;
        coins[1] = 5;
        coins[2] = 10;
        coins[3] = 25;

        for(int j = 1; j<X+1; j++) {
            for(int i = 0; i<4; i++) {
                ll sum = 0;
                for(int k = 0; k<=i; k++) {
                    if(j - coins[k] >= 0)
                        sum += dp[i][j-coins[k]] % mod;
                }
                sum = sum % mod;
                if(i - 1 >= 0)
                    dp[i][j] = max(sum, dp[i-1][j]);
                else dp[i][j] = sum;
            }
        }

        cout << dp[3][X] % mod << "\n";

    }
    return 0;
}
