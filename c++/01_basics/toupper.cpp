#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#ifdef _WIN32
#include <windows.h>  // Windows 系统特有头文件
#endif
using namespace std;

// 1. 【const 引用】：只读模式
// 场景：当你只需要“查看”数据，不想（也不该）修改原件时。
// 优点：省去了拷贝大对象的开销，同时保证了数据的安全。
void printStrings(const vector<string>& vec) {
  cout << "now:";
  for (const auto& s : vec) {  // 这里也是 const 引用，避免拷贝每个字符串
    cout << "[" << s << "] ";
  }
  cout << endl;
  // vec.push_back("error"); // 如果取消注释，编译器会报错，因为它是 const
}

// 2. 【非 const 引用】：编辑模式
// 场景：当你确实需要“加工”原件，让函数的操作结果直接反映在外部时。
void convertToUppercase(vector<string>& vec) {
  for (auto& s : vec) {  // 必须是非 const 引用，因为我们要改写它
    for (char& c : s) {  // 同样，引用字符串里的每个字符
      c = toupper(c);    // 转大写
    }
  }
}

int main() {
  // 【老兵绝招 1】解决 Windows 控制台乱码
#ifdef _WIN32
  SetConsoleOutputCP(65001);  // 强制控制台使用 UTF-8 编码
#endif

  vector<string> myWords = {"hello", "c++", "primer", "szu"};

  cout << "--- 修改前 ---" << endl;
  printStrings(myWords);

  cout << "\n正在转换为大写..." << endl;
  convertToUppercase(myWords);

  cout << "--- 修改后 ---" << endl;
  printStrings(myWords);

  // 【老兵绝招 2】防止程序跑完直接关掉窗口（虽然 VS Code
  // 终端通常不会，但这是好习惯）
  cout << "\n程序运行结束，按回车退出..." << endl;
  cin.get();

  return 0;
}