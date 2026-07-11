#include <iostream>

using namespace std;

struct link {
  int num;
  link* next;
};

int main() {
  link* head = new link();
  head->next = NULL;
  int L = 0;
  int t;
  cin >> t;

  while (t--) {
    int i, e;
    cin >> i >> e;
    if (i < 1 || i > L + 1) {
      cout << "error" << endl;
      continue;
    }
    link* p = head;
    for (int j = 0; j < i - 1; ++j) {
      p = p->next;
    }

    link* s = new link();
    s->num = e;
    s->next = p->next;
    p->next = s;

    ++L;

    link* temp = head->next;
    while (temp != NULL) {
      cout << temp->num;
      if (temp->next) cout << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  return 0;
}