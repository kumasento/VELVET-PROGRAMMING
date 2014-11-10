BOUND = 4000000

FIB = [0, 1, 2]

def fib(n):
    if n <= 2:
        return FIB[n]
    FIB.append(FIB[n-1] + FIB[n-2])
    return FIB[n]

n = 1
sum = 0
x = fib(1)

while x <= BOUND:
    if x % 2 == 0:
        sum += x
    n += 1
    x = fib(n)

print sum
