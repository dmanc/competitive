#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

/** Computes shortest path from S to all nodes **/
int bfs(vector<vector<int> > &adj, vector<int> &visited, int S, int P) {

    int numNodes = adj.size();
    vector<int> distance(numNodes);

    for(int i = 0; i<distance.size(); i++)
        distance[i] = 10000000;
    distance[S] = 0;

    queue<int> q;
    q.push(S);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(visited[node])
            continue;
        visited[node] = 1;

        for(int nextNode : adj[node]) {
            q.push(nextNode);
            distance[nextNode] = min(distance[nextNode], distance[node] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i<distance.size(); i++) {
        if(distance[i] <= P)
            ans++;
    }
    return ans;
}

int connected(vector<vector <int> > &adj, int P) {
    int numNodes = adj.size();
    vector<int> visited(numNodes);
    for(int i = 0; i<numNodes; i++)
        visited[i] = 0;
    int count = 0;
    for(int i = 1; i<numNodes; i++) {
        if(!visited[i]) {
            bfs(adj, visited, i, P);
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int N, M, S, P;
        cin >> N >> M >> S >> P;
        vector<vector<int> >adj(N+1);

        while(M--) {
            int U, V;
            cin >> U >> V;
            adj[U].push_back(V);
            adj[V].push_back(U);
        }

        vector<int> visited(N+1);

        int dist = bfs(adj, visited, S, P);
        int connect = connected(adj, P);

        cout << connect << " " << dist << "\n";
    }
    return 0;
}
