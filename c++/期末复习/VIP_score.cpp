#include <iostream>
#include <string>

using namespace std;

class Member {
 protected:
  int id;
  string name;
  int score;

 public:
  Member() : id(0), name("a"), score(0) {}
  Member(int i, string n, int s) : id(i), name(n), score(s) {}
  virtual void Add(int m) { score += m; }
  virtual int Exchange(int n1) {
    int n2 = n1 / 100;
    score -= n2 * 100;
    return n2;
  }
  virtual void print() {
    cout << "普通会员" << id << "--" << name << "--" << score << endl;
  }
};

class VIP : public Member {
 private:
  int add_rate;
  int exc_rate;

 public:
  VIP(int i, string n, int s, int a, int e)
      : Member(i, n, s), add_rate(a), exc_rate(e) {}
  void Add(int m) { score += m * add_rate; }
  int Exchange(int n1) {
    int n2 = n1 / exc_rate;
    score -= n2 * exc_rate;
    return n2;
  }
  void print() {
    cout << "贵宾会员" << id << "--" << name << "--" << score << endl;
  }
};

int main() {
  Member* pm;

  int i, s, m, n1;
  string n;
  cin >> i >> n >> s >> m >> n1;
  Member mm(i, n, s);

  pm = &mm;
  pm->Add(m);
  int x = pm->Exchange(n1);
  pm->print();

  int r1, r2;
  cin >> i >> n >> s >> r1 >> r2 >> m >> n1;
  VIP vv(i, n, s, r1, r2);
  pm = &vv;
  pm->Add(m);
  x = pm->Exchange(n1);
  pm->print();

  return 0;
}