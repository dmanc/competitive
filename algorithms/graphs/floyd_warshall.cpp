#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi floyd_warshall(vvi adj) {
    int n = adj.size();
    vvi dist(n, vi(n));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(i == j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
        }
    }

    for(int k = 0; k<n; k++) {
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vvi adj(n, vi(n));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                cin >> adj[i][j];
            }
        }
        vvi dist = floyd_warshall(adj);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
