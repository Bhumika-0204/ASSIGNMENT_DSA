#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void insert(Node*& head, int v) {
    Node* n = new Node();
    n->data = v;
    n->next = head;
    head = n;
}

int visited[100], recStack[100];

// -------- DFS for Connected Components --------
void dfs(int node, Node* adj[]) {
    visited[node] = 1;
    cout << node << " ";

    Node* temp = adj[node];
    while (temp != nullptr) {
        if (!visited[temp->data])
            dfs(temp->data, adj);
        temp = temp->next;
    }
}

// -------- Cycle Detection (Undirected) --------
bool dfsCycle(int node, int parent, Node* adj[]) {
    visited[node] = 1;

    Node* temp = adj[node];
    while (temp != nullptr) {
        int nbr = temp->data;

        if (!visited[nbr]) {
            if (dfsCycle(nbr, node, adj))
                return true;
        }
        else if (nbr != parent) {
            return true;
        }

        temp = temp->next;
    }
    return false;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Node* adj[100];
    for (int i = 0; i < n; i++) adj[i] = nullptr;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        insert(adj[u], v);
        insert(adj[v], u); // undirected
    }

    for (int i = 0; i < 100; i++) visited[i] = 0;

    cout << "\nConnected Components:\n";
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            cout << "Component " << components << ": ";
            dfs(i, adj);
            cout << endl;
        }
    }

    cout << "\nTotal Components = " << components << "\n";

    // Cycle detection
    for (int i = 0; i < 100; i++) visited[i] = 0;

    bool cycleFound = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, -1, adj)) {
                cycleFound = true;
                break;
            }
        }
    }

    cout << "\nCycle Present? " << (cycleFound ? "YES" : "NO") << endl;

    return 0;
}
