#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class SolutionSTL {
public:
    TreeNode* buildTree(const vector<int>& arr) {
        if (arr.empty() || arr[0] == -1) return nullptr;

        TreeNode* root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < arr.size()) {
            TreeNode* node = q.front();
            q.pop();

            // left child
            if (i < arr.size() && arr[i] != -1) {
                node->left = new TreeNode(arr[i]);
                q.push(node->left);
            }
            i++;

            // right child
            if (i < arr.size() && arr[i] != -1) {
                node->right = new TreeNode(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }

    int diameter;

    int height(TreeNode* root) {
        if (!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        height(root);
        return diameter;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter tree nodes in level-order (-1 for NULL): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    SolutionSTL sol;

    TreeNode* root = sol.buildTree(arr);

    cout << "Diameter = " << sol.diameterOfBinaryTree(root) << endl;
    return 0;
}
