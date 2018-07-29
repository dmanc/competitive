#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int d, sumTime;
    cin >> d >> sumTime;
    vi min_t(d);
    vi max_t(d);
    int minSum = 0;
    int maxSum = 0;
    for(int i = 0; i<d; i++) {
        cin >> min_t[i] >> max_t[i];
        minSum += min_t[i];
        maxSum += max_t[i];
    }
    if(minSum <= sumTime && sumTime <= maxSum) {
        cout << "YES\n";
        vi ans(d);
        for(int i = 0; i<d; i++)
            ans[i] = min_t[i];
        int val = minSum;
        for(int i = 0; i<d; i++) {
            int inc = max_t[i] - min_t[i];

            if(val == sumTime) break;

            if(val + inc >= sumTime) {
                for(int j = 0; j<=inc; j++) {
                    if(val + j == sumTime) {
                        ans[i] = min_t[i] + j;
                        break;
                    }
                }
            }
            else
                ans[i] = max_t[i];
            val += inc;
        }

        for(int i = 0; i<d; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

    }
    else {
        cout << "NO\n";
    }
    return 0;
}
