#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> arr;
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(int x) {
        arr.push_back(x);
        topIndex++;
        cout << x << " pushed to stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        cout << arr[topIndex] << " popped from stack.\n";
        arr.pop_back();
        topIndex--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = topIndex; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << "Top element: " << s.top() << endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
