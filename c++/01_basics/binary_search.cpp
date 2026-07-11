#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr;
  int num;

  while (cin >> num) {
    arr.push_back(num);
    if (num == -1) break;
  }
  cin.clear();

  int goal;
  cin >> goal;

  auto beg = arr.begin(), end = arr.end();
  auto mid = beg + (end - beg) / 2;
  int times = 0;

  while (mid != end && *mid != goal) {
    ++times;
    if (goal < *mid) {
      end = mid;
    } else {
      beg = mid + 1;
    }
    mid = beg + (end - beg) / 2;
  }

  if (mid != end && *mid == goal) {
    cout << times + 1 << endl;
  } else {
    cout << "no!" << endl;
  }

  return 0;
}