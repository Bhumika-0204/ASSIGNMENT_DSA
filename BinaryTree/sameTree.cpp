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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {
    // ----- First Tree -----
    int n1;
    cout << "Enter number of nodes for Tree 1: ";
    cin >> n1;

    vector<int> vals1(n1);
    cout << "Enter level-order values for Tree 1 (-1 for NULL): ";
    for (int i = 0; i < n1; i++) cin >> vals1[i];

    // ----- Second Tree -----
    int n2;
    cout << "Enter number of nodes for Tree 2: ";
    cin >> n2;

    vector<int> vals2(n2);
    cout << "Enter level-order values for Tree 2 (-1 for NULL): ";
    for (int i = 0; i < n2; i++) cin >> vals2[i];

    SolutionSTL sol;
    TreeNode* t1 = sol.buildTree(vals1);
    TreeNode* t2 = sol.buildTree(vals2);

    if (sol.isSameTree(t1, t2))
        cout << "Trees are SAME.\n";
    else
        cout << "Trees are NOT SAME.\n";

    return 0;
}
