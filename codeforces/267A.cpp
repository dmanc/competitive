#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        int iterations = 0;
        while(a > 1 && b > 1) {
            if(a > b) {
                iterations += a/b;
                a -= (a/b) * b;
            }
            else {
                iterations += b/a;
                b -= (b/a)*a;
            }
        }
        if(a == 1) iterations += b;
        else if(b == 1) iterations += a;
        cout << iterations << "\n";
    }
    return 0;
}
