#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Player {
 protected:
  string name;
  double height;
  double weight;

 public:
  Player() {}
  Player(string na, double h, double w) : name(na), weight(w), height(h) {}
  virtual void print() {
    cout << "球员姓名:" << name << " 身高:" << height << " 体重:" << weight
         << endl;
  }
};

class MVP : public Player {
 protected:
  int year;
  double score;
  double rebounds;
  double assist;

 public:
  MVP(int y, double s, double r, double a)
      : year(y), score(s), rebounds(r), assist(a) {}
  bool judge() {
    if ((score > 25) && (rebounds > 6) && (assist > 6))
      return true;
    else
      return false;
  }
  void print() {
    cout << "MVP年份:" << year << " 得分:" << fixed << setprecision(1) << score
         << " 篮板:" << fixed << setprecision(1) << rebounds
         << " 助攻:" << fixed << setprecision(1) << assist << endl;
  }
};

class DPOY : public Player {
 protected:
  int year;
  double rebounds;
  double steal;
  double caps;

 public:
  DPOY(int y, double r, double s, double c)
      : year(y), rebounds(r), steal(s), caps(c) {}
  bool judge() {
    if ((rebounds > 12) && (steal > 1.5) && (caps > 1.5)) {
      return true;
    } else
      return false;
  }
  void print() {
    cout << "DPOY年份:" << year << " 盖帽:" << fixed << setprecision(1) << caps
         << " 篮板:" << fixed << setprecision(1) << rebounds
         << " 抢断:" << fixed << setprecision(1) << steal << endl;
  }
};

int main() {
  string na;
  double h, w;
  cin >> na >> h >> w;
  Player p1(na, h, w);
  p1.print();
  double score[12], rebounds[12], assist[12], caps[12], steal[12];
  for (int i = 0; i < 12; i++) {
    cin >> score[i] >> rebounds[i] >> assist[i] >> caps[i] >> steal[i];
  }
  for (int year = 2010, i = 0; year <= 2021; year++, i++) {
    // MVP
    MVP p2(year, score[i], rebounds[i], assist[i]);
    if (p2.judge()) p2.print();
  }
  for (int year = 2010, i = 0; year <= 2021; year++, i++) {
    // DPOY
    DPOY p3(year, rebounds[i], steal[i], caps[i]);
    if (p3.judge()) p3.print();
  }

  return 0;
}