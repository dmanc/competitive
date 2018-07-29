#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    int n;
    cin >> n;
    vi packets(n);
    for(int i = 0; i<n; i++) cin >> packets[i];
    if(n == 1 || (n == 2 && packets[0] == packets[1])) cout << "-1";
    else {
        cout << 1 << "\n";
        int min = 1e9;
        int id = 0;
        for(int i = 0; i<n; i++) {
            if(packets[i] < min) {
                id = i;
                min = packets[i];
            }
        }
        cout << id + 1;
    }
    return 0;
}
