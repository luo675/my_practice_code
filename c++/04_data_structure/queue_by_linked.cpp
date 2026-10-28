#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {}
};

struct LinkedQueue {
  Node* front;
  Node* rear;

  LinkedQueue() {
    front = new Node(0);
    rear = front;
  }

  LinkedQueue(const LinkedQueue&) = delete;
  LinkedQueue& operator=(const LinkedQueue&) = delete;

  bool empty() const { return front == rear; }

  void push(int value) {
    Node* node = new Node(value);

    rear->next = node;
    rear = node;
  }

  bool pop(int& val) {
    if (empty()) {
      return false;
    }

    Node* node = front->next;
    val = node->data;

    front->next = node->next;

    if (rear == node) {
      rear = front;
    }

    delete node;
    return true;
  }

  ~LinkedQueue() {
    while (front != nullptr) {
      Node* next = front->next;
      delete front;
      front = next;
    }
  }
};

int main() { return 0; }