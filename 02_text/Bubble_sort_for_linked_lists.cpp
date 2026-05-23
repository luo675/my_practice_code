#include <iostream>
#include <string>

using namespace std;

struct node {
  string str;
  node* next = nullptr;
};

void printed(node* head);

void sort(node* head);

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    int n;
    if (!(cin >> n)) return 0;
    node *head = nullptr, *p1, *p2 = nullptr;
    // 输入数据
    while (n--) {
      p1 = new node;
      cin >> p1->str;
      if (head == nullptr) {
        head = p1;
        p2 = p1;
      } else {
        p2->next = p1;
        p2 = p1;
      }
    }
    // 降序排序
    sort(head);
    // 输出
    printed(head);
    cout << endl;
  }
}

void printed(node* head) {
  cout << head->str << endl;
  if (head->next != nullptr) printed(head->next);
}

void sort(node* head) {
  bool swap;
  node* p1 = head;
  node* p2 = nullptr;

  do {
    p1 = head;
    swap = false;
    while (p1->next != p2) {
      if (p1->str[0] < p1->next->str[0]) {
        string temp = p1->str;
        p1->str = p1->next->str;
        p1->next->str = temp;
        swap = true;
      }
      p1 = p1->next;
    }
    p2 = p1;

  } while (swap);
}
