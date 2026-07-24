import torch

# —— 造假数据（跟昨天一样）——
X = torch.randn(100, 1)
y_true = 3 * X + 2 + 0.1 * torch.randn(100, 1)

# —— 手写参数（替代 nn.Linear）——
# nn.Linear 里就这两行：
w = torch.randn(1, 1, requires_grad=True)   # 随机初始斜率
b = torch.randn(1, requires_grad=True)       # 随机初始截距

# —— 训练（跟昨天一模一样的 5 步循环）——
for step in range(200):
    y_pred = X @ w + b                       # ① 猜：矩阵乘 + 加截距
    loss = ((y_pred - y_true) ** 2).mean()   # ② 算误差
    loss.backward()                          # ③ 算梯度
    with torch.no_grad():                    # ④ 手动更新（关掉梯度记录）
        w -= 0.01 * w.grad
        b -= 0.01 * b.grad
    w.grad.zero_()                           # ⑤ 清空账本
    b.grad.zero_()

print(f"w = {w.item():.3f}, b = {b.item():.3f}")
# 应该输出：w ≈ 3.000, b ≈ 2.000
