#include <bits/stdc++.h>
using namespace std;

class LinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

    ListNode* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a node at the tail
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if (!head) {
            head = node;
            return;
        }
        ListNode* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = node;
    }

    // Print linked list
    void printList() {
        cout << "Linked List: ";
        if (!head) {
            cout << "Empty\n";
            return;
        }
        ListNode* curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    // Function to count number of nodes
    int countNodes() {
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;
    int n;
    cout << "Enter number of elements in linked list: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.addAtTail(val);
    }

    cout << "\nYour Linked List:\n";
    list.printList();

    int total = list.countNodes();
    cout << "Total number of nodes = " << total << "\n";

    return 0;
}
