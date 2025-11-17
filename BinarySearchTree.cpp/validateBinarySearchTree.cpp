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

            if (i < arr.size() && arr[i] != -1) {
                node->left = new TreeNode(arr[i]);
                q.push(node->left);
            }
            i++;

            if (i < arr.size() && arr[i] != -1) {
                node->right = new TreeNode(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }

    bool isValid(TreeNode* root, long long low, long long high) {
        if (!root) return true;
        if (root->val <= low || root->val >= high) return false;

        return isValid(root->left, low, root->val) &&
               isValid(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter level-order values (-1 for NULL): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    SolutionSTL sol;
    TreeNode* root = sol.buildTree(arr);

    if (sol.isValidBST(root))
        cout << "Valid BST\n";
    else
        cout << "Not a BST\n";

    return 0;
}
