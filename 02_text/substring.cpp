#include <iostream>

using namespace std;

int substr(char str1[], char str2[], int index) {
  int count = 0;
  for (int i = 0;; ++i) {
    if (str1[i] == '\0') {
      count = i;
      break;
    }
  }
  if (index < 0 || count < index)
    return 0;
  else {
    int i = 0;
    for (int j = index; str1[j] != '\0'; ++j, ++i) {
      str2[i] = str1[j];
    }
    str2[i] = '\0';
  }
  cout << str2 << endl;
  return 1;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    char str1[1000], str2[1000];
    int index;
    cin.getline(str1, 1000);
    cin >> index;
    cin.ignore();
    int a = substr(str1, str2, index);
    if (a == 0) cout << "IndexError" << endl;
  }

  return 0;
}