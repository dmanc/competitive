#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string exp;
        cin >> exp;
        stack<int> op;
        string ans;
        for(auto c : exp) {
            if(c == ')') { ans += op.top(); op.pop(); }
            else if(c >= 'a' && c <= 'z') ans += c;
            else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') op.push(c);
        }
        cout << ans << "\n";
    }
    return 0;
}
