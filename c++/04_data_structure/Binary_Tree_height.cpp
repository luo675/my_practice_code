#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
  char data;
  TreeNode* left = NULL;
  TreeNode* right = NULL;

  TreeNode(char c) { data = c; }
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

int getHeight(string& s, int& pos) {
  if (pos >= s.size()) {
    return 0;
  }

  char c = s[pos++];

  if (c == '0') {
    return 0;
  }

  int leftHeight = getHeight(s, pos);
  int rightHeight = getHeight(s, pos);

  return max(leftHeight, rightHeight) + 1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int pos = 0;
    int hei = getHeight(s, pos);

    cout << hei << endl;
  }

  return 0;
}