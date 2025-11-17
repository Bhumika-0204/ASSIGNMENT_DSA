#include <iostream>
#include <vector>
using namespace std;

class QueueSTL {
public:
    int front, rear, size;
    vector<int> arr;

    QueueSTL(int n) {
        front = 0;
        rear = -1;
        size = n;
        arr.resize(n);
    }

    bool isFull() {
        return rear - front + 1 == size;
    }

    bool isEmpty() {
        return rear < front;
    }

    void enqueue(int x) {
        if (!isFull()) {
            rear++;
            arr[rear] = x;
        } else {
            cout << "Queue is Full, cannot enqueue.\n";
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            front++;
        } else {
            cout << "Queue is Empty, cannot dequeue.\n";
        }
    }

    int getFront() {
        if (!isEmpty()) return arr[front];
        return -1;
    }

    int getRear() {
        if (!isEmpty()) return arr[rear];
        return -1;
    }
};

int main() {
    int n, q;

    cout << "Enter size of Queue (n): ";
    cin >> n;

    cout << "Enter number of queries (q): ";
    cin >> q;

    QueueSTL q1(n);

    cout << "\nCommands:\n";
    cout << "1 x : enqueue(x)\n";
    cout << "2   : dequeue()\n";
    cout << "3   : getFront()\n";
    cout << "4   : getRear()\n";
    cout << "5   : isEmpty()\n";
    cout << "6   : isFull()\n\n";

    while (q--) {
        int type;
        cout << "Enter query type: ";
        cin >> type;

        if (type == 1) {
            int x;
            cout << "Enter value to enqueue: ";
            cin >> x;
            q1.enqueue(x);
        }
        else if (type == 2) {
            cout << "Performing dequeue...\n";
            q1.dequeue();
        }
        else if (type == 3) {
            cout << "Front element: " << q1.getFront() << endl;
        }
        else if (type == 4) {
            cout << "Rear element: " << q1.getRear() << endl;
        }
        else if (type == 5) {
            cout << (q1.isEmpty() ? "Queue is Empty" : "Queue is NOT Empty") << endl;
        }
        else if (type == 6) {
            cout << (q1.isFull() ? "Queue is Full" : "Queue is NOT Full") << endl;
        }
        else {
            cout << "Invalid Query Type!" << endl;
        }
    }

    return 0;
}
