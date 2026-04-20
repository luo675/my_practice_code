#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N;

int charToInt(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  else
    return c - 'A' + 10;
}

bool isPalindromic(const vector<int>& num) {
  int len = num.size();
  for (int i = 0; i < len / 2; ++i) {
    if (num[i] != num[len - 1 - i]) return false;
  }
  return true;
}

void add(vector<int>& num) {
  vector<int> b = num;
  reverse(b.begin(), b.end());

  int len = num.size();
  int carry = 0;

  for (int i = 0; i < len; ++i) {
    int sum = num[i] + b[i] + carry;
    num[i] = sum % N;
    carry = sum / N;
  }

  if (carry > 0) {
    num.push_back(carry);
  }
}

int main() {
  string M_str;
  cin >> N >> M_str;

  vector<int> num;
  for (int i = M_str.length() - 1; i >= 0; i--) {
    num.push_back(charToInt(M_str[i]));
  }

  for (int step = 0; step <= 30; step++) {
    if (isPalindromic(num)) {
      cout << "STEP=" << step << endl;
      return 0;
    }
    add(num);
  }

  cout << "Impossible!" << endl;

  return 0;
}