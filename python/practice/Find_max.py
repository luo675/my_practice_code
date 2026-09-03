nums = [13,7,29,-4,18,29,3]

max_num = nums[0]
min_num = nums[0]

for a in nums:
    if(a>max_num):
        max_num=a
    if(a<min_num):
        min_num=a

print('最大值：',max_num)
print('最小值：',min_num)
