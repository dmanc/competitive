#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string ans;
    locale loc;
    for(int i = 0; i<s.size(); i++) {
        char c = tolower(s[i], loc);
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y') {
            ans += '.';
            ans += c;
        }
    }
    cout << ans << "\n";
    return 0;
}
