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
  int id;
  string name;
  int score;
  Student* next;
  Student() : id(0), name(""), score(0), next(nullptr) {}
  Student(int i, string n, int s) : id(i), name(n), score(s), next(nullptr) {}
};

class ScoreList {
 private:
  Student* stu;

 public:
  ScoreList() : stu(nullptr) {}
  void insertSorted(int i, string n, int s) {
    Student* node = new Student(i, n, s);
    Student* cur = stu;
    Student* pre = nullptr;

    if (cur == nullptr) {
      stu = node;
      return;
    }

    while (cur != nullptr && cur->score > s) {
      pre = cur;
      cur = cur->next;
    }

    if (pre == nullptr) {
      node->next = stu;
      stu = node;
    } else {
      pre->next = node;
      node->next = cur;
    }
  }

  void print() {
    Student* p = stu;
    while (p) {
      cout << p->id << " " << p->name << " " << p->score << endl;
      p = p->next;
    }
  }

  void removeFailed() {
    Student* p1 = stu;
    Student* p2 = nullptr;

    while (p1) {
      if (p1->score < 60) {
        if (p2 == nullptr) {
          stu = p1->next;
          delete p1;
          p1 = stu;
        } else {
          p2->next = p1->next;
          delete p1;
          p1 = p2->next;
        }
      } else {
        p2 = p1;
        p1 = p1->next;
      }
    }
  }

  ~ScoreList() {
    Student* p1 = stu;
    while (p1) {
      Student* temp = p1;
      p1 = p1->next;
      delete temp;
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
