#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int q;
    cin >> q;
    while(q--) {
        int m;
        cin >> m;
        cout << upper_bound(arr.begin(), arr.end(), m) - arr.begin() << "\n";
    }



    return 0;
}
