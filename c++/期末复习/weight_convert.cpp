#include <iostream>
// 必须添加，因为使用了 string 类型
using namespace std;
class CN;  // 提前声明

class EN;  // 提前声明

class Weight {  // 抽象类

 protected:
  string kind;  // 计重类型

  int gram;  // 克

 public:
  Weight(string tk = "no name", int tg = 0)

  {
    kind = tk;

    gram = tg;
  }

  virtual void Print(ostream& out) = 0;  // 输出不同类型的计重信息
};

class CN : public Weight {  // 中国计重
  //....类定义自行编写
  /********** Write your code here! **********/
 private:
  int jin, liang, qian;

 public:
  CN(int j, int l, int q, int g, string k)
      : Weight(k, g), jin(j), liang(l), qian(q) {}
  void Convert(int w) {
    jin = w / 500;
    liang = (w % 500) / 50;
    qian = ((w % 500) % 50) / 5;
    gram = ((w % 500) % 50) % 5;
  }
  void Print(ostream& out) override {
    out << kind << ":" << jin << "斤" << liang << "两" << qian << "钱" << gram
        << "克" << endl;
  }
  /*******************************************/
};

class EN : public Weight {  // 英国计重
  //....类定义自行编写
  /********** Write your code here! **********/
 private:
  int bang, ang, da;

 public:
  EN(int b, int a, int d, int g, string k)
      : Weight(k, g), bang(b), ang(a), da(d) {}
  void Convert(int w) {
    bang = w / 512;
    ang = (w % 512) / 32;
    da = ((w % 512) % 32) / 2;
    gram = ((w % 512) % 32) % 2;
  }
  void Print(ostream& out) override {
    out << kind << ":" << bang << "磅" << ang << "盎司" << da << "打兰" << gram
        << "克" << endl;
  }
  // 类型转换运算符：英国计重 → 中国计重
  operator CN() const {
    int total = gram + bang * 512 + ang * 32 + da * 2;
    CN cn(0, 0, 0, 0, "中国计重");
    cn.Convert(total);
    return cn;
  }
  /*******************************************/
};
// 以全局函数方式重载输出运算符，代码3-5行....自行编写

// 重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用

// 重载函数必须调用参数Weight对象的Print方法
/********** Write your code here! **********/
ostream& operator<<(ostream& os, Weight& w) {
  w.Print(os);
  return os;
}
#include <string>
/*******************************************/
int main()  // 主函数

{
  int tw;

  // 创建一个中国计重类对象cn

  // 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind

  CN cn(0, 0, 0, 0, "中国计重");

  cin >> tw;

  cn.Convert(tw);  // 把输入的克数转成中国计重

  cout << cn;

  // 创建英国计重类对象en

  // 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind

  EN en(0, 0, 0, 0, "英国计重");

  cin >> tw;

  en.Convert(tw);  // 把输入的克数转成英国计重

  cout << en;

  cn = en;  // 把英国计重转成中国计重

  cout << cn;

  return 0;
}