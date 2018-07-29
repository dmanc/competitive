#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i<n; i++) cin >> a[i];
    int start = 0;
    int end = a.size() - 1;
    int count = 0;
    while(true) {
        int oldStart = start;
        int oldEnd = end;
        if(a[start] <= k) {
            start++;
            count++;
        }
        else if(a[end] <= k){ 
            end--;
            count++;
        }

        if(oldStart == start && oldEnd == end) break;
        if(start > end || end < start) break;
    }
    cout << count;

    return 0;
}
