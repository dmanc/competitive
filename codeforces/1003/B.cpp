#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, x;
    cin >> a >> b >> x;
    string ans;
    int temp = x/2;
    if(x % 2 == 0) {
        if(a > b) {
            while(temp > 0) {
                ans += "01";
                temp--;
            }
            while(b - x/2 > 0) {
                ans += '1';
                b--;
            }
            while(a - x/2 > 0) {
                ans += '0';
                a--;
            }
        }
        else {
            while(temp > 0) {
                ans += "10";
                temp--;
            }
            while(a - x/2 > 0) {
                ans += '0';
                a--;
            }
            while(b - x/2 > 0) {
                ans += '1';
                b--;
            }
        }
    }
    else {
        if(a > b) {
            while(temp > 0) {
                ans += "01";
                temp--;
            }
            while(a - x/2 > 0) {
                ans += '0';
                a--;
            }
            while(b - x/2 > 0) {
                ans += '1';
                b--;
            }
        }
        else {
            while(temp > 0) {
                ans += "10";
                temp--;
            }
            while(b - x/2 > 0) {
                ans += '1';
                b--;
            }
            while(a - x/2 > 0) {
                ans += '0';
                a--;
            }
        }
    }
    cout << ans; 
    return 0;
}
