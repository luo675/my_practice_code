#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    for (auto& s : str) {
      if (s >= 'A' && s <= 'Z')
        s = (s - 'A' + 4) % 26 + 'A';

      else if (s >= 'a' && s <= 'z')
        s = (s - 'a' + 4) % 26 + 'a';
    }
    cout << str << endl;
  }
}
