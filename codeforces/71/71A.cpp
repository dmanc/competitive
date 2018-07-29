#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);   
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        string s;
        cin >> s;
        int len = s.size();
        if(len > 10) {
            string word;
            word += s[0];
            word += to_string(len - 2);
            word += s[len - 1];
            cout << word << "\n";
        }
        else {
            cout << s << "\n";
        }
    }
    return 0;
}
