import torch
import numpy as np

a=np.array([1.0,2.0,3.0])

b=torch.tensor([1.0,2.0,3.0])

a1=a*3
a2=a@a
a3=a.sum()

b1=b*3
b2=b@b
b3=b.sum()

print(a)
print(a1)
print(a2)
print(a3)

print(b)
print(b1)
print(b2)
print(b3)