import torch
import numpy as np

x=torch.tensor([3.0],requires_grad=True)
y=x**2

y.backward()

print(x.grad)