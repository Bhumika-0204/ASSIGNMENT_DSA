#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    Node(int v) { val = v; left = right = NULL; }
};

class BST {
public:
    Node* insertNode(Node* root, int key) {
        if (root == NULL) return new Node(key);

        if (key < root->val)
            root->left = insertNode(root->left, key);
        else if (key > root->val)
            root->right = insertNode(root->right, key);

        return root;
    }

    bool searchNode(Node* root, int key) {
        if (root == NULL) return false;
        if (root->val == key) return true;
        if (key < root->val) return searchNode(root->left, key);
        return searchNode(root->right, key);
    }

    Node* minValueNode(Node* root) {
        while (root->left) root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return NULL;

        if (key < root->val)
            root->left = deleteNode(root->left, key);

        else if (key > root->val)
            root->right = deleteNode(root->right, key);

        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
};

int main() {
    BST tree;
    Node* root = NULL;

    int n;
    cout << "Enter number of elements to insert in BST: ";
    cin >> n;

    cout << "Enter elements (one by one): ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = tree.insertNode(root, x);
    }

    cout << "Inorder Traversal: ";
    tree.inorder(root);
    cout << "\n";

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (tree.searchNode(root, key))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << "Enter value to delete: ";
    cin >> key;
    root = tree.deleteNode(root, key);

    cout << "Inorder After Deletion: ";
    tree.inorder(root);
    cout << "\n";

    return 0;
}
