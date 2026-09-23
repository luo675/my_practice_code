#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next = NULL;
  int pos;
};

void print(Node* head) {
  Node* p = head->next;

  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

bool swap(int pos1, int pos2, Node* head) {
  Node *p1 = NULL, *p2 = NULL;
  Node* p = head->next;

  while (p != NULL) {
    if (p->pos == pos1) {
      p1 = p;
      p = p->next;
    }

    if (p->pos == pos2) {
      p2 = p;
      p = p->next;
    }

    p = p->next;
  }
  if (p1 != NULL && p2 != NULL) {  // 开始交换
    int temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;

    return true;
  }

  return false;
}

int main() {
  int n;
  cin >> n;

  Node* head = new Node;
  Node *p1, *p2;
  p2 = head;

  for (int i = 1; i <= n; i++) {
    p1 = new Node;
    cin >> p1->data;
    p1->pos = i;
    p2->next = p1;
    p2 = p1;
  }

  print(head);
  int pos1, pos2;
  cin >> pos1 >> pos2;

  if (swap(pos1, pos2, head)) {
    print(head);
  } else {
    cout << "error" << endl;
  }

  cin >> pos1 >> pos2;

  if (swap(pos1, pos2, head)) {
    print(head);
  } else {
    cout << "error" << endl;
  }

  Node* p = head;
  while (p != NULL) {
    Node* temp = p;
    p = p->next;
    delete temp;
  }

  return 0;
}