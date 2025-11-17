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
    TreeNode* buildTree(const vector<int>& vals) {
        if (vals.empty() || vals[0] == -1) return nullptr;

        TreeNode* root = new TreeNode(vals[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < vals.size()) {
            TreeNode* node = q.front(); q.pop();

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

    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};

int main() {
    int n;
    cout << "Enter number of nodes in level-order: ";
    cin >> n;

    vector<int> vals(n);
    cout << "Enter level-order values (-1 for NULL): ";
    for (int i = 0; i < n; i++) cin >> vals[i];

    SolutionSTL sol;
    TreeNode* root = sol.buildTree(vals);

    vector<int> ans;
    sol.inorder(root, ans);

    cout << "Inorder Traversal: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
