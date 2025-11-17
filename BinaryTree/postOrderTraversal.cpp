#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class SimpleQueue {
public:
    TreeNode** arr;
    int head, tail, capacity;

    SimpleQueue(int n) {
        capacity = n + 5;
        arr = new TreeNode*[capacity];
        head = tail = 0;
    }

    ~SimpleQueue() { delete[] arr; }

    void push(TreeNode* x) { arr[tail++] = x; }
    TreeNode* front() { return arr[head]; }
    void pop() { head++; }
    bool empty() { return head == tail; }
};

class SolutionNoSTL {
public:
    TreeNode* buildTree(int vals[], int n) {
        if (n == 0 || vals[0] == -1) return nullptr;

        TreeNode* root = new TreeNode(vals[0]);
        SimpleQueue q(n);
        q.push(root);

        int i = 1;
        while (!q.empty() && i < n) {
            TreeNode* node = q.front(); q.pop();

            if (i < n && vals[i] != -1) {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            i++;

            if (i < n && vals[i] != -1) {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            i++;
        }

        return root;
    }

    void postorder(TreeNode* root, int out[], int& count) {
        count = 0;
        postRec(root, out, count);
    }

private:
    void postRec(TreeNode* node, int out[], int& count) {
        if (!node) return;
        postRec(node->left, out, count);
        postRec(node->right, out, count);
        out[count++] = node->val;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes in level-order: ";
    cin >> n;

    int* vals = new int[n];
    cout << "Enter level-order values (-1 for NULL): ";
    for (int i = 0; i < n; i++) cin >> vals[i];

    SolutionNoSTL sol;
    TreeNode* root = sol.buildTree(vals, n);

    int* out = new int[n];
    int count = 0;
    sol.postorder(root, out, count);

    cout << "Postorder Traversal: ";
    for (int i = 0; i < count; i++) cout << out[i] << " ";
    cout << endl;

    delete[] vals;
    delete[] out;

    return 0;
}
