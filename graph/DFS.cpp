#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    cout << node << " ";

    for (int x : adj[node]) {
        if (!visited[x]) {
            dfs(x, adj, visited);
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter start node for DFS: ";
    cin >> start;

    vector<int> visited(n, 0);

    cout << "DFS Traversal: ";
    dfs(start, adj, visited);
}
