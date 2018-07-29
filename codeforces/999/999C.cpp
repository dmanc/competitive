#include <bits/stdc++.h>
using namespace std;

typedef set<int> si;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    si id[26];
    for(int i = 0; i<s.size(); i++) {
        id[int(s[i]) - 97].insert(i);
    }
    
    for(int i = 0; i<k; i++) {
        for(int j = 0; j<26; j++) {
            if(id[j].size() > 0) {
                id[j].erase(id[j].begin());
                break;
            }
        }
    }
    string temp;
    temp.resize(n, ' ');
    for(int i = 0; i<26; i++) {
        for(int a : id[i])
            temp[a] = char(i+97);
    }
    string ans;
    for(int i = 0; i<temp.size(); i++) if(temp[i] != ' ') ans += temp[i];
    cout << ans;

    
    return 0;
}
