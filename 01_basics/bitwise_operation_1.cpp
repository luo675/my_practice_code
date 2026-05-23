#include <iostream>

using namespace std;

int main() {
  unsigned int status = 0;
  cout << status << endl;
  status |= (1 << 2);
  status |= (1 << 4);
  if (status & (1 << 4)) cout << "yes" << endl;
  cout << status << endl;
}