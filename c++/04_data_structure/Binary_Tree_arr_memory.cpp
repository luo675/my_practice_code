#include <iostream>
#include <string>
#include <vector>

using namespace std;

void preOrder(vector<int>& tree, int index, vector<int>& result) {
  if (index >= tree.size() || tree[index] == 0) {
    return;
  }

  result.push_back(tree[index]);

  preOrder(tree, 2 * index + 1, result);
  preOrder(tree, 2 * index + 2, result);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> tree(n);

    for (int i = 0; i < n; i++) {
      cin >> tree[i];
    }

    vector<int> result;
    preOrder(tree, 0, result);

    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }

    cout << endl;
  }
  return 0;
}