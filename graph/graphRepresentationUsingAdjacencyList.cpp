#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void insert(Node*& head, int v) {
    Node* newNode = new Node();
    newNode->data = v;
    newNode->next = head;
    head = newNode;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Node* adj[100]; // array of linked-list heads
    for (int i = 0; i < n; i++) adj[i] = nullptr;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        insert(adj[u], v);
        insert(adj[v], u); // undirected graph
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        Node* temp = adj[i];
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}
