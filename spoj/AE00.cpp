#include <bits/stdc++.h>

using namespace std;

int factors(int n) {
    int ans = 1;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) ans++;
    return ans;
}

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 1; i<=N; i++) {
        ans += factors(i);
    }
    cout << ans;
    return 0;
}
