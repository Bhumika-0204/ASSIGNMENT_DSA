#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& vis) {
    if (node == dest) return true;
    vis[node] = 1;

    for (int nbr : adj[node]) {
        if (!vis[nbr]) {
            if (dfs(nbr, dest, adj, vis)) return true;
        }
    }
    return false;
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

    vector<int> vis(n, 0);

    cout << (dfs(src, dest, adj, vis) ? "Path Exists" : "No Path");
}
