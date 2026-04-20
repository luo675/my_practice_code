#include <iomanip>
#include <iostream>

int main() {
  float F;
  std::cin >> F;
  float C;
  C = 5.0 / 9.0 * (F - 32);
  std::cout << std::fixed << std::setprecision(1) << C << std::endl;

  return 0;
}