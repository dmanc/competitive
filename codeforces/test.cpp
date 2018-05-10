#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 5e4;
ll mod = 1e9 + 7;

int dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int count = 0;
    dp[0] = 1;
    for (int i = 0; i < T; ++i) {
        char type;
        cin >> type;

        if (type == 'f')
            count++;
        else
            for (int j = 1; j <= count; j++) {
                (dp[j] += dp[j - 1]) %= mod;
            }
    }
    cout << dp[count] << endl;
    return 0;
}
