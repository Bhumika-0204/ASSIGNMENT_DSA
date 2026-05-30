#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pair<int,int>>> adj(n);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> vis(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 0}); // {weight, node}
    int mstCost = 0;

    while (!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if (vis[node]) continue;
        vis[node] = 1;
        mstCost += wt;

        for (auto &nbr : adj[node]) {
            int next = nbr.first;
            int w = nbr.second;
            if (!vis[next]) pq.push({w, next});
        }
    }

    cout << mstCost;
}
