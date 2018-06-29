#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        vi men(N);
        for(int i = 0; i<N; i++) cin >> men[i];
        sort(men.begin(), men.end());
        vi women(N);
        for(int i = 0; i<N; i++) cin >> women[i];
        sort(women.begin(), women.end());
        int ans = 0;
        for(int i = 0; i<N; i++) ans += men[i] * women[i];
        cout << ans << "\n";
    }
    return 0;
}
