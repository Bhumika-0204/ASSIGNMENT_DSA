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

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int rightNode = -1;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                rightNode = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(rightNode);
        }
        return result;
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
    vector<int> ans = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
