#include <iostream>



int main() {
  int sum = 0, a = 50;
  while (a <= 100) {
    sum += a;
    a++;
  }
  std::cout << sum << std::endl;

  return 0;
}