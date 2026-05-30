#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int dest, vector<vector<int>>& adj,
         vector<int>& vis, vector<int>& path) {

    if (node == dest) {
        for (int p : path) cout << p << " ";
        cout << dest << "\n";
        return;
    }

    vis[node] = 1;

    for (int nbr : adj[node]) {
        if (!vis[nbr]) {
            path.push_back(node);
            dfs(nbr, dest, adj, vis, path);
            path.pop_back();
        }
    }

    vis[node] = 0;
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

    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;

    vector<int> vis(n, 0), path;
    dfs(src, dest, adj, vis, path);
}
