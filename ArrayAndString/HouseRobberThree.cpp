#include <iostream>
using namespace std;

class treeNode {
public:
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

int maxSum(treeNode* root, bool inc) {
    if (root == NULL) return 0;

    if (inc == true) {
        return root->data + maxSum(root->left, false) + maxSum(root->right, false);
    } else {
        int x = max(maxSum(root->left, true),maxSum(root->left, false));
        int y = max( maxSum(root->right, true),maxSum(root->right, false));
        return x+y;
    }
}

int maxValue(treeNode* root) {
    int ans = max(maxSum(root, true), maxSum(root, false));
    return ans;
}

int main() {

    treeNode* root = new treeNode(3);
    root->left = new treeNode(4);
    root->right = new treeNode(5);
    root->left->left = new treeNode(1);
    root->left->right = new treeNode(3);
    root->right->right = new treeNode(7);

    cout << "Maximum money that can be robbed: " << maxValue(root) << endl;
    return 0;
}
