import numpy as np

rewards=np.array([
    [1,-1,0,2,-1],
    [0,1,-1,0,1],
    [2,0,-1,1,0]
])

print(rewards.sum(axis=1))

print(rewards.mean(axis=0))

gamma=0.9

discounts=gamma**np.arange(5)

result=rewards*discounts

print(result)