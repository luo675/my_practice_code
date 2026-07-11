#include <iostream>
#include <string>

class CPoint {
 private:
  int x, y;

 public:
  CPoint(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
  int GetX() const { return x; }
  int GetY() const { return y; }

  bool operator==(const CPoint& other) const {
    return x == other.x && y == other.y;
  }
};

class CGame {
 private:
  char** ch;
  int n;
  static int counter;
  int wrong;

  void releaseMemory() {
    if (ch != nullptr) {
      for (int i = 0; i < n; ++i) {
        delete[] ch[i];
      }
      delete[] ch;
      ch = nullptr;
    }
  }

 protected:
  bool isValid(int x, int y) const {
    return x >= 0 && x < n && y >= 0 && y < n;
  }

  char getCharAt(int x, int y) const {
    if (!isValid(x, y)) return '*';
    return ch[x][y];
  }

  void setCharAt(int x, int y, char c) {
    if (isValid(x, y)) ch[x][y] = c;
  }

  void incrementWrong() { wrong++; }
  int getWrong() const { return wrong; }
  int getSize() const { return n; }

 public:
  CGame() : ch(nullptr), n(0), wrong(0) {}

  virtual ~CGame() { releaseMemory(); }

  CGame(const CGame&) = delete;
  CGame& operator=(const CGame&) = delete;

  virtual void set(int num) {
    releaseMemory();
    n = num;
    ch = new char*[n];
    for (int i = 0; i < n; ++i) ch[i] = new char[n];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) std::cin >> ch[i][j];
  }

  virtual bool judge(const CPoint& p1, const CPoint& p2) {
    int x1 = p1.GetX(), y1 = p1.GetY();
    int x2 = p2.GetX(), y2 = p2.GetY();

    if (!isValid(x1, y1) || !isValid(x2, y2)) {
      incrementWrong();
      return false;
    }

    char c1 = getCharAt(x1, y1);
    char c2 = getCharAt(x2, y2);

    if (!(p1 == p2) && c1 != '*' && c2 != '*' && c1 == c2) {
      setCharAt(x1, y1, '*');
      setCharAt(x2, y2, '*');
      return true;
    } else {
      incrementWrong();
      return false;
    }
  }

  bool judge_win() const {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (ch[i][j] != '*') return false;
    return true;
  }

  bool isGameOverByWrong() const { return wrong >= 3; }

  static void addWin() { counter++; }

  void disp() const { std::cout << "Total Wins: " << counter << std::endl; }
};

class CStrictGame : public CGame {
 public:
  CStrictGame() : CGame() {}
  ~CStrictGame() override = default;

  void set(int num) override { CGame::set(num); }

  bool judge(const CPoint& p1, const CPoint& p2) override {
    int x1 = p1.GetX(), y1 = p1.GetY();
    int x2 = p2.GetX(), y2 = p2.GetY();

    if (!isValid(x1, y1) || !isValid(x2, y2)) {
      incrementWrong();
      return false;
    }

    char c1 = getCharAt(x1, y1);
    char c2 = getCharAt(x2, y2);
    bool sameRowOrCol = (x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2);

    if (!(p1 == p2) && c1 != '*' && c2 != '*' && c1 == c2 && sameRowOrCol) {
      setCharAt(x1, y1, '*');
      setCharAt(x2, y2, '*');
      return true;
    } else {
      incrementWrong();
      return false;
    }
  }
};

int CGame::counter = 0;

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    char type;
    int N;
    std::cin >> type >> N;

    CGame* g1 = nullptr;
    if (type == 'N')
      g1 = new CGame();
    else
      g1 = new CStrictGame();

    g1->set(N);

    int M;
    std::cin >> M;

    for (int i = 0; i < M; ++i) {
      int x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      CPoint p1(x1 - 1, y1 - 1);
      CPoint p2(x2 - 1, y2 - 1);
      g1->judge(p1, p2);

      // 错误达3次或已全部消除，提前结束操作
      if (g1->isGameOverByWrong() || g1->judge_win()) break;
    }

    if (g1->judge_win()) {
      CGame::addWin();
      std::cout << "Congratulations" << std::endl;
    } else {
      std::cout << "Game Over" << std::endl;
    }

    delete g1;
    g1 = nullptr;
  }

  CGame g2;
  g2.disp();

  return 0;
}