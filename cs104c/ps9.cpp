#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        ll prevX = 0;
        ll prevY = 0;
        ll cost = 0;
        ll firstX = 0;
        ll firstY = 0;
        for(int i = 0; i<n; i++) {
            ll x, y;

            cin >> x >> y;
            if(i == 0) {
                firstX = x;
                firstY = y;
            }
            cost += (prevX - 0)*(y - 0) - (x - 0)*(prevY - 0);
            prevX = x;
            prevY = y;
        }

        cost += (prevX - 0)*(firstY - 0) - (firstX - 0)*(prevY - 0);

        cout << cost << "\n";
    }
    return 0;
}
