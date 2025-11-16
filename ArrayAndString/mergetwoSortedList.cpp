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

    void insertAtTail(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
            return;
        }
        Node* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = node;
    }

    void display() {
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

    static Node* mergeTwoLists(Node* l1, Node* l2) {
        Node dummy(0);
        Node* tail = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1 != nullptr)
            tail->next = l1;
        else
            tail->next = l2;

        return dummy.next;
    }
};

int main() {
    LinkedList list1, list2;
    int n1, n2;

    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    cout << "Enter " << n1 << " sorted elements:\n";
    for (int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        list1.insertAtTail(val);
    }

    cout << "\nEnter number of nodes in second sorted list: ";
    cin >> n2;
    cout << "Enter " << n2 << " sorted elements:\n";
    for (int i = 0; i < n2; i++) {
        int val;
        cin >> val;
        list2.insertAtTail(val);
    }

    cout << "\nFirst List: ";
    list1.display();
    cout << "Second List: ";
    list2.display();

    LinkedList::Node* mergedHead = LinkedList::mergeTwoLists(list1.head, list2.head);

    cout << "\nMerged Sorted List: ";
    LinkedList::Node* curr = mergedHead;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "\n";

    return 0;
}
