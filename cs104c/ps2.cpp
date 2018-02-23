#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int dijkstra(vvii graph, int u, int v){

    bool found = false;
    priority_queue<ii, vii, greater<ii> > Q;
    int graphSize = graph.size();
    vl dist(graphSize, 2e18);
    vi prev(graphSize, -1);
    vi visited(graphSize, 0);

    Q.push({u,0});
    dist[u] = 0;

    while (!Q.empty()){

        int u = Q.top().first;
        Q.pop();

        if(u == v){
            found = true;
            break;
        }

        for(auto neighbor: graph[u]) {
            if (dist[u] + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = dist[u] + neighbor.second;
                prev[neighbor.first] = u;
                //Q.push({neighbor.first, dist[neighbor.first]});
            }
            if(!visited[neighbor.first]) {
                visited[neighbor.first] = 1;
                Q.push({neighbor.first, dist[neighbor.first]});
            }



        }
    }
    return round(dist[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;
        vvii graph(N+1);
        for(int i = 0; i < M; ++i) {
            int U, V;
            double S, L;
            cin >> U >> V >> S >> L;
            graph[U].push_back({V,L/S});
        }
        int ans = dijkstra(graph, 1, N);
        cout << ans << "\n";
    }
    return 0;
}
