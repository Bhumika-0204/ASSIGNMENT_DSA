#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

    ListNode* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* curr = head;
        for (int i = 0; i < index; i++) curr = curr->next;
        return curr->val;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if (!head) head = node;
        else {
            ListNode* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = node;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        ListNode* curr = head;
        for (int i = 0; i < index - 1; i++) curr = curr->next;
        ListNode* node = new ListNode(val);
        node->next = curr->next;
        curr->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size || !head) return;
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            ListNode* curr = head;
            for (int i = 0; i < index - 1; i++) curr = curr->next;
            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        size--;
    }

    void printList() {
        cout << "Current Linked List: ";
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
};

int main() {
    MyLinkedList list;
    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    cout << "Available operations:\n";
    cout << "1 addAtHead <val>\n";
    cout << "2 addAtTail <val>\n";
    cout << "3 addAtIndex <index> <val>\n";
    cout << "4 deleteAtIndex <index>\n";
    cout << "5 get <index>\n";
    cout << "6 print\n";

    while (q--) {
        int op;
        cout << "\nEnter operation number: ";
        cin >> op;

        if (op == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            list.addAtHead(val);
        } else if (op == 2) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            list.addAtTail(val);
        } else if (op == 3) {
            int index, val;
            cout << "Enter index and value: ";
            cin >> index >> val;
            list.addAtIndex(index, val);
        } else if (op == 4) {
            int index;
            cout << "Enter index: ";
            cin >> index;
            list.deleteAtIndex(index);
        } else if (op == 5) {
            int index;
            cout << "Enter index: ";
            cin >> index;
            cout << "Value at index " << index << " = " << list.get(index) << "\n";
        } else if (op == 6) {
            list.printList();
        } else {
            cout << "Invalid operation!\n";
        }
    }
    return 0;
}
