#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll trailing(int n) {
    ll count = 0;
    while(n > 0) {
        count += n % 10 == 0 ? 1 : 0;
        if(n%10 != 0) break;
        n /= 10;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll** arr = new ll*[n];
    for(int i = 0; i<n; i++) arr[i] = new ll[n];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> arr[i][j];

    ll** dp = new ll*[n];
    for(int i = 0; i<n; i++) dp[i] = new ll[n];

    dp[0][0] = arr[0][0];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            dp[i][j] = arr[i][j];

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(i == 0 && j > 0) {
                dp[i][j] = dp[i][j-1] * arr[i][j];
            }
            if(j == 0 && i > 0) dp[i][j] = dp[i-1][j] * arr[i][j];
            else if(j > 0 && i > 0) {
                dp[i][j] = trailing(dp[i][j-1]*arr[i][j]) <= trailing(dp[i-1][j]*arr[i][j]) ? dp[i][j-1] * arr[i][j] : dp[i-1][j]*arr[i][j];
                if( trailing(dp[i][j-1]*arr[i][j]) == trailing(dp[i-1][j]*arr[i][j]) ) {
                    dp[i][j] = min( dp[i][j-1] * arr[i][j], dp[i-1][j]*arr[i][j]);
                }
            }
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            dp[i][j] = trailing(dp[i][j]);
        }
    }

    cout << dp[n-1][n-1] << "\n";


    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
     }

    stack<string> st;
    // Compute path
    int i = n-1;
    int j = n-1;
    while(i != 0 || j != 0) {
        int a = 1e9;
        int b = 1e9;
        if(i - 1 >= 0)
            a = dp[i-1][j];
        if(j - 1 >= 0)
            b = dp[i][j-1];

        if(a <= b) {
            st.push("D");
            i--;
        }
        else {
            st.push("R");
            j--;
        }
    }
    //cout << "\n";

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << "\n";

    return 0;
}
