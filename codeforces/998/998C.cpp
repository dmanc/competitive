#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    ll count = 0;
    int flag = false;
    for(ll i = 0; i<s.size(); i++) {
        if(s[i] == '0') {
            if(!flag) count++;
            flag = true;
        }
        if(s[i] == '1') flag = false;
    }
    if(count == 0) cout << 0;
    else cout << (count-1)*min(x, y) + y;
    return 0;
}
