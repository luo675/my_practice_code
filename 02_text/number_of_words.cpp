#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string word, text;
  if (!getline(cin, word)) return 0;
  if (!getline(cin, text)) return 0;

  // 全部转小写
  for (char& c : word) c = tolower(c);
  for (char& c : text) c = tolower(c);

  // 在前后加空格，确保“完全匹配”
  word = " " + word + " ";
  text = " " + text + " ";

  int count = 0;
  size_t firstPos = string::npos;
  size_t pos = text.find(word);

  if (pos == string::npos) {
    cout << -1 << endl;
  } else {
    firstPos = pos;  // 记录第一次出现的位置
    while (pos != string::npos) {
      count++;
      pos = text.find(word, pos + 1);  // 从下一个位置继续找
    }
    // 注意：因为我们在 text 前面加了一个空格，所以索引正好抵消了
    cout << count << " " << firstPos << endl;
  }

  return 0;
}