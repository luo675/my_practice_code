#include <iostream>
#include <string>

using namespace std;

class Teacher {
 protected:
  string n, s, add, pho, t;
  int a;

 public:
  Teacher(string n, string s, string add, string pho, string t, int a)
      : n(n), s(s), add(add), pho(pho), t(t), a(a) {}
  void display();
};

class Cadre {
 protected:
  string n, s, add, pho, p;
  int a;

 public:
  Cadre(string n, string s, string add, string pho, string p, int a)
      : n(n), s(s), add(add), pho(pho), p(p), a(a) {}
};

class Teacher_Cadre : public Teacher, public Cadre {
 protected:
  double wages;

 public:
  Teacher_Cadre(string n, string s, string add, string pho, string t, int a,
                string p, double w)
      : Teacher(n, s, add, pho, t, a), Cadre(n, s, add, pho, p, a), wages(w) {}
  void show();
};

void Teacher::display() {
  cout << "name:" << n << endl;
  cout << "age:" << a << endl;
  cout << "sex:" << s << endl;
  cout << "title:" << t << endl;
  cout << "address:" << add << endl;
  cout << "tel:" << pho << endl;
}

void Teacher_Cadre::show() {
  Teacher::display();
  cout << "post:" << p << endl;
  cout << "wages:" << wages;
}

int main() {
  string n, s, t, p, add, pho;
  int a;
  double w;
  cin >> n >> a >> s >> t >> p;
  cin.ignore();
  getline(cin, add);
  cin >> pho >> w;

  Teacher_Cadre p1(n, s, add, pho, t, a, p, w);
  p1.show();

  return 0;
}