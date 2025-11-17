#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(const vector<int>& vals) {
        if (vals.empty() || vals[0] == -1) return nullptr;

        TreeNode* root = new TreeNode(vals[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < vals.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (i < vals.size() && vals[i] != -1) {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            i++;

            if (i < vals.size() && vals[i] != -1) {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }

    bool isMirror(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;

        return isMirror(a->left, b->right) &&
               isMirror(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};

int main() {
    int n;
    cout << "Enter number of nodes in level-order: ";
    cin >> n;

    vector<int> vals(n);
    cout << "Enter level-order values (-1 for NULL): ";
    for (int i = 0; i < n; i++) cin >> vals[i];

    Solution sol;
    TreeNode* root = sol.buildTree(vals);

    if (sol.isSymmetric(root))
        cout << "Tree is Symmetric.\n";
    else
        cout << "Tree is NOT Symmetric.\n";

    return 0;
}
