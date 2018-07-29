#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MOD 1e9 + 7
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, R, M;
        scanf("%d %d %d", &N, &R, &M);
        vvi adj(N+1);
        for(int i = 0; i<R; i++) {
            int U, V;
            scanf("%d %d", &U, &V);
            adj[U].push_back(V);
            adj[V].push_back(U);
        }
        vector<pii> soldiers;
        for(int i = 0; i<M; i++) {
            int K, S;
            scanf("%d %d", &K, &S);
            soldiers.emplace_back(K, S);
        }
        
        vi visited(N+1, 0);
        vi done(N+1, 0);
        int flag = 1;
        for(int k = 0; k<soldiers.size(); k++) {
            // bfs
            int s = soldiers[k].first;
            int str = soldiers[k].second;
            queue<pii> q;
            q.push({s, 0});
            visited[s] = 1;
            while(!q.empty()) {
                int a = q.front().first;
                int depth = q.front().second;
                q.pop();
                if(depth > str) break;
                if(done[a] == 1) {  
                    flag = 0;
                    break;
                }
                for(int b : adj[a]) {
                    if(!visited[b]) {
                        q.push({b, depth + 1});
                        visited[b] = 1;
                    }
                }
                done[a] = 1;
            }
            if(flag == 0) break;
        }
        for(int i = 1; i<=N; i++) {
            if(done[i] == 0) {
                flag = 0;
                break;
            }
        }
        if(flag == 0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
