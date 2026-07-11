#include <iostream>
#include <string>
using namespace std;

class Producer {
 private:
  string name;

 public:
  Producer() { cout << "Producer constructor" << endl; }
  Producer(string n) : name(n) { cout << "Producer constructor" << endl; }
  ~Producer() { cout << "Producer destructor" << endl; }

  void set(string n) { name = n; }
  void print() { cout << name; }
};

class Audio {
 private:
  string title;
  int length;

 public:
  Audio() { cout << "Audio constructor" << endl; }
  Audio(string t, int l) : title(t), length(l) {
    cout << "Audio constructor" << endl;
  }
  ~Audio() { cout << "Audio destructor" << endl; }

  void set(string t, int l) {
    title = t;
    length = l;
  }

  string getTitle() const { return title; }
  int getLength() const { return length; }
};

class Song : public Audio {
 private:
  Producer producer;
  string singer;

 public:
  Song() { cout << "Song constructor" << endl; }

  Song(string s, string t, int l, string n)
      : Audio(t, l), producer(n), singer(s) {
    cout << "Song constructor" << endl;
  }

  ~Song() { cout << "Song destructor" << endl; }

  void set(string s, string t, int l, string n) {
    singer = s;
    Audio::set(t, l);
    producer.set(n);
  }

  int GetL() const { return getLength(); }

  void print() {
    cout << singer << " " << getTitle() << " " << getLength() << " ";
    producer.print();
    cout << endl;
  }
};

int Select(Song s[], int n) {
  int index = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i].GetL() > s[index].GetL()) {
      index = i;
    }
  }
  return index;
}

int main() {
  int t;
  cin >> t;

  Song* s = new Song[t];

  for (int i = 0; i < t; ++i) {
    string singer, title, producer;
    int length;
    cin >> singer >> title >> length >> producer;
    s[i].set(singer, title, length, producer);
  }

  int x = Select(s, t);
  s[x].print();

  delete[] s;
  return 0;
}