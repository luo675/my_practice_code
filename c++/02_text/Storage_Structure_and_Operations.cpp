#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

void print(Node* head) {
  Node* p = head->next;

  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }

  cout << endl;
}

void insert(Node* head) {
  int pos, data;
  cin >> pos >> data;

  Node* p = head;

  for (int i = 1; i < pos; ++i) {
    if (p->next == NULL) {
      cout << "error" << endl;
      return;
    }
    p = p->next;
  }

  if (pos < 1) {
    cout << "error" << endl;
    return;
  }

  Node* newNode = new Node;
  newNode->data = data;

  newNode->next = p->next;
  p->next = newNode;

  print(head);
}

void removeNode(Node* head) {
  int pos;
  cin >> pos;

  if (pos < 1) {
    cout << "error" << endl;
    return;
  }

  Node* p = head;

  for (int i = 1; i < pos; ++i) {
    if (p->next == NULL) {
      cout << "error" << endl;
      return;
    }
    p = p->next;
  }

  if (p->next == NULL) {
    cout << "error" << endl;
    return;
  }

  Node* q = p->next;

  p->next = q->next;

  delete q;

  print(head);
}

void find(Node* head) {
  int pos;
  cin >> pos;

  if (pos < 1) {
    cout << "error" << endl;
    return;
  }

  Node* p = head->next;

  for (int i = 1; i < pos; ++i) {
    if (p == NULL) {
      cout << "error" << endl;
      return;
    }

    p = p->next;
  }

  if (p == NULL) {
    cout << "error" << endl;
    return;
  }

  cout << p->data << endl;
}

int main() {
  int n;
  cin >> n;

  Node* head = new Node;
  head->next = NULL;

  Node* tail = head;

  for (int i = 0; i < n; ++i) {
    int data;
    cin >> data;

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    tail->next = newNode;
    tail = newNode;
  }

  print(head);

  insert(head);
  insert(head);

  removeNode(head);
  removeNode(head);

  find(head);
  find(head);

  Node* p = head;

  while (p != NULL) {
    Node* q = p;
    p = p->next;
    delete q;
  }

  return 0;
}