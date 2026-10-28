#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
  char data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(char c) {
    data = c;
    left == nullptr;
    right = nullptr;
  }
};

TreeNode* createTree(string& s, int& pos) {
  if (pos >= s.size()) {
    return NULL;
  }

  char c = s[pos++];
  if (c == '0') {
    return NULL;
  }

  TreeNode* root = new TreeNode(c);
  root->left = createTree(s, pos);
  root->right = createTree(s, pos);

  return root;
}

void deleteTree(TreeNode* root) {
  if (root == NULL) {
    return;
  }

  deleteTree(root->left);
  deleteTree(root->right);

  delete root;
}

void findLeaves(TreeNode* root, TreeNode* parent, string& leaves,
                string& parents) {
  if (root == NULL) {
    return;
  }

  if (root->left == NULL && root->right == NULL) {
    leaves += root->data;
    leaves += ' ';

    if (parent != NULL) {
      parents += parent->data;
      parents += ' ';
    }

    return;
  }

  findLeaves(root->left, root, leaves, parents);
  findLeaves(root->right, root, leaves, parents);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int pos = 0;
    TreeNode* root = createTree(s, pos);

    string leaves, parents;

    findLeaves(root, NULL, leaves, parents);

    cout << leaves << endl;
    cout << parents << endl;

    deleteTree(root);
  }

  return 0;
}