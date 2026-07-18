import numpy as np

rewards=np.array([1.0,-1.0,0.5,2.0])

discount=0.99

discounted=rewards*discount

advantages=np.array([1.0,2.0,3.0])
mask=np.array([[1],[2],[3]])

result=advantages+mask
print(rewards)
print(discounted)
print(advantages)
print(mask)
print(result)