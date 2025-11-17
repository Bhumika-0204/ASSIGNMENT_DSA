#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
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

            // left
            if (i < arr.size() && arr[i] != -1) {
                node->left = new TreeNode(arr[i]);
                q.push(node->left);
            }
            i++;

            // right
            if (i < arr.size() && arr[i] != -1) {
                node->right = new TreeNode(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }

    bool hasPathSum(TreeNode* root, int target) {
        if (!root) return false;

        // if leaf
        if (!root->left && !root->right)
            return root->val == target;

        return hasPathSum(root->left, target - root->val) ||
               hasPathSum(root->right, target - root->val);
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter tree nodes in level-order (-1 for NULL): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    SolutionSTL sol;
    TreeNode* root = sol.buildTree(arr);

    if (sol.hasPathSum(root, target))
        cout << "Path Exists\n";
    else
        cout << "Path Does NOT Exist\n";

    return 0;
}
