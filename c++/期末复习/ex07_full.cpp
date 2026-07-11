/*
 * 练习7：链表 — 从零完整实现
 *
 * 题目要求：
 * 1. 定义 Node 结构体（data + next）
 * 2. 实现 LinkedList 类，包含以下成员函数：
 *    - append(val)      尾插法添加
 *    - prepend(val)     头插法插入
 *    - remove(val)      删除指定值（分情况：空表/头节点/中间）
 *    - print()          遍历输出
 *    - ~LinkedList()    析构释放所有节点
 *
 * main 函数已经写好了，你的代码加在上面
 * 预期输出：
 * 链表内容: 10 20 30 40
 * 插入5到头部后: 5 10 20 30 40
 * 删除20后: 5 10 30 40
 */
#include <iostream>
using namespace std;

// ========== 你的代码写在这里 ==========
struct Node {
  Node* next = nullptr;
  int data;
  Node(int d) : data(d), next(nullptr) {}
};
class LinkedList {
 private:
  Node* head;

 public:
  LinkedList() : head(nullptr) {}
  void append(int n) {
    Node* newnode = new Node(n);

    if (head == nullptr) {
      head = newnode;
      return;
    }

    Node* p = head;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = newnode;
  }
  void print() {
    Node* p = head;
    while (p != nullptr) {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }
  void prepend(int n) {
    Node* p = new Node(n);
    p->next = head;
    head = p;
  }
  void remove(int n) {
    if (head == nullptr) return;
    if (head->data = n) {
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node* p = head;
    while (p->next != nullptr && p->next->data != n) {
      p = p->next;
    }
    if (p->next != nullptr) {
      Node* q = p->next;
      p->next = q->next;
      delete q;
    }
  }
  ~LinkedList() {
    Node* p = head;
    while (p != nullptr) {
      Node* next = p->next;
      delete p;
      p = next;
    }
  }
};

// ========== 你的代码结束 ==========

int main() {
  LinkedList list;

  list.append(10);
  list.append(20);
  list.append(30);
  list.append(40);
  cout << "链表内容: ";
  list.print();

  list.prepend(5);
  cout << "插入5到头部后: ";
  list.print();

  list.remove(20);
  cout << "删除20后: ";
  list.print();

  return 0;
}
