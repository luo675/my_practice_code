#include <iostream>

using namespace std;

struct node {
  int num;
  node* next = nullptr;
};

void printed(node* head);

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    int n;
    if (!(cin >> n)) return 0;
    node *head = nullptr, *p1, *p2 = nullptr;
    while (n--) {
      p1 = new node;
      cin >> p1->num;
      if (head == nullptr) {
        head = p1;
        p2 = p1;
      } else {
        p2->next = p1;
        p2 = p1;
      }
    }
    printed(head);
    cout << endl;
  }

  return 0;
}

void printed(node* head) {
  if (head->next != nullptr) {
    printed(head->next);
  }
  cout << head->num << " ";
}