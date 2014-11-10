import math

def is_prime(x):
    mid = math.sqrt(x)
    mid = int(mid+1)
    for i in range(2, mid+1):
        if x % i == 0:
            return False
    return True

def largest_prime_factor(x):
    mid = math.sqrt(x)
    mid = int(mid+1)
    print mid
    max = 0
    for i in range(2, mid+1):
        if x % i == 0 and is_prime(i):
            if i > max:
                max = i

    return max

print largest_prime_factor(600851475143)
