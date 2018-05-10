#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i<n; i++)
        cin >> a[i];
    vi sorted = a;
    sort(sorted.begin(), sorted.end());
    int size = a.size();
    if(k == 1 || size  == 1)     cout << sorted[0] << "\n";
    else if(size == 2 && k == 2) cout << sorted[size-1] << "\n";
    else if(size >= 2 && k == 2) cout << max(a[0], a[size-1]) << "\n";
    else cout << sorted[size-1] << "\n";
    return 0;
}
