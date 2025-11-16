#include <iostream>
using namespace std;

class LinkedList {
    public:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* head;


    LinkedList() {
        head = nullptr;
    }

    void insertTail(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
            return;
        }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }

    void print() {
        cout << "List: ";
        Node* curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    Node* search(int val) {
        Node* curr = head;
        while (curr) {
            if (curr->val == val) return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    void deleteNode(Node* node) {
        if (!node || !node->next) {
            cout << "Cannot delete last node with this method.\n";
            return;
        }
        node->val = node->next->val;
        Node* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

int main() {
    LinkedList list;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insertTail(val);
    }

    cout << "\nBefore deletion:\n";
    list.print();

    int del;
    cout << "Enter node value to delete (not last node): ";
    cin >> del;

    LinkedList::Node* node = list.search(del);
    if (node)
        list.deleteNode(node);
    else
        cout << "Node not found!\n";

    cout << "\nAfter deletion:\n";
    list.print();

    return 0;
}
