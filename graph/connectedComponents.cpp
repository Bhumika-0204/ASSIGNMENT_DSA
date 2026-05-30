#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>> adj;
    int n;

    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    void dfs(int node, vector<int> &visited) {
        visited[node] = 1;
        cout << node << " ";

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited);
            }
        }
    }

    // ----------------- Connected Components -----------------
    int connectedComponents() {
        vector<int> visited(n, 0);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                cout << "\nComponent " << components << ": ";
                dfs(i, visited);
            }
        }
        return components;
    }

    // ----------------- Cycle Detection (Undirected) ---------
    bool dfsCycle(int node, int parent, vector<int> &visited) {
        visited[node] = 1;

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                if (dfsCycle(nbr, node, visited))
                    return true;
            }
            else if (nbr != parent) {
                return true; // cycle found
            }
        }
        return false;
    }

    bool hasCycle() {
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfsCycle(i, -1, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    Graph g(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nConnected Components:";
    int cc = g.connectedComponents();

    cout << "\n\nTotal Components = " << cc << "\n";

    cout << "\nCycle Present? " << (g.hasCycle() ? "YES" : "NO") << "\n";
}
