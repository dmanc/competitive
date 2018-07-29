#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi a(100);
vi b(100);
vi visited(100, 0);

int num;

void dfs(int u) {
    visited[u] = 1;
    for(int i = 0; i<=num; i++) {
        if(visited[i]) continue;
        if(a[u] > a[i] && a[u] < b[i]) dfs(i);
        if(b[u] > a[i] && b[u] < b[i]) dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vii intervals;
    vvi graph(100);
    while(n--) {
        int type, x, y;
        cin >> type >> x >> y;
        // Add to the graph
        if(type == 1) {
            num++;
            a[num] = x;
            b[num] = y;
        }
        // Search for a path
        else {
            fill(visited.begin(), visited.end(),0);
            dfs(x);
            if(visited[y]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
