#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi bfs(vvi adj, int s) {
    int n = adj.size();

    // Can cause TLE if running BFS multiple times
    vi visited(n+1, 0);
    vi dist(n+1, -1);

    dist[s] = 0;
    visited[s] = true;

    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int a = q.front();
        q.pop();
        for(int b : adj[a]) {
            if(!visited[b]) {
                visited[b] = 1;
                dist[b] = dist[a] + 1;
                q.push(b);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V, E;
    cin >> V >> E;
    cout << "|V| = " << V << 
        ", " << "|E| = " << E << "\n";
    
    vvi adj(V+1);

    for(int i = 0; i<E; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s;
    cin >> s;
    vi dist = bfs(adj, s);
    for(int i = 1; i<=V; i++) cout << dist[i] << " ";
    cout << "\n";
    return 0;
}
