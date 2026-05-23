#include <iostream>
#include <stack>
using namespace std;

int n, ans = 0;

// next_in: 下一个要入栈的数字
// out_count: 已经输出的数字个数
// stk: 当前栈的状态
void dfs(int next_in, int out_count, stack<int> stk) {
  // 所有数字都已输出，找到一种方案
  if (out_count == n) {
    ans++;
    return;
  }

  // 操作1：将下一个数压入栈（如果还有数可以入栈）
  if (next_in <= n) {
    stk.push(next_in);
    dfs(next_in + 1, out_count, stk);
    stk.pop();
  }

  // 操作2：将栈顶弹出到输出序列（如果栈非空）
  if (!stk.empty()) {
    int top = stk.top();
    stk.pop();
    dfs(next_in, out_count + 1, stk);
    stk.push(top);
  }
}

int main() {
  cin >> n;
  stack<int> stk;
  dfs(1, 0, stk);
  cout << ans << endl;
  return 0;
}

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  long long dp[19] = {0};
  dp[0] = 1;  // 空序列只有1种
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int k = 1; k <= i; k++) {
      dp[i] += dp[k - 1] * dp[i - k];
    }
  }

  cout << dp[n] << endl;
  return 0;
}