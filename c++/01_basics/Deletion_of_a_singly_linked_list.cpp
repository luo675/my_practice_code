#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

int Delete(Node*& H, int i, int& currentSize) {
  if (i < 1 || i > currentSize || H == NULL) {
    return 0;
  }
  Node *p = H, *pre = NULL;

  if (i == 1) {
    H = H->next;
    delete p;
  } else {
    for (int k = 1; k < i; k++) {
      pre = p;
      p = p->next;
    }
    pre->next = p->next;
    delete p;
  }

  currentSize--;
  return 1;
}

void PrintList(Node* H, int size) {
  cout << size;
  Node* p = H;
  while (p != NULL) {
    cout << " " << p->data;
    p = p->next;
  }
  cout << endl;
}

int main() {
  int n;
  if (!(cin >> n)) return 0;

  Node *head = NULL, *tail = NULL;
  int currentSize = n;

  for (int i = 0; i < n; i++) {
    Node* newNode = new Node;
    cin >> newNode->data;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  PrintList(head, currentSize);

  int m, pos;
  cin >> m;
  while (m--) {
    cin >> pos;
    if (Delete(head, pos, currentSize)) {
      PrintList(head, currentSize);
    } else {
      cout << "error" << endl;
    }
  }

  return 0;
}