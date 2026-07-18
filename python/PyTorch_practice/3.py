import torch
import numpy as np
import torch.nn as nn

X=torch.randn(100,1)
y_true=3*X+2+0.1*torch.randn(100,1)

model=nn.Linear(1,1)

optimizer=torch.optim.SGD(model.parameters(),lr=0.01)

for step in range(200):
    y_pred=model(X)
    loss=((y_pred-y_true)**2).mean()
    loss.backward()
    optimizer.step()
    optimizer.zero_grad()


print(list(model.parameters()))

    