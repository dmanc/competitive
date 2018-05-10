#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, C;
        cin >> N >> C;
        int value[N+1];
        int weight[N+1];
        for(int i = 0; i<=N; i++) {
            value[i] = 0;
            weight[i] = 0;
        }

        for(int i = 1; i<=N; i++) {
            cin >> value[i];
            cin >> weight[i];
        }

        int dp[N+1][C+1];
        for(int i = 0; i<=N; i++)
            for(int j = 0; j<=C; j++)
                dp[i][j] = 0;

        for(int j = 0; j<=C; j++) dp[0][j] = 0;
        for(int i = 1; i<=N; i++) {
            for(int j = 1; j<=C; j++) {
                int curr_weight = weight[i];
                if(curr_weight > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j - curr_weight] + value[i]);
            }
        }
        cout << dp[N][C] << "\n";
    }

    return 0;
}
