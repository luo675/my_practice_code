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

TreeNode* createTree(string& s, int& pos) {
  if (pos >= s.size()) return NULL;

  char c = s[pos++];

  if (c == '0') return NULL;

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

void CountLeaf(TreeNode* root, int& count) {
  if (root == NULL) return;

  if (root->left == NULL && root->right == NULL) {
    count++;
    return;
  }

  CountLeaf(root->left, count);
  CountLeaf(root->right, count);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int pos = 0;

    int count = 0;

    TreeNode* root = createTree(s, pos);
    CountLeaf(root, count);
    deleteTree(root);
    cout << count << endl;
  }

  return 0;
}