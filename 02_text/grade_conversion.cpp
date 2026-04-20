#include <iostream>
#include <string>

using namespace std;

int main() {
  string str[] = {"F", "F", "F", "F", "F", "F", "D", "C", "B", "A"};
  int grade;
  cin >> grade;
  if (grade < 0 || grade > 100)
    cout << "error" << endl;
  else {
    grade = grade / 10;
    cout << str[grade] << endl;
  }
  return 0;
}