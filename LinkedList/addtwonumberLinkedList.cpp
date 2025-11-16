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
            cout << curr->val;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << "\n";
    }

    static Node* addTwoNumbers(Node* l1, Node* l2) {
        Node dummy(0);
        Node* tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }
};

int main() {
    LinkedList list1, list2;
    int n1, n2;

    cout << "Enter number of digits in first number: ";
    cin >> n1;
    cout << "Enter digits (in reverse order): ";
    for (int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        list1.insertTail(val);
    }

    cout << "\nEnter number of digits in second number: ";
    cin >> n2;
    cout << "Enter digits (in reverse order): ";
    for (int i = 0; i < n2; i++) {
        int val;
        cin >> val;
        list2.insertTail(val);
    }

    cout << "\nFirst Number List: ";
    list1.display();
    cout << "Second Number List: ";
    list2.display();

    LinkedList::Node* result = LinkedList::addTwoNumbers(list1.head, list2.head);

    cout << "\nSum List (in reverse order): ";
    while (result) {
        cout << result->val;
        if (result->next) cout << " -> ";
        result = result->next;
    }
    cout << "\n";

    return 0;
}
