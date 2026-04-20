#include <iostream>

using namespace std;

class Tree {
 public:
  Tree();
  Tree(int age);
  void grow(int years);
  void age();

 private:
  int ages;
};

Tree::Tree() { ages = 1; }

Tree::Tree(int age) { ages = age; }

void Tree::grow(int years) { ages += years; }

void Tree::age() { cout << ages << endl; }

int main() {
  Tree t1;
  int a;
  cin >> a;
  t1.grow(a);
  t1.age();
  int b;
  cin >> b;
  Tree t2(b);
  int c;
  cin >> c;
  t2.grow(c);
  t2.age();

  return 0;
}