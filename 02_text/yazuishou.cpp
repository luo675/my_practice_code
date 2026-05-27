#include <iostream>
#include <string>

using namespace std;

class Animal {
 protected:
  int age;

 public:
  Animal() {}
  Animal(int a) : age(a) { cout << "Animal constructed." << endl; }
  void virtual display() { cout << "Animal age: " << age << endl; }
};

class Bird : virtual public Animal {
 protected:
  float wing;

 public:
  Bird(int a, float w) : Animal(a), wing(w) {
    cout << "Bird constructed." << endl;
  }
  void virtual display() { cout << "Wingspan: " << wing << "m" << endl; }
};

class Mammal : virtual public Animal {
 protected:
  double weight;

 public:
  Mammal(int a, double wt) : Animal(a), weight(wt) {
    cout << "Mammal constructed." << endl;
  }
  void virtual display() { cout << "Weight: " << weight << "kg" << endl; }
};

class Platypus : public Bird, public Mammal {
 public:
  Platypus(int a, float w, double wt) : Animal(a), Bird(a, w), Mammal(a, wt) {
    cout << "Platypus constructed." << endl;
  }
  void display() {
    Animal::display();
    Bird::display();
    Mammal::display();
  }
};

int main() {
  int age;
  float wing;
  double weight;
  cin >> age >> wing >> weight;

  Platypus p1(age, wing, weight);
  p1.display();

  return 0;
}