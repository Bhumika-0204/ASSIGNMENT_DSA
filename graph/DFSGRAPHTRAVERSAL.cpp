#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& ans) {
        vis[node] = 1;
        ans.push_back(node);

        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour, adj, vis, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> ans;

        int start = 0;
        dfs(start, adj, vis, ans);

        return ans;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;   
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> res = obj.dfsOfGraph(V, adj);

    for (int x : res)
        cout << x << " ";

    return 0;
}
