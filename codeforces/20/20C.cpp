#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

void dijkstra(vvii graph, int u, int v){

    bool found = false;
    priority_queue<ii, vii, greater<ii> > Q;
    int graphSize = graph.size();
    vl dist(graphSize, 2 << 63 - 1);
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
    for(auto i : prev) {
        cout << i << " ";
    }
    cout << "\n";
    if(found) {
        stack<int> path;
        int temp = v;
        while(temp != -1){
            path.push(temp);
            temp = prev[temp];
        }
        while(!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
        cout << "\n";

    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vvii graph(n+1);
    for(int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }

    dijkstra(graph, 1, n);
    return 0;
}
