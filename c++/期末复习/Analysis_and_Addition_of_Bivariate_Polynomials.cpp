#include <iostream>
using namespace std;

class polyitem {
 private:
  int coeff;  // 系数
  int xexp;   // x指数
  int yexp;   // y指数

 public:
  // 构造函数
  polyitem(int c = 0, int x = 0, int y = 0) {
    coeff = c;
    xexp = x;
    yexp = y;
  }

  friend polyitem split(char item[], int len);
  friend class poly;
};

// 解析单项式的函数
polyitem split(char item[], int len) {
  int i = 0;
  int sign = 1;  // 符号，1表示正，-1表示负

  // 处理开头的符号
  if (i < len && item[i] == '+') {
    sign = 1;
    i++;
  } else if (i < len && item[i] == '-') {
    sign = -1;
    i++;
  }

  // 解析系数
  int coeff = 0;
  bool has_coeff = false;
  while (i < len && item[i] >= '0' && item[i] <= '9') {
    has_coeff = true;
    coeff = coeff * 10 + (item[i] - '0');
    i++;
  }

  if (!has_coeff) {
    coeff = 1;  // 没有数字就是1
  }
  coeff *= sign;  // 乘上符号

  // 解析x部分
  int xexp = 0;
  if (i < len && item[i] == 'x') {
    xexp = 1;  // 默认指数是1
    i++;
    if (i < len && item[i] == '^') {
      i++;
      xexp = 0;
      while (i < len && item[i] >= '0' && item[i] <= '9') {
        xexp = xexp * 10 + (item[i] - '0');
        i++;
      }
    }
  }

  // 解析y部分
  int yexp = 0;
  if (i < len && item[i] == 'y') {
    yexp = 1;  // 默认指数是1
    i++;
    if (i < len && item[i] == '^') {
      i++;
      yexp = 0;
      while (i < len && item[i] >= '0' && item[i] <= '9') {
        yexp = yexp * 10 + (item[i] - '0');
        i++;
      }
    }
  }

  return polyitem(coeff, xexp, yexp);
}

class poly {
 private:
  polyitem* items;
  int n;

 public:
  poly(string polystr);
  ~poly();
  void polysort();
  void addpoly(const poly rhs);
  void display();
  friend class polyitem;
};

// 构造函数：解析多项式字符串
poly::poly(string polystr) {
  // 先数有多少个单项式
  n = 0;
  int len = polystr.length();
  char* temp = new char[len + 2];  // 临时存储字符串

  // 复制到temp数组
  for (int i = 0; i < len; i++) {
    temp[i] = polystr[i];
  }
  temp[len] = '\0';

  // 如果第一个字符不是+或-，在前面加+
  if (len > 0 && temp[0] != '+' && temp[0] != '-') {
    // 移动字符
    for (int i = len; i >= 0; i--) {
      temp[i + 1] = temp[i];
    }
    temp[0] = '+';
    len++;
  }

  // 数单项式个数
  for (int i = 0; i < len; i++) {
    if (temp[i] == '+' || temp[i] == '-') {
      if (i == 0 || (temp[i - 1] != '^')) {
        n++;
      }
    }
  }

  // 分配空间
  items = new polyitem[n];

  // 解析每个单项式
  int item_index = 0;
  int start = 0;
  for (int i = 0; i <= len; i++) {
    if ((temp[i] == '+' || temp[i] == '-' || i == len) && i > 0) {
      if (temp[i - 1] != '^') {  // 确保不是指数部分的符号
        // 提取单项式
        int item_len = i - start;
        char* single_item = new char[item_len + 1];
        for (int j = 0; j < item_len; j++) {
          single_item[j] = temp[start + j];
        }
        single_item[item_len] = '\0';

        // 跳过空项
        if (item_len > 1 || (item_len == 1 && single_item[0] != '+')) {
          items[item_index] = split(single_item, item_len);
          item_index++;
        }

        delete[] single_item;
        start = i;
      }
    }
  }
  n = item_index;  // 更新实际项数

  delete[] temp;
}

// 析构函数
poly::~poly() {
  if (items) {
    delete[] items;
  }
}

// 排序：按x降幂，x相同按y降幂
void poly::polysort() {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (items[j].xexp < items[j + 1].xexp ||
          (items[j].xexp == items[j + 1].xexp &&
           items[j].yexp < items[j + 1].yexp)) {
        // 交换两个单项式
        polyitem temp = items[j];
        items[j] = items[j + 1];
        items[j + 1] = temp;
      }
    }
  }
}

// 多项式加法
void poly::addpoly(const poly rhs) {
  // 创建临时数组存储结果
  polyitem* temp_items = new polyitem[n + rhs.n];
  int temp_n = 0;

  // 复制当前多项式的所有项
  for (int i = 0; i < n; i++) {
    temp_items[temp_n] = items[i];
    temp_n++;
  }

  // 添加rhs的每一项
  for (int i = 0; i < rhs.n; i++) {
    bool found = false;
    for (int j = 0; j < temp_n; j++) {
      if (temp_items[j].xexp == rhs.items[i].xexp &&
          temp_items[j].yexp == rhs.items[i].yexp) {
        // 同类项合并
        temp_items[j].coeff += rhs.items[i].coeff;
        found = true;
        break;
      }
    }
    if (!found) {
      // 新项
      temp_items[temp_n] = rhs.items[i];
      temp_n++;
    }
  }

  // 删除系数为0的项
  int new_n = 0;
  for (int i = 0; i < temp_n; i++) {
    if (temp_items[i].coeff != 0) {
      new_n++;
    }
  }

  // 创建最终结果数组
  polyitem* final_items = new polyitem[new_n];
  int index = 0;
  for (int i = 0; i < temp_n; i++) {
    if (temp_items[i].coeff != 0) {
      final_items[index] = temp_items[i];
      index++;
    }
  }

  // 替换原数组
  delete[] items;
  items = final_items;
  n = new_n;

  // 排序
  polysort();

  delete[] temp_items;
}

// 显示多项式
void poly::display() {
  if (n == 0) {
    cout << "0" << endl;
    return;
  }

  bool first_term = true;
  bool all_zero = true;

  for (int i = 0; i < n; i++) {
    if (items[i].coeff == 0) continue;

    all_zero = false;

    // 输出符号
    if (first_term) {
      if (items[i].coeff < 0) {
        cout << "-";
      }
      first_term = false;
    } else {
      if (items[i].coeff > 0) {
        cout << "+";
      } else {
        cout << "-";
      }
    }

    // 输出系数（绝对值）
    int abs_coeff = (items[i].coeff > 0) ? items[i].coeff : -items[i].coeff;
    if (abs_coeff != 1 || (items[i].xexp == 0 && items[i].yexp == 0)) {
      cout << abs_coeff;
    }

    // 输出x部分
    if (items[i].xexp > 0) {
      cout << "x";
      if (items[i].xexp > 1) {
        cout << "^" << items[i].xexp;
      }
    }

    // 输出y部分
    if (items[i].yexp > 0) {
      cout << "y";
      if (items[i].yexp > 1) {
        cout << "^" << items[i].yexp;
      }
    }
  }

  if (all_zero) {
    cout << "0";
  }
  cout << endl;
}