#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class SolutionNoSTL {
public:
    TreeNode* nodes[10001];
    bool isChild[10001];

    SolutionNoSTL() {
        for (int i = 0; i < 10001; i++) {
            nodes[i] = NULL;
            isChild[i] = false;
        }
    }

    TreeNode* getNode(int x) {
        if (!nodes[x]) nodes[x] = new TreeNode(x);
        return nodes[x];
    }

    TreeNode* createBinaryTree(int desc[][3], int n) {
        for (int i = 0; i < n; i++) {
            int parent = desc[i][0];
            int child = desc[i][1];
            int isLeft = desc[i][2];

            TreeNode* p = getNode(parent);
            TreeNode* c = getNode(child);

            if (isLeft == 1) p->left = c;
            else p->right = c;

            isChild[child] = true;
        }

        // root = not a child
        int rootVal = -1;
        for (int i = 0; i < n; i++) {
            int p = desc[i][0];
            if (!isChild[p]) {
                rootVal = p;
                break;
            }
        }
        return nodes[rootVal];
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int n;
    cout << "Enter number of descriptions: ";
    cin >> n;

    int desc[10000][3];
    cout << "Enter descriptions (parent child isLeft):\n";
    for (int i = 0; i < n; i++) {
        cin >> desc[i][0] >> desc[i][1] >> desc[i][2];
    }

    SolutionNoSTL obj;
    TreeNode* root = obj.createBinaryTree(desc, n);

    cout << "Preorder Traversal: ";
    printTree(root);
}
