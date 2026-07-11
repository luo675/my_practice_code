#include <iostream>
#include <string>
using namespace std;

class Student {
 protected:
  string name;
  int type;
  int courses[3];
  string courseGrade;

 public:
  Student(string n, int t, int a1, int a2, int a3) {
    name = n;
    type = t;
    courses[0] = a1;
    courses[1] = a2;
    courses[2] = a3;
    courseGrade = "";
  }

  virtual void calculateGrade() = 0;

  void print() {
    string typeName;
    if (type == 1) {
      typeName = "本科生";
    } else {
      typeName = "研究生";
    }
    cout << name << "," << typeName << "," << courseGrade << endl;
  }

  virtual ~Student() {}
};

class Undergraduate : public Student {
 public:
  Undergraduate(string n, int t, int a1, int a2, int a3)
      : Student(n, t, a1, a2, a3) {}

  void calculateGrade() override {
    double avg = (courses[0] + courses[1] + courses[2]) / 3.0;
    if (avg >= 80)
      courseGrade = "优秀";
    else if (avg >= 70)
      courseGrade = "良好";
    else if (avg >= 60)
      courseGrade = "一般";
    else if (avg >= 50)
      courseGrade = "及格";
    else
      courseGrade = "不及格";
  }
};

class Postgraduate : public Student {
 public:
  Postgraduate(string n, int t, int a1, int a2, int a3)
      : Student(n, t, a1, a2, a3) {}

  void calculateGrade() override {
    double avg = (courses[0] + courses[1] + courses[2]) / 3.0;
    if (avg >= 90)
      courseGrade = "优秀";
    else if (avg >= 80)
      courseGrade = "良好";
    else if (avg >= 70)
      courseGrade = "一般";
    else if (avg >= 60)
      courseGrade = "及格";
    else
      courseGrade = "不及格";
  }
};

int main() {
  int n;
  cin >> n;

  Student** students = new Student*[n];

  for (int i = 0; i < n; i++) {
    string name;
    int type, a1, a2, a3;
    cin >> name >> type >> a1 >> a2 >> a3;

    if (type == 1) {
      students[i] = new Undergraduate(name, type, a1, a2, a3);
    } else {
      students[i] = new Postgraduate(name, type, a1, a2, a3);
    }

    students[i]->calculateGrade();
    students[i]->print();
  }

  for (int i = 0; i < n; i++) {
    delete students[i];
  }
  delete[] students;

  return 0;
}