#include <iostream>
#include <queue>
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

void deleteTree(TreeNode* root) {
  if (root == NULL) {
    return;
  }

  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

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

void LevelOrder(TreeNode* root) {
  if (root == NULL) {
    return;
  }

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* p = q.front();
    q.pop();

    cout << p->data;

    if (p->left != NULL) {
      q.push(p->left);
    }

    if (p->right != NULL) {
      q.push(p->right);
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int pos = 0;
    cin >> s;

    TreeNode* root = createTree(s, pos);

    LevelOrder(root);
    cout << endl;

    deleteTree(root);
  }

  return 0;
}