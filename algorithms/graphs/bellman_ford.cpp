#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef vector<iii> viii;

vi bellman_ford(viii edges, int start) {
    int n = edges.size();
    vi dist(n+1, INF);
    dist[start] = 0;
    for(int i = 1; i<=n-1; i++) {
        for(auto e : edges) {
            int u, v, w;
            tie(u, v, w) = e;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    cout << "vertices: " << n << "\nedges: " << m << "\n";

    int s;
    cin >> s;
    cout << "starting node: " << s << "\n";

    viii edges; 
    // Construct the edge list
    for(int i = 0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    
    for(int i = 0; i<m; i++) {
        int a, b, c;
        tie(a, b, c) = edges[i];
        cout << "edge: " << a << " - " << b
             << " with weight " << c << "\n";
    }

    vi dist(n+1);
    dist = bellman_ford(edges, s);

    for(int i = 1; i<=n; i++) {
        if(dist[i] == INF) cout << "inf ";
        else cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
