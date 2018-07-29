#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<bool> nums(N+1);
    fill(nums.begin(), nums.end(), true);
    nums[0] = false;
    nums[1] = true;
    for(int i = 2; i<sqrt(N) + 1; i++) {
        if(nums[i]) {
            for(int j = i*i; j<=N; j+=i) {
                nums[j] = false;
            }
        }
    }

    for(int i = 2; i<N; i++) {
        if(!nums[i]) {
            if(!nums[N - i]) {
                cout << i << " " << N-i;
                break;
            }
        }
    }
    cout << "\n";



    return 0;
}
