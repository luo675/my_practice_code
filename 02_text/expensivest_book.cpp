#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CBook {
 private:
  string name;
  string author;
  double money;
  string publish;

 public:
  CBook() {}
  void SetBook(string n, string a, string p, double m) {
    name = n;
    author = a;
    publish = p;
    money = m;
  }

  friend void find(CBook* book, int n, int& max1index, int& max2index);

  friend istream& operator>>(istream& is, CBook& book);

  friend ostream& operator<<(ostream& os, const CBook& book);
};

string trim(const string& s) {
  size_t start = s.find_first_not_of(" \t\n\r\f\v");
  if (start == string::npos) return "";
  size_t end = s.find_last_not_of(" \t\n\r\f\v");
  return s.substr(start, end - start + 1);
}

vector<string> splitByComma(const string& line) {
  vector<string> result;
  stringstream ss(line);
  string item;
  while (getline(ss, item, ',')) {
    result.push_back(trim(item));
  }

  return result;
}

istream& operator>>(istream& is, CBook& book) {
  string line;
  if (getline(is, line)) {
    vector<string> fields = splitByComma(line);
    if (fields.size() >= 4) {
      book.name = fields[0];
      book.author = fields[1];
      book.money = stod(fields[2]);
      book.publish = fields[3];
    } else {
      is.setstate(ios::failbit);
    }
  }
  return is;
}

void find(CBook* book, int n, int& max1index, int& max2index) {
  max1index = 0;
  max2index = -1;
  for (int i = 1; i < n; ++i) {
    if (book[i].money > book[max1index].money) {
      max2index = max1index;
      max1index = i;
    } else if (book[i].money == book[max1index].money) {
      if (max2index == -1 || book[max2index].money < book[max1index].money) {
        max2index = i;
      }
    } else {
      if (max2index == -1 || book[i].money > book[max2index].money) {
        max2index = i;
      }
    }
  }
  if (max2index == -1) max2index = 0;
}

ostream& operator<<(ostream& os, const CBook& book) {
  os << book.name << endl
     << book.author << endl
     << fixed << setprecision(2) << book.money << endl
     << book.publish << endl;
  return os;
}

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    int n;
    cin >> n;
    cin.ignore();
    CBook* book = new CBook[n];
    for (int i = 0; i < n; ++i) {
      cin >> book[i];
    }
    int m1, m2;
    find(book, n, m1, m2);

    cout << book[m1] << endl << book[m2] << endl;
    delete[] book;
  }

  return 0;
}