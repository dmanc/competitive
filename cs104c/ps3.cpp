#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef tuple<int,int,int> iii;
typedef vector<iii> viii;


void bellman_ford(viii edges, int n, int start, int end, int K) {
    vi dist(n, 2e8);
    vi store(n, -1);
    dist[start] = 0;

    for(int i = 1; i<=n-1; i++) {
        for(auto e : edges) {
            int a,b,w;
            tie(a,b,w) = e;
            dist[b] = min(dist[b], dist[a] + w);
        }
    }
    for(auto e : edges) {
        int a,b,w;
        tie(a,b,w) = e;
        if(dist[a] != 2e8 && dist[a] + w < dist[b]) {
            cout << "infinity\n";
            return;
        }
    }
    if(dist[end] == 2e8) cout << "-1\n";
    else cout << K-dist[end] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int N, M, K;
        cin >> N >> M >> K;
        //vvii graph(N+1);
        viii edges;
        for(int i = 0; i<M; i++) {
            int U, V, C;
            cin >> U >> V >> C;
            edges.emplace_back(U,V,-C);
        }
        bellman_ford(edges, N+1, 1, N, K);
    }
    return 0;
}
