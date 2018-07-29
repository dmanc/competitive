#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

vi dijkstra(vvpii adj, int start) {
    int n = adj.size();
    vi visited(n+1, 0);
    vi dist(n+1, INF);
    dist[start] = 0;
    
    priority_queue<pii> q;
    q.push({0, start});
    while(!q.empty()) {
        int a = q.top().second;
        q.pop();

        if(visited[a]) continue;
        visited[a] = true;
        
        for(auto u : adj[a]) {
            int b = u.first;
            int w = u.second;
            if(dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
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
        int n, m;
        cin >> n >> m;
        vvpii adj(n+1);
        for(int i = 0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].emplace_back(b, c);
        }

        int a, b;
        cin >> a >> b;
        vi dist = dijkstra(adj, a);

        int ans = dist[b];
        if(ans == INF) cout << "NO\n";
        else cout << dist[b] << "\n";
    }
    return 0;
}
