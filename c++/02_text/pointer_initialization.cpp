#include <iostream>

using namespace std;

int main() {
  int* p;
  int i;
  cin >> i;
  if (i == 0)
    p = NULL;
  else
    p = &i;
  if (p == NULL) {
    cout << "NULL";
  } else
    cout << "Initialized";

  return 0;
}