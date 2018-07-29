#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int code[N];
    for(int i = 0; i<N; i++) {
        char num;
        cin >> num;
        if(num == 's') code[i] = 0;
        else code[i] = 1;
    }

    int* dp = new int[5000];
    for(int i = 0; i<5000; i++) dp[i] = 0;
    dp[0] = 1;
    int indentation = 0;
    //if(code[0] == 1) indentation = 1;
    for(int i = 0; i<N; i++) {
        int val = code[i];
        if(val == 1) indentation++;
        else {
            for(int j = 1; j<=indentation; j++)
                dp[j] = ((dp[j] % mod) + (dp[j-1] % mod)) % mod;
        }
    }
    
    cout << dp[indentation] << "\n";
    return 0;
}
