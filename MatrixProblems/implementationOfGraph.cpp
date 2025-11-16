#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int **adj = new int*[n+1];
    int *size = new int[n+1];

    for (int i = 1; i <= n; i++) {
        adj[i] = new int[n];  // worst-case each node connected to all
        size[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j < size[i]; j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
