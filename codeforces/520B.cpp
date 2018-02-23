#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

/** Computes shortest path from S to all nodes **/
int bfs(int n, int m) {

    map<int, int> distance;
    distance[n] = 0;

    map<int, bool> visited;
    visited[n] = false;

    queue<int> q;
    q.push(n);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(visited[node])
            continue;
        visited[node] = true;
        if(node*2 <= 2*m) {
            q.push(node*2);
            distance[node*2];
            if(distance[node*2] == 0)
                distance[node*2] = 10000000;
            distance[node*2] = min(distance[node*2], distance[node] + 1);
        }
        if(node - 1 > 0) {
            q.push(node-1);
            distance[node - 1];
            if(distance[node - 1] == 0)
                distance[node - 1] = 10000000;
            distance[node-1] = min(distance[node-1], distance[node] + 1);
        }
    }

    return distance[m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if(n > m)
        cout << (n-m);
    else {
        int dist = bfs(n, m);
        cout << dist << "\n";
    }
    return 0;
}
