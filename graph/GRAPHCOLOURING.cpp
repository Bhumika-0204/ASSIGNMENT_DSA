#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int N, int col) {
    for (int k = 0; k < N; k++) {
        if (graph[node][k] && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, int color[], bool graph[101][101], int N, int M) {
    if (node == N)
        return true;

    for (int col = 1; col <= M; col++) {
        if (isSafe(node, color, graph, N, col)) {
            color[node] = col;

            if (solve(node + 1, color, graph, N, M))
                return true;

            color[node] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    int N, E, M;
    cin >> N >> E >> M;

    bool graph[101][101] = {0};

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = true;
    }

    int color[101] = {0};

    if (solve(0, color, graph, N, M))
        cout << 1;
    else
        cout << 0;

    return 0;
}
