#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> q;

  q.push(10);
  q.push(20);
  q.push(30);

  cout << q.size() << endl;

  while (!q.empty()) {
    int val = q.front();
    q.pop();

    cout << val << " ";
  }

  cout << endl;

  return 0;
}