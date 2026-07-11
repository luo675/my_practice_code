// 请补充头文件、polyitem类、友元函数split和poly类实现。注意poly类的析构函数已经实现，无需再写

/********** Write your code here! **********/
#include<iostream>
#include<string>

using namespace std;

class poly(){
    private:



    public:
        



};



/*******************************************/
//poly类的析构函数
poly::~poly()
{
    if (items)
        delete[] items;
}

// 主函数
int main()
{
    string polystr;
    int t, m;
    string op;

    cin >> t; // 输入测试次数t

    while (t--)
    {
        cin >> m; // 输入m, 表示m个多项式

        poly polyres; // 初始结果多项式，项数0

        for (auto i = 0; i < m; i++)
        {
            cin >> polystr;         // 输入多项式串
            poly polya(polystr);    // 解析polystr串构造多项式
            polya.polysort();       // 按指数降序排序
			  polya.display();        // 输出解析构造的多项式
            polyres.addpoly(polya); // polyres+=polya
        }
        polyres.display(); // 按指数降序排序输出
    }

    return 0;
}
