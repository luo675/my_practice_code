#include <iostream>

using namespace std;

struct Spoint {
  int x;
  int y;
};

struct SRect {
  Spoint p1;
  Spoint p2;
};

bool isoverlap(const SRect& rect1, const SRect& rect2);

int max_num(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int min_num(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    SRect rect[2];
    cin >> rect[0].p1.x >> rect[0].p1.y >> rect[0].p2.x >> rect[0].p2.y;

    cin >> rect[1].p1.x >> rect[1].p1.y >> rect[1].p2.x >> rect[1].p2.y;

    if (isoverlap(rect[0], rect[1])) {
      cout << "overlapped" << endl;
    } else
      cout << "not overlapped" << endl;
  }

  return 0;
}
// false为不重叠，true为重叠
bool isoverlap(const SRect& rect1, const SRect& rect2) {
  int top_1 = max_num(rect1.p1.y, rect1.p2.y);
  int low_1 = min_num(rect1.p1.y, rect1.p2.y);
  int left_1 = min_num(rect1.p1.x, rect1.p2.x);
  int right_1 = max_num(rect1.p1.x, rect1.p2.x);
  int top_2 = max_num(rect2.p1.y, rect2.p2.y);
  int low_2 = min_num(rect2.p1.y, rect2.p2.y);
  int left_2 = min_num(rect2.p1.x, rect2.p2.x);
  int right_2 = max_num(rect2.p1.x, rect2.p2.x);

  if (right_1 < left_2 || left_1 > right_2 || top_1 < low_2 || low_1 > top_2)
    return false;

  return true;
}