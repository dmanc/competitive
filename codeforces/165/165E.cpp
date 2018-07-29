#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll mod = 1e9+7;

ll** mul(ll** a, ll** b) {
    //long long m[4][4];
    ll** m = new ll*[4];
    for(int i = 0; i<4; i++) m[i] = new ll[4];
    for(int i = 0; i<4; i++) {
        for(int j = 0; j<4; j++) {
            m[i][j] = 0;
            for(int k = 0; k<4; k++)
                m[i][j] += (a[i][k]*b[k][j] % mod) % mod;
        }
    }
    for(int i = 0; i<4; i++) {
        for(int j = 0; j<4; j++)
            m[i][j] = m[i][j] % mod;
    }
    return m;
}

ll** pow(ll** M, int n) {
    //int M[4][4] = {{0,1,1,1}, {1,0,1,1}, {1,1,0,1}, {1,1,1,0}};
    if(n == 0) return 0;
    else if(n == 1) return M;
    else if(n % 2 == 0) {
        return pow(mul(M, M), n/2);
    }
    else {
        return mul(M, pow(mul(M, M), (n-1)/2));
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //int n;
    cin >> n;

    ll** M = new ll*[4];
    for(int i = 0; i<4; i++) {
        M[i] = new ll[4];
    }
    M[0][0] = 0;
    M[0][1] = 1;
    M[0][2] = 1;
    M[0][3] = 1;

    M[1][0] = 1;
    M[1][1] = 0;
    M[1][2] = 1;
    M[1][3] = 1;

    M[2][0] = 1;
    M[2][1] = 1;
    M[2][2] = 0;
    M[2][3] = 1;

    M[3][0] = 1;
    M[3][1] = 1;
    M[3][2] = 1;
    M[3][3] = 0;
    if(n != 0)
        M = pow(M, n);

    //for(int i = 0; i<4; i++) {
    //  for(int j = 0; j<4; j++) {
    //       cout << M[i][j] << " ";
    //  }
    //  cout << "\n";
    //}
    if(n == 0) cout << 1 << "\n";
    else cout << M[0][0] << "\n";

    return 0;
}
