#include <iostream>
#include <string>

using namespace std;

struct Student {
  int ID;
  string str[3];
};

int judge(Student* stu1, Student* stu2);

int min_num(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

int main() {
  int t;
  if (!(cin >> t)) return 0;
  Student* Stu = new Student[t];
  for (int i = 0; i < t; ++i) {
    cin >> Stu[i].ID >> Stu[i].str[0] >> Stu[i].str[1] >> Stu[i].str[2];
  }

  for (int i = 0; i < t; ++i) {
    for (int j = i + 1; j < t; ++j) {
      int a = judge(&Stu[i], &Stu[j]);
      if (a != 0) cout << Stu[i].ID << " " << Stu[j].ID << " " << a << endl;
    }
  }
  delete[] Stu;
  return 0;
}

int judge(Student* stu1, Student* stu2) {
  for (int k = 0; k < 3; ++k) {
    // 如果抄袭，返回k
    int a = stu1->str[k].size();
    int b = stu2->str[k].size();
    int c = min_num(a, b);
    int count = 0;
    for (int i = 0; i < c; ++i) {
      if (stu1->str[k][i] == stu2->str[k][i]) ++count;
    }
    if (count * 10 >= c * 9) return k + 1;
  }
  return 0;
}