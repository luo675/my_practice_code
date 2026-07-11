#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Polynomial {
 private:
  map<int, long long> terms;

 public:
  Polynomial() = default;

  friend istream& operator>>(istream& in, Polynomial& p) {
    int n;
    in >> n;
    p.terms.clear();
    for (int i = 0; i < n; ++i) {
      long long coef;
      int exp;
      in >> coef >> exp;
      if (coef != 0) {
        p.terms[exp] += coef;
      }
    }

    for (auto it = p.terms.begin(); it != p.terms.end();) {
      if (it->second == 0)
        it = p.terms.erase(it);
      else
        ++it;
    }
    return in;
  }

  friend ostream& operator<<(ostream& out, const Polynomial& p) {
    if (p.terms.empty()) {
      out << "0";
      return out;
    }

    bool first = true;
    for (const auto& [exp, coef] : p.terms) {
      if (coef == 0) continue;

      if (!first) {
        if (coef > 0) out << "+";
      }

      if (exp == 0) {
        out << coef;
      } else {
        if (coef == 1) {
        } else if (coef == -1) {
          out << "-";
        } else {
          out << coef;
        }

        out << "x";
        if (exp != 1) {
          out << "^" << exp;
        }
      }

      first = false;
    }
    if (first) out << "0";

    return out;
  }

  Polynomial operator+(const Polynomial& other) const {
    Polynomial result;
    result.terms = this->terms;
    for (const auto& [exp, coef] : other.terms) {
      result.terms[exp] += coef;
    }
    result.clean();
    return result;
  }

  Polynomial operator-(const Polynomial& other) const {
    Polynomial result;
    result.terms = this->terms;
    for (const auto& [exp, coef] : other.terms) {
      result.terms[exp] -= coef;
    }
    result.clean();
    return result;
  }

  Polynomial operator*(const Polynomial& other) const {
    Polynomial result;
    for (const auto& [e1, c1] : this->terms) {
      for (const auto& [e2, c2] : other.terms) {
        result.terms[e1 + e2] += c1 * c2;
      }
    }
    result.clean();
    return result;
  }

 private:
  void clean() {
    for (auto it = terms.begin(); it != terms.end();) {
      if (it->second == 0)
        it = terms.erase(it);
      else
        ++it;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    Polynomial a, b;
    cin >> a >> b;
    cout << (a + b) << "\n";
    cout << (a - b) << "\n";
    cout << (a * b) << "\n";
  }

  return 0;
}