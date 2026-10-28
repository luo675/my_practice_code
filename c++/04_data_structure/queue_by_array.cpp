#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct CircularQueue {
  static constexpr int M = 5;

  int data[M]{};
  int front = 0;
  int rear = 0;

  bool empty() const { return front == rear; }

  bool full() const { return (rear + 1) % M == front; }

  bool push(int value) {
    if (full()) {
      return false;
    }

    data[rear] = value;
    rear = (rear + 1) % M;
    return true;
  }

  bool pop(int& value) {
    if (empty()) {
      return false;
    }

    value = data[front];
    front = (front + 1) % M;
    return true;
  }

  bool getFront(int& value) const {
    if (empty()) {
      return false;
    }

    value = data[front];
    return true;
  }

  int size() const { return (rear - front + M) % M; }
};

int main() {
  CircularQueue q;

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);

  cout << q.push(50) << endl;

  int value;

  if (q.pop(value)) {
    cout << value << endl;
  }

  q.push(50);

  while (q.pop(value)) {
    cout << value << " ";
  }

  cout << endl;

  return 0;
}
