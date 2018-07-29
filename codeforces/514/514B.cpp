#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<double, int> slopes;

    double n, x_0, y_0;
    cin >> n >> x_0 >> y_0;
    for(int i = 0; i<n; i++) {
        double x, y;
        cin >> x >> y;
        double slope = 100000000.0;
        if(x - x_0 != 0)
            slope = (y - y_0) / (x - x_0);
        slopes[slope]++;
    }

    cout << slopes.size() << "\n";

    return 0;
}
