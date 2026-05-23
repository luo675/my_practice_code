#include <iostream>
#include <string>

using namespace std;

class Student {
 private:
  string name;
  int score;

 public:
  Student() {
    name = "a";
    score = 0;
  }
  Student(string na, int s) : name(na), score(s) {}
  void getName(string n) { name = n; }
  void getScore(int s) { score = s; }

  void output() { cout << name << " " << score << endl; }

  friend Student compareScore(Student& s1, Student& s2);
};

Student compareScore(Student& s1, Student& s2) {
  if (s1.score < s2.score)
    return s2;
  else
    return s1;
}

int main() {
  int N, M;
  cin >> N;
  while (N--) {
    cin >> M;
    Student* s = new Student[M];
    for (int i = 0; i < M; ++i) {
      string na;
      int sc;
      cin >> na >> sc;
      s[i].getName(na);
      s[i].getScore(sc);
    }

    Student temp;
    for (int i = 0; i < M; ++i) {
      temp = compareScore(temp, s[i]);
    }

    temp.output();

    delete[] s;
  }

  return 0;
}