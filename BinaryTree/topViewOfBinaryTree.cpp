#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class SolutionNoSTL {
public:
    TreeNode* buildTree(int arr[], int i, int n) {
        if (i >= n || arr[i] == -1) return NULL;

        TreeNode* root = new TreeNode(arr[i]);
        root->left  = buildTree(arr, 2*i + 1, n);
        root->right = buildTree(arr, 2*i + 2, n);
        return root;
    }

    void topView(TreeNode* root) {
        if (!root) return;

        // Manual queue
        TreeNode* nodeQ[200000];
        int hdQ[200000];
        int front = 0, back = 0;

        // Manual map using array HD range [-10000,10000]
        int offset = 10000;
        int mp[20001];
        bool seen[20001];

        for (int i = 0; i < 20001; i++)
            seen[i] = false;

        nodeQ[back] = root;
        hdQ[back] = 0;
        back++;

        int minHD = 0, maxHD = 0;

        while (front < back) {
            TreeNode* node = nodeQ[front];
            int hd = hdQ[front];
            front++;

            int idx = hd + offset;
            if (!seen[idx]) {
                seen[idx] = true;
                mp[idx] = node->val;
            }

            if (node->left) {
                nodeQ[back] = node->left;
                hdQ[back] = hd - 1;
                back++;
                if (hd - 1 < minHD) minHD = hd - 1;
            }
            if (node->right) {
                nodeQ[back] = node->right;
                hdQ[back] = hd + 1;
                back++;
                if (hd + 1 > maxHD) maxHD = hd + 1;
            }
        }

        cout << "Top View: ";
        for (int hd = minHD; hd <= maxHD; hd++) {
            int idx = hd + offset;
            if (seen[idx])
                cout << mp[idx] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter nodes (-1 for NULL): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    SolutionNoSTL sol;
    TreeNode* root = sol.buildTree(arr, 0, n);

    sol.topView(root);

    delete[] arr;
    return 0;
}
