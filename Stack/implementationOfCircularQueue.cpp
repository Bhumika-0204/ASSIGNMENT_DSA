#include <iostream>
using namespace std;

class MyCircularQueueNoSTL {
public:
    int arr[10000];
    int front, rear, size, count;

    MyCircularQueueNoSTL(int k) {
        size = k;
        front = 0;
        rear = -1;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == size; }
};

int main() {
    int n, q;
    cout << "Enter size of circular queue: ";
    cin >> n;

    cout << "Enter number of queries: ";
    cin >> q;

    MyCircularQueueNoSTL q1(n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x; cin >> x;
            cout << (q1.enQueue(x) ? "true" : "false") << endl;
        }
        else if (type == 2) cout << (q1.deQueue() ? "true" : "false") << endl;
        else if (type == 3) cout << q1.Front() << endl;
        else if (type == 4) cout << q1.Rear() << endl;
        else if (type == 5) cout << (q1.isEmpty() ? "true" : "false") << endl;
        else if (type == 6) cout << (q1.isFull() ? "true" : "false") << endl;
    }

    return 0;
}
