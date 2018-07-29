#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--) {
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = stoi(a);
        int m = stoi(b);
        string temp = to_string(n+m);
        reverse(temp.begin(), temp.end());
        int ans = stoi(temp);
        cout << ans << "\n";
    }
    return 0;
}
