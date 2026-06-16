#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    istringstream iss(line);
    int x;
    bool first = true;

    while (iss >> x) {
      if (!first) cout << " ";
      cout << x + 1;
      first = false;
    }
    cout << " ";
    cout << endl;
  }

  return 0;
}