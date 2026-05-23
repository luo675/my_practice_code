#include <iostream>

using namespace std;

struct Node {
  int id;
  Node* next;
  Node(int val) : id(val), next(nullptr) {}
};

void solve() {
  int n, k, m;

  while (cin >> n >> k >> m) {
    if (n <= 0) continue;

    Node* head = new Node(1);
    Node* tail = head;
    for (int i = 2; i <= n; ++i) {
      tail->next = new Node(i);
      tail = tail->next;
    }
    tail->next = head;

    Node* curr = head;
    Node* prev = tail;
    for (int i = 1; i < k; ++i) {
      prev = curr;
      curr = curr->next;
    }

    bool first = true;
    while (n > 0) {
      for (int i = 1; i < m; ++i) {
        prev = curr;
        curr = curr->next;
      }

      if (!first) cout << " ";
      cout << curr->id;
      first = false;

      prev->next = curr->next;
      Node* temp = curr;
      curr = curr->next;
      delete temp;

      n--;
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}