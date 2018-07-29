#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, B;
    cin >> n >> B;
    vi a(n);
    for(int i = 0; i<n; i++) cin >> a[i];
    int odd = 0;
    int even = 0;
    vi cuts;
    for(int i = 0; i<n-1; i++) {
        if(a[i] % 2 == 0) even++;
        else odd++;
        if(even == odd) {
            cuts.push_back(abs(a[i+1] - a[i]));
        }
    }
    //for(int i = 0; i<cuts.size(); i++) cout << cuts[i] << " ";
    //cout << "\n";
    sort(cuts.begin(), cuts.end());
    int val = 0;
    int ans = 0;
    for(int i = 0; i<cuts.size(); i++) {
        val += cuts[i];
        ans++;
        if(val > B) {
            val -= cuts[i];
            ans--;
            break;
        }
    }
    cout << ans;
    return 0;
}
