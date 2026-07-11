#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> strs;

int parseIntArg(const vector<string>& tokens, int& idx);
string parseStrArg(const vector<string>& tokens, int& idx);

int parseIntArg(const vector<string>& tokens, int& idx) {
  if (tokens[idx] == "find") {
    idx++;
    string s = parseStrArg(tokens, idx);
    int N = parseIntArg(tokens, idx);
    size_t pos = strs[N].find(s);
    return (pos == string::npos) ? strs[N].length() : pos;
  } else if (tokens[idx] == "rfind") {
    idx++;
    string s = parseStrArg(tokens, idx);
    int N = parseIntArg(tokens, idx);
    size_t pos = strs[N].rfind(s);
    return (pos == string::npos) ? strs[N].length() : pos;
  } else {
    int val = stoi(tokens[idx]);
    idx++;
    return val;
  }
}

string parseStrArg(const vector<string>& tokens, int& idx) {
  if (tokens[idx] == "copy") {
    idx++;
    int N = parseIntArg(tokens, idx);
    int X = parseIntArg(tokens, idx);
    int L = parseIntArg(tokens, idx);
    return strs[N].substr(X, L);
  } else if (tokens[idx] == "add") {
    idx++;
    string s1 = parseStrArg(tokens, idx);
    string s2 = parseStrArg(tokens, idx);
    bool isNum1 = true, isNum2 = true;
    for (char c : s1)
      if (!isdigit(c)) {
        isNum1 = false;
        break;
      }
    for (char c : s2)
      if (!isdigit(c)) {
        isNum2 = false;
        break;
      }
    if (isNum1 && isNum2 && !s1.empty() && !s2.empty()) {
      int num1 = stoi(s1), num2 = stoi(s2);
      if (num1 >= 0 && num1 <= 99999 && num2 >= 0 && num2 <= 99999)
        return to_string(num1 + num2);
    }
    return s1 + s2;
  } else {
    string s = tokens[idx];
    idx++;
    return s;
  }
}

void processCommand(const string& line) {
  vector<string> tokens;
  istringstream iss(line);
  string token;
  while (iss >> token) tokens.push_back(token);
  if (tokens.empty()) return;

  int idx = 0;
  string cmd = tokens[idx++];
  if (cmd == "insert") {
    string S = parseStrArg(tokens, idx);
    int N = parseIntArg(tokens, idx);
    int X = parseIntArg(tokens, idx);
    strs[N].insert(X, S);
  } else if (cmd == "reset") {
    string S = parseStrArg(tokens, idx);
    int N = parseIntArg(tokens, idx);
    strs[N] = S;
  } else if (cmd == "print") {
    int N = parseIntArg(tokens, idx);
    cout << strs[N] << endl;
  } else if (cmd == "printall") {
    for (int i = 1; i < strs.size(); ++i) cout << strs[i] << endl;
  } else if (cmd == "over") {
    exit(0);
  }
}

int main() {
  int n;
  cin >> n;
  strs.resize(n + 1);
  for (int i = 1; i <= n; ++i) cin >> strs[i];
  cin.ignore();

  string line;
  while (getline(cin, line)) {
    if (line == "over") break;
    processCommand(line);
  }
  return 0;
}