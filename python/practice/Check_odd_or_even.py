a=input()

a=int(a)

if a==0:
    print('zero')

elif a>0:
    if a%2==1:
        print('positive odd')
    else:
        print('positive even')
else:
    a=-a
    if a%2==1:
        print('negative odd')
    else:
        print('negative even')
