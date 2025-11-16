#include <iostream>
using namespace std;

class LinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* head;

public:
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

    void display() {
        cout << "Linked List: ";
        if (!head) {
            cout << "Empty\n";
            return;
        }
        Node* curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;   // store next
            curr->next = prev;   // reverse
            prev = curr;         // move prev
            curr = next;         // move curr
        }

        head = prev; // update head
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

    cout << "\nBefore reversal:\n";
    list.display();

    list.reverse();

    cout << "\nAfter reversal:\n";
    list.display();

    return 0;
}
