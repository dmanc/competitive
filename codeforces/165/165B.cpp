#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int low = 0;
    int high = n+1;
    while(low + 1 < high) {
        int mid = low + (high - low)/2;
        int sum = mid;
        int i = 1;
        //cout << mid << "\n";
        while(true) {
            int val = int(mid/pow(k, i));
            sum += val;
            if(val == 0) break;
            i++;
        }

        if(sum < n)
            low = mid;
        else
            high = mid;
    }
    cout << high << "\n";
    return 0;
}
