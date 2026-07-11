/*
 * 练习7：链表完整操作（建/遍历/插入/删除/释放）
 *
 * 补全代码，让程序输出：
 * 链表内容: 10 20 30 40
 * 插入5到头部后: 5 10 20 30 40
 * 删除20后: 5 10 30 40
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // TODO 1: 尾插法添加节点
    void append(int val) {
        // 创建新节点
        // 如果链表为空 → head = 新节点
        // 如果不为空 → 找到最后一个节点，让它指向新节点
    }

    // TODO 2: 头插法插入节点
    void prepend(int val) {
        // 创建新节点
        // 新节点的 next = head
        // head = 新节点
    }

    // TODO 3: 删除指定值的节点（假设值唯一）
    void remove(int val) {
        // 情况1：链表为空 → 直接返回
        // 情况2：删除的是头节点 → head = head->next，delete 旧头
        // 情况3：删除中间/尾部 → 找到前驱，跳过被删节点，delete
    }

    // TODO 4: 遍历打印
    void print() {
        // for (Node* p = head; p; p = p->next)
        // cout << p->data << " ";
    }

    // TODO 5: 析构函数（释放所有节点）
    ~LinkedList() {
        // 遍历每个节点，逐个 delete
    }
};

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
