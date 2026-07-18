/*
 * 附加题1：学生成绩链表（链表 + 类封装）⭐ 必考方向
 *
 * 题目描述：
 * 定义 Student 结构体（学号id、姓名name、成绩score）
 * 用链表管理学生信息，实现以下功能：
 * 1. 按成绩从高到低插入（insertSorted）——插入时自动排序
 * 2. 打印所有学生信息
 * 3. 删除成绩低于60分的学生
 * 4. 析构释放所有节点
 *
 * main函数测试数据：
 * 插入(1001,"Alice",85)、(1002,"Bob",55)、(1003,"Tom",92)、(1004,"Jerry",45)
 *
 * 预期输出：
 * 所有学生:
 * 1003 Tom 92
 * 1001 Alice 85
 * 1002 Bob 55
 * 1004 Jerry 45
 * 删除不及格后:
 * 1003 Tom 92
 * 1001 Alice 85
 */
#include <iostream>
#include <string>
using namespace std;

// ========== 你的代码 ==========
struct Student {
  Student* next;
  int score;
  int id;
  string name;
  Student() : id(0), name(""), score(0), next(nullptr) {}
  Student(int i, string n, int s) : id(i), name(n), score(s), next(nullptr) {}
};

class ScoreList {
 private:
  Student* head;

 public:
  ScoreList() : head(nullptr) {}
  void insertSorted(int i, string n, int s) {
    Student* node = new Student(i, n, s);
    Student* cur = head;
    Student* pre = nullptr;

    while (cur != nullptr && cur->score > s) {
      pre = cur;
      cur = cur->next;
    }

    node->next = cur;
    if (pre == nullptr) {
      head = node;
    } else {
      pre->next = node;
    }
  }

  void print() {
    Student* cur = head;

    while (cur != nullptr) {
      cout << cur->id << " " << cur->name << " " << cur->score << endl;
      cur = cur->next;
    }
  }

  void removeFailed() {
    Student* pre = nullptr;
    Student* cur = head;

    while (cur != nullptr && cur->score >= 60) {
      pre = cur;
      cur = cur->next;
    }

    if (cur == nullptr) {
      return;
    }

    if (pre == nullptr) {
      head = nullptr;
    } else {
      pre->next = nullptr;
    }
    Student* temp;

    while (cur != nullptr) {
      temp = cur;
      cur = cur->next;
      delete temp;
    }
  }

  ~ScoreList() {
    Student* pre = nullptr;
    Student* cur = head;

    while (cur != nullptr) {
      pre = cur;
      cur = cur->next;
      delete pre;
    }
  }
};

// ========== 代码结束 ==========

int main() {
  ScoreList list;

  list.insertSorted(1001, "Alice", 85);
  list.insertSorted(1002, "Bob", 55);
  list.insertSorted(1003, "Tom", 92);
  list.insertSorted(1004, "Jerry", 45);

  cout << "所有学生:" << endl;
  list.print();

  list.removeFailed();  // 删除不及格
  cout << "删除不及格后:" << endl;
  list.print();

  return 0;
}
