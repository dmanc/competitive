#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double N;
    while(true) {
        cin >> N;
        if(N == 0) break;
        cout << int((N*(N+1.0/2.0)*(N+1))/3.0) << "\n";
    }
    return 0;
}
