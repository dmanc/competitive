#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        ll p = a % 10;
        ll mod =  b % 4;
        if(b == 0) cout << 1 << "\n";
        else if(p == 0 || p == 1 || p == 5 || p == 6) cout << p << "\n";
        else if(mod == 1) cout << a % 10 << "\n";
        else if(mod == 2) cout << (a*a) % 10 << "\n";
        else if(mod == 3) cout << (a*a*a) % 10 << "\n";
        else if(mod == 0) cout << (a*a*a*a) % 10 << "\n";
    }
    return 0;
}
