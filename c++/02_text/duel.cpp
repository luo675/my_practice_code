#include <iostream>
#include <string>

using namespace std;

class Node2D {
 protected:
  string place;

 public:
  Node2D() {}
  Node2D(string p) : place(p) {}
};

class Body : virtual public Node2D {
 protected:
  int health, defense;

 public:
  Body(int h, int d) : health(h), defense(d) {}
};

class Weapon : virtual public Node2D {
 protected:
  string w_name;
  int damage;

 public:
  Weapon(string n, int d) : w_name(n), damage(d) {}
};

class Player : public Body, public Weapon {
 protected:
  string name;

 public:
  Player(string p, int h, int d, string wn, int da, string na)
      : Node2D(p), Body(h, d), Weapon(wn, da), name(na) {}
  void display() {
    cout << name << " still have " << health << " health" << endl;
  }
  void win(Player p) {
    cout << name << " defeated " << p.name << " by " << w_name << " in "
         << place << endl;
  }
  bool attack(Player& p) {
    int realDamage = damage - p.defense;
    cout << name << " deal " << realDamage << " damage to " << p.name << endl;
    p.health -= realDamage;
    if (p.health <= 0) {
      return true;
    } else {
      cout << p.name << " still have " << p.health << " health" << endl;
      cout << endl;
      return false;
    }
  }
  void sub(int a) { health -= a; }
  int gethea() { return health; }
};

int main() {
  string place, name[2], weapon[2];
  int life[2], defend[2], harm[2];
  cin >> place;
  for (int i = 0; i < 2; ++i) {
    cin >> name[i] >> life[i] >> defend[i] >> weapon[i] >> harm[i];
  }
  Player p[2] = {
      Player(place, life[0], defend[0], weapon[0], harm[0], name[0]),
      Player(place, life[1], defend[1], weapon[1], harm[1], name[1])};
  int x1 = 0;
  int x2 = 1;
  while (!p[x1].attack(p[x2])) {
    int temp = x1;
    x1 = x2;
    x2 = temp;
  }
  p[x1].win(p[x2]);

  return 0;
}