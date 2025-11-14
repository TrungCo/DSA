#include <bits/stdc++.h>


using namespace std;

struct graphList {
    int n,m;
    vector<vector<int>> g;
    graphList(int _n, int _m) {
        n = _n;
        m = _m;
        g.resize(n + 1);
        for(int i=0;i<m;i++) {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    void print() const {
        for (int i = 1; i <= n; i++) {
            cout << i << ": ";
            for (int v : g[i]) cout << v << " ";
            cout << "\n";
        }
    }

    void dfs(int n, vector<bool> &visited) {
        cout << n << " ";
        visited[n] = true;
        for (int i : g[n]) {
            if (!visited[i]) {
                dfs(i, visited);
            }
        }
    }
    void bfs(int n) {
        vector<bool> visited;
        visited.assign(n, false);
        queue<int> q;
        q.push(n);
        visited[n] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v : g[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

};


int main() {
    vector<bool> visited;
    visited.assign(6, false);
    graphList a(6,6);

    a.bfs(1);
    return 0;
}
