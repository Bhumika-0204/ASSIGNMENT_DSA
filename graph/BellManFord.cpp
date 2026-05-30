#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<tuple<int,int,int>> edges;
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (auto &edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Negative Cycle Found";
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
        cout << "Dist to " << i << " = " << dist[i] << endl;
}
