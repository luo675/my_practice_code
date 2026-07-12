#include <iostream>
#include <string>

using namespace std;

class CClass {
 private:
  string id;
  string name;
  int grade;
  int credit;

 public:
  CClass(string i, string n, int g, int c)
      : id(i), name(n), grade(g), credit(c) {}
  CClass() {}
  void set() { cin >> id >> name >> credit >> grade; }
  int getg() { return grade; }
  int getc() { return credit; }
};

class Student {
 private:
  string id;
  string name;
  int age;
  string major;
  int grade;
  int type;
  int cla_n;
  int to_cre = 0;
  CClass* cla;

 public:
  Student(string i, string n, int a, string m, int g, int cn)
      : id(i), name(n), age(a), major(m), grade(g), cla_n(cn) {
    cla = new CClass[cla_n];
    type = 0;
  }
  void record() {
    for (int i = 0; i < cla_n; i++) {
      cla[i].set();
    }
  }
  Student(const Student& obj) {
    id = "2100" + obj.id;
    name = obj.name;
    age = obj.age;
    major = obj.major;
    grade = 1;
    type = 1;
    int n = 0;
    for (int i = 0; i < obj.cla_n; ++i) {
      if (obj.cla[i].getg() >= 60) {
        n++;
      }
    }
    cla_n = n;
    cla = new CClass[n];
    for (int i = 0, j = 0; i < obj.cla_n; i++) {
      if (obj.cla[i].getg() >= 60) {
        cla[j] = obj.cla[i];
        j++;
      }
    }
  }

  void dispD() {
    cout << id << " " << name << " " << age << " " << major << " ";
    if (type == 0) {
      cout << "undergraduate ";
    } else {
      cout << "postgraduate ";
    }
    cout << grade << " ";
  }
  void dispC() {
    dispD();
    cout << cla_n << " " << to_cre;
  }
  void count() {
    for (int i = 0; i < cla_n; i++) {
      if (cla[i].getg() >= 60) {
        to_cre += cla[i].getc();
      }
    }
  }

  ~Student() { delete[] cla; }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string id, name, major;
    int age, grade, n;
    cin >> id >> name >> age >> major >> grade >> n;
    Student s1(id, name, age, major, grade, n);
    s1.record();

    char ch;
    cin >> ch;
    s1.count();
    if (ch == 'C') {
      s1.dispC();
      cout << endl;
    } else {
      s1.dispD();
      cout << endl;
    }

    Student s2 = s1;
    cin >> ch;
    s2.count();
    if (ch == 'C') {
      s2.dispC();
      cout << endl;
    } else {
      s2.dispD();
      cout << endl;
    }
  }

  return 0;
}