#include <iostream>

using namespace std;

struct Node {
  Node* next = NULL;
  int coef;
  int exp;
};

void print(Node* head) {
  Node* p = head->next;

  bool first = true;

  while (p != NULL) {
    if (p->coef > 0) {
      if (!first) {
        cout << " + ";
      }

      if (p->exp == 0) {
        cout << p->coef;
      } else if (p->exp < 0) {
        cout << p->coef << "x^(" << p->exp << ")";
      } else {
        cout << p->coef << "x^" << p->exp;
      }

      p = p->next;

      first = false;

      continue;
    }

    else if (p->coef < 0) {
      if (!first) {
        cout << " + ";
      }

      cout << "(";
      if (p->exp == 0) {
        cout << p->coef << ")";
      } else if (p->exp < 0) {
        cout << p->coef << ")" << "x^(" << p->exp << ")";
      } else {
        cout << p->coef << ")" << "x^" << p->exp;
      }

      p = p->next;

      first = false;

      continue;
    }

    p = p->next;
  }

  cout << endl;
}

void addition(Node* head1, Node* head2, Node* head3) {
  Node *p1, *p2, *p3, *p4;
  p1 = head1->next;
  p2 = head2->next;
  p3 = head3;

  while (p1 != NULL && p2 != NULL) {
    if (p1->exp > p2->exp) {
      p4 = new Node;
      p4->exp = p2->exp;
      p4->coef = p2->coef;
      p3->next = p4;
      p3 = p4;
      p2 = p2->next;
    }

    else if (p1->exp < p2->exp) {
      p4 = new Node;
      p4->exp = p1->exp;
      p4->coef = p1->coef;
      p3->next = p4;
      p3 = p4;
      p1 = p1->next;
    }

    else {
      p4 = new Node;
      p4->coef = p1->coef + p2->coef;
      p4->exp = p1->exp;
      p3->next = p4;
      p3 = p4;
      p1 = p1->next;
      p2 = p2->next;
    }
  }

  while (p1 != NULL) {
    p4 = new Node;
    p4->coef = p1->coef;
    p4->exp = p1->exp;

    p3->next = p4;
    p3 = p4;

    p1 = p1->next;
  }

  while (p2 != NULL) {
    p4 = new Node;
    p4->coef = p2->coef;
    p4->exp = p2->exp;

    p3->next = p4;
    p3 = p4;

    p2 = p2->next;
  }
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, m;
    cin >> n;
    Node* head1 = new Node;
    Node* head2 = new Node;
    Node* head3 = new Node;

    Node *p1, *p2 = head1;

    while (n--) {
      int coef, exp;
      cin >> coef >> exp;
      p1 = new Node;
      p1->coef = coef;
      p1->exp = exp;
      p2->next = p1;
      p2 = p1;
    }
    print(head1);

    cin >> m;
    p2 = head2;
    while (m--) {
      int coef, exp;
      cin >> coef >> exp;
      p1 = new Node;
      p1->coef = coef;
      p1->exp = exp;
      p2->next = p1;
      p2 = p1;
    }
    print(head2);

    addition(head1, head2, head3);

    print(head3);

    p1 = head1;
    while (p1 != NULL) {
      p2 = p1->next;
      delete p1;
      p1 = p2;
    }

    p1 = head2;
    while (p1 != NULL) {
      p2 = p1->next;
      delete p1;
      p1 = p2;
    }

    p1 = head3;
    while (p1 != NULL) {
      p2 = p1->next;
      delete p1;
      p1 = p2;
    }
  }

  cout << endl;

  return 0;
}