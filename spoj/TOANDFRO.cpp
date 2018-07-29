#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int col;
    while(true) {
        cin >> col;
        if(col == 0) break;
        string s;
        cin >> s;
        int row = s.size() / col;
        char arr[row][col];
        for(int i = 0; i<row; i++) {
            string temp;
            for(int j = 0; j<col; j++)
                temp += s[i*col + j];
            if(i % 2 == 1) reverse(temp.begin(), temp.end());
            for(int j = 0; j<col; j++) arr[i][j] = temp[j];
        }

        string ans;
        for(int i = 0; i<col; i++) {
            for(int j = 0; j<row; j++) {
                ans += arr[j][i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
