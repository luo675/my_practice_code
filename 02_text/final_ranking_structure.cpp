#include <iostream>

using namespace std;

struct team {
  long ID;
  int M;
};

void sort_print(team te[], long n);

int main() {
  long n;
  cin >> n;
  team* te = new team[n];
  for (long i = 0; i < n; ++i) {
    cin >> te[i].ID >> te[i].M;
  }
  sort_print(te, n);
  delete[] te;
  return 0;
}

void sort_print(team te[], long n) {
  team temp;
  for (long i = 0; i < n - 1; ++i) {
    for (long j = 0; j < n - 1 - i; ++j) {
      if (te[j].M < te[j + 1].M) {
        temp = te[j];
        te[j] = te[j + 1];
        te[j + 1] = temp;
      }
    }
  }

  for (long i = 0; i < n; ++i) {
    cout << te[i].ID << " " << te[i].M << endl;
  }
}