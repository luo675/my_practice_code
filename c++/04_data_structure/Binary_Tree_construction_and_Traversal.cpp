#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
  char data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(char c) {
    data = c;
    left = NULL;
    right = NULL;
  }
};

TreeNode* createTree(const string& s, int& pos) {
  if (pos >= s.size()) return NULL;

  char c = s[pos++];
  if (c == '#') {
    return NULL;
  }

  TreeNode* root = new TreeNode(c);

  root->left = createTree(s, pos);
  root->right = createTree(s, pos);

  return root;
}

void preorder(TreeNode* root) {
  if (root == NULL) return;

  cout << root->data;
  preorder(root->left);
  preorder(root->right);
}

void inorder(TreeNode* root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  cout << root->data;
  inorder(root->right);
}

void postorder(TreeNode* root) {
  if (root == NULL) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  cout << root->data;
}

void deleteTree(TreeNode* root) {
  if (root == NULL) {
    return;
  }

  deleteTree(root->left);
  deleteTree(root->right);

  delete root;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int pos = 0;
    TreeNode* root = createTree(s, pos);

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    deleteTree(root);
  }

  cout << endl;

  return 0;
}