import numpy as np

rewards=[1,-1,0,2,-1,3,0,1]

discounted=[]

for i,r in enumerate(rewards):
    discounted.append(r*(0.99**i))

print(discounted)

rewards=np.array([1,-1,0,2,-1,3,0,1])

discounts=0.99**np.arange(len(rewards))
discounted=rewards*discounts

print(discounted)