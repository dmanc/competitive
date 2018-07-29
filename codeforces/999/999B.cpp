#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi divisors(int n) {
    vi d;
    for(int i = 1; i<=n; i++)
        if(n % i == 0)
            d.push_back(i);
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi d = divisors(n);
    string s;
    cin >> s;
    for(int i = 0; i<d.size(); i++) {
        reverse(s.begin(), s.begin()+d[i]);
    }
    cout << s;

    return 0;
}
