#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int *dp = new int[n+1];
    dp[0] = 0;
    int temp1, temp2, temp3;
    for(int i = 1; i<n+1; i++) {
        temp1 = i - a >= 0 ? dp[i - a] : -1e8;
        temp2 = i - b >= 0 ? dp[i - b] : -1e8;
        temp3 = i - c >= 0 ? dp[i - c] : -1e8;
        dp[i] = max(1 + temp1, 1 + temp2);
        dp[i] = max(dp[i], 1 + temp3);
    }
    cout << dp[n] << "\n";
    return 0;
}
