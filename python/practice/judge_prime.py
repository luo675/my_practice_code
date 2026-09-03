def is_prime(n):
    for a in range(2,n):
        if n%a==0:
            return False
    return True







for num in range(2,101):
    if is_prime(num):
        print(num,'是质数')
